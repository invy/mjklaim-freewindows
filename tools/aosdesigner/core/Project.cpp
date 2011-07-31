#include "core/Project.hpp"

#include <algorithm>

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/algorithm/string.hpp>

#include "util/Assert.hpp"

#include "core/ProjectInfos.hpp"
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
		AOSD_ASSERT( is_valid(infos), "Tried to construct a Project with invalid project infos!" );
	}

	Project::Project( const bfs::path& project_file_path )
		: m_location( project_file_path )
		, m_directory_path( project_file_path.parent_path() )
	{
		AOSD_ASSERT( !project_file_path.empty(), "Tried to construct a Project at an empty path!" );
		AOSD_ASSERT( bfs::is_regular_file( m_location ), "Tried to create a project with an invalid file path! Path : " << m_location )
		AOSD_ASSERT( bfs::is_directory( m_directory_path ), "Wow, what's wrong with that project's directory? Path : " << m_directory_path )

		// THINK : make it  a throwing test?
		AOSD_ASSERT( boost::filesystem::exists( project_file_path ), "Tried to construct a Project with a path that don't exist!" ); 

		// THINK : move that in a separate function?
		using namespace boost::property_tree;
		
		bfs::ifstream filestream( project_file_path );

		ptree infos;
		read_xml( filestream, infos );

		m_name = infos.get<std::string>( "project.name" );

	}


	void Project::relocate( const bfs::path& new_filepath )
	{
		// TODO : add some checks!
		m_location = new_filepath;
		m_directory_path = m_location.parent_path();

		AOSD_ASSERT( bfs::is_regular_file( m_location ), "Tried to create a project with an invalid file path! Path : " << m_location )
		AOSD_ASSERT( bfs::is_directory( m_directory_path ), "Wow, what's wrong with that project's directory? Path : " << m_directory_path )

	}

	void Project::rename( const std::string& new_name )
	{
		// TODO : add some checks!
		m_name = new_name;
	}

	bool Project::save()
	{
		using namespace boost::property_tree;

		// fill it with properties that needs to be saved
		ptree infos;

		infos.put( "project.name", name() );

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
			AOSD_NOT_IMPLEMENTED_YET;
			return false;
		}

		return true;
	}

	void Project::foreach_sequence( const SequenceModifierFunc& func )
	{
		std::for_each( m_sequences.begin(), m_sequences.end(), func );
	}

	void Project::foreach_sequence( const SequenceReaderFunc& func ) const
	{
		std::for_each( m_sequences.begin(), m_sequences.end(), func );
	}

	bool Project::new_sequence( const SequenceInfos& infos )
	{
		m_sequences.push_back( new Sequence( *this, infos ) );
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


}
}