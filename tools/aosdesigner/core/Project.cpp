#include "core/Project.hpp"

#include <algorithm>

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/algorithm/string.hpp>

#include "utilcpp/Assert.hpp"

#include "core/ProjectInfos.hpp"
#include "core/SequenceInfos.hpp"
#include "core/Sequence.hpp"
#include "core/StoryWalker.hpp"
#include "view/Dialogs.hpp"
#include "Paths.hpp"

namespace aosd
{
namespace core
{

	Project::Project( const ProjectInfos& infos )
		: m_location( infos.location )
		, m_name( infos.name )
		, m_directory_path( infos.location.parent_path() )
	{
		UTILCPP_ASSERT( is_valid(infos), "Tried to construct a Project with invalid project infos!" );
	}

	Project::Project( const bfs::path& project_file_path )
		: m_location( project_file_path )
		, m_directory_path( project_file_path.parent_path() )
	{
		UTILCPP_ASSERT( !project_file_path.empty(), "Tried to construct a Project at an empty path!" );
		UTILCPP_ASSERT( bfs::is_regular_file( m_location ), "Tried to create a project with an invalid file path! Path : " << m_location )
		UTILCPP_ASSERT( bfs::is_directory( m_directory_path ), "Wow, what's wrong with that project's directory? Path : " << m_directory_path )

		// THINK : make it  a throwing test?
		UTILCPP_ASSERT( boost::filesystem::exists( project_file_path ), "Tried to construct a Project with a path that don't exist!" ); 

		// THINK : move that in a separate function?
		using namespace boost::property_tree;
		
		bfs::ifstream filestream( project_file_path );

		ptree infos;
		read_xml( filestream, infos );

		m_name = infos.get<std::string>( "project.name" );
		auto sequences = infos.get_child( "project.sequences" );
		std::for_each( sequences.begin(), sequences.end(), [&]( const std::pair< std::string, ptree >& sequence_info )
		{
			UTILCPP_ASSERT( sequence_info.first == "sequence", "Found an unknown tag! Should be \"sequence\" instead of \"" << sequence_info.first << "\"" );

			const bfs::path sequence_location = sequence_info.second.get_value<std::string>();
			add_sequence( std::unique_ptr<Sequence>( new Sequence( *this, sequence_location ) ) );
			
			UTILCPP_LOG << "Loaded Sequence : " << m_sequences.back().name() << " [" << m_sequences.back().id() << "]";

		});

	}


	Project::~Project()
	{

	}


	void Project::relocate( const bfs::path& new_filepath )
	{
		// TODO : add some checks!
		// TODO : move the files in the new location?
		m_location = new_filepath;
		m_directory_path = m_location.parent_path();

		UTILCPP_ASSERT( bfs::is_regular_file( m_location ), "Tried to create a project with an invalid file path! Path : " << m_location )
		UTILCPP_ASSERT( bfs::is_directory( m_directory_path ), "Wow, what's wrong with that project's directory? Path : " << m_directory_path )

	}

	void Project::rename( const std::string& new_name )
	{
		if( new_name.empty()  )
		{
			UTILCPP_LOG_ERROR << "Tried to rename project " << m_name << " to \"" << new_name << "\" : invalid!";
			return;
		}

		m_name = new_name;
	}

	bool Project::save()
	{
		using namespace boost::property_tree;

		// fill it with properties that needs to be saved
		ptree infos;

		infos.put( "project.name", name() );

		foreach_sequence( [&]( const Sequence& sequence )
		{ 
			infos.add( "project.sequences.sequence", sequence.location().generic_string() );
		});

		// TODO : add other informations here
		// TODO : manage errors differently

		try
		{
			namespace bfs = boost::filesystem;
			const auto directory_path = m_location.parent_path();

			// make sure the directory is available
			if( !bfs::is_directory( directory_path ) )
			{
				bfs::create_directories( directory_path );
			}
			
			bfs::ofstream filestream( m_location );
			write_xml( filestream, infos );
		}
		catch( const boost::exception& e )
		{
			// TODO : add logging here
			UTILCPP_NOT_IMPLEMENTED_YET;
			return false;
		}

		foreach_sequence( []( Sequence& sequence ){ sequence.save(); });

		return true;
	}

	void Project::foreach_sequence( SequenceModifierFunc func )
	{
		std::for_each( m_sequences.begin(), m_sequences.end(), func );
	}

	void Project::foreach_sequence( SequenceReaderFunc func ) const
	{
		std::for_each( m_sequences.begin(), m_sequences.end(), func );
	}

	bool Project::new_sequence( const SequenceInfos& infos )
	{
		auto sequence = new Sequence( *this, infos );
		
		add_sequence( std::unique_ptr<Sequence>( sequence ) );
		emit sequence_created( *sequence );

		// create a new storywalker for this sequence
		new_storywalker( sequence->id() );

		return true;
	}

	bool Project::new_sequence()
	{
		// request the new sequence infos
		const SequenceInfos infos = view::request_new_sequence_infos();

		// create and register the sequence
		if( is_valid( infos ) ) 
			return new_sequence( infos );
		else 
			return false;

	}

	bool Project::new_storywalker( const SequenceId& sequence_id )
	{
		Sequence* sequence = find_sequence( sequence_id );
		
		if( sequence )
		{
			auto interpreter = sequence->make_interpreter();
			if( interpreter )
			{
				auto storywalker = new StoryWalker( *interpreter );
				add_storywalker( std::unique_ptr< StoryWalker >( storywalker ) );
				
				emit storywalk_begin( *storywalker ); 
				return true;
			}
		}

		return false;
	}


	void Project::add_sequence( std::unique_ptr<Sequence>&& sequence )
	{
		UTILCPP_ASSERT_NOT_NULL( sequence );
		m_sequences.push_back( sequence.release() );
	}


	void Project::add_storywalker( std::unique_ptr<StoryWalker>&& storywalker )
	{
		UTILCPP_ASSERT_NOT_NULL( storywalker );
		m_walks.push_back( storywalker.release() );
		

	}

	Sequence* Project::find_sequence( const SequenceId& sequence_id )
	{
		if( m_sequences.empty() )
			return nullptr;

		auto find_it = std::find_if( m_sequences.begin(), m_sequences.end(), [&]( Sequence& sequence ){ return sequence.id() == sequence_id; } );

		if( find_it != m_sequences.end() )
			return &(*find_it);
		else
			return nullptr;
	}





}
}