#include "core/Project.hpp"

#include <algorithm>

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/exception/diagnostic_information.hpp>

#include "utilcpp/Assert.hpp"

#include "core/ProjectInfos.hpp"
#include "core/SequenceInfos.hpp"
#include "core/Sequence.hpp"
#include "core/EditionSession.hpp"
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
		, m_selected_session( nullptr )
	{
		UTILCPP_ASSERT( is_valid(infos), "Tried to construct a Project with invalid project infos!" );
	}

	Project::Project( const bfs::path& project_file_path )
		: m_location( project_file_path )
		, m_directory_path( project_file_path.parent_path() )
		, m_selected_session( nullptr )
	{
		UTILCPP_ASSERT( !project_file_path.empty(), "Tried to construct a Project at an empty path!" );
		UTILCPP_ASSERT( bfs::is_regular_file( m_location ), "Tried to create a project with an invalid file path! Path : " << m_location )
		UTILCPP_ASSERT( bfs::is_directory( m_directory_path ), "Wow, what's wrong with that project's directory? Path : " << m_directory_path )

		// THINK : make it  a throwing test?
		UTILCPP_ASSERT( boost::filesystem::exists( project_file_path ), "Tried to construct a Project with a path that don't exist!" ); 

		// THINK : move that in a separate function?
		using namespace boost::property_tree;
		ptree infos;

		try
		{
			bfs::ifstream filestream( project_file_path );			
			read_xml( filestream, infos );
		}
		catch( const boost::exception& e )
		{
			UTILCPP_LOG_ERROR << "ERROR on Project file loading : \n" << boost::diagnostic_information(e);
		}

		try
		{
			m_name = infos.get<std::string>( "project.name" );
		}
		catch( const boost::exception& e )
		{
			UTILCPP_LOG_ERROR << "ERROR on Project's properties reading : \n" << boost::diagnostic_information(e);
		}

		try
		{
			auto sequences = infos.get_child( "project.sequences", ptree() );

			if( !sequences.empty() )
			{
				std::for_each( sequences.begin(), sequences.end(), [&]( const std::pair< std::string, ptree >& sequence_info )
				{
					if( sequence_info.first == "sequence" )
					{
						const bfs::path sequence_location = sequence_info.second.get_value<std::string>();
						add_sequence( std::unique_ptr<Sequence>( new Sequence( *this, sequence_location ) ) );

						UTILCPP_LOG << "Loaded Sequence : " << m_sequences.back().name() << " [" << m_sequences.back().id() << "]";
					}
					else
					{
						UTILCPP_LOG_ERROR << "Found an unknown tag! Should be \"sequence\" instead of \"" << sequence_info.first << "\"";
					}



				});
			}
			else
			{
				UTILCPP_LOG << "No sequences in this project.";
			}
			
		}
		catch( const boost::exception& e )
		{
			UTILCPP_LOG_ERROR << "ERROR on Project's sequences loading : \n" << boost::diagnostic_information(e);
		}

		try
		{
			auto edition_sessions = infos.get_child( "project.edition", ptree() );

			if( !edition_sessions.empty() )
			{
				std::for_each( edition_sessions.begin(), edition_sessions.end(), [&]( const std::pair< std::string, ptree >& edition_session )
				{
					if( edition_session.first == "session" )
					{
						const bfs::path session_file_location = directory_path() / path::EDITION_SESSION_FILE( edition_session.second.get_value<std::string>() );
						add_edition( std::unique_ptr<EditionSession>( new EditionSession( *this, session_file_location ) ) );

						UTILCPP_LOG << "Loaded edition session : [" << m_edit_sessions.back().id() << "]";

					}
					else
					{
						UTILCPP_LOG_ERROR << "Found an unknown tag! Should be \"session\" instead of \"" << edition_session.first << "\"";
					}
				});
			}
			else
			{
				UTILCPP_LOG << "No edition session for this project.";
			}

		}
		catch( const boost::exception& e )
		{
			UTILCPP_LOG_ERROR << "ERROR on Project's edition session loading : \n" << boost::diagnostic_information(e);
		}

		
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

		foreach_edition( [&]( const EditionSession& edition_session )
		{ 
			infos.add( "project.edition.session", edition_session.id() );
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
			UTILCPP_LOG_ERROR <<  boost::diagnostic_information(e);
			return false;
		}

		std::for_each( m_sequences.begin(), m_sequences.end(), []( Sequence& sequence ){ sequence.save(); });
		std::for_each( m_edit_sessions.begin(), m_edit_sessions.end(), []( EditionSession& edition_session ){ edition_session.save(); });

		return true;
	}

	void Project::foreach_sequence( std::function< void ( const Sequence& sequence )> func ) const
	{
		std::for_each( m_sequences.begin(), m_sequences.end(), func );
	}

	void Project::foreach_edition( std::function< void ( const EditionSession& edition_session )> func ) const
	{
		std::for_each( m_edit_sessions.begin(), m_edit_sessions.end(), func );
	}

	bool Project::new_sequence( const SequenceInfos& infos )
	{
		auto sequence = new Sequence( *this, infos );
		
		add_sequence( std::unique_ptr<Sequence>( sequence ) );
		emit sequence_created( *sequence );

		if( infos.is_edition_requested )
		{
			EditionSessionInfos session_infos;
			session_infos.name = sequence->name();
			session_infos.sequence_id = sequence->id();
			return new_edition( session_infos );
		}

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

	bool Project::new_edition( const EditionSessionInfos& session_infos )
	{
		Sequence* sequence = find_sequence( session_infos.sequence_id );
		
		if( sequence )
		{
			add_edition( std::unique_ptr< EditionSession >( new EditionSession( *this, *sequence, session_infos.name ) ) );

			return true;
		}

		return false;
	}

	bool Project::new_edition()
	{
		// request the new edition session
		const EditionSessionInfos infos = view::request_new_edition_session_infos();

		// create and register the sequence
		if( is_valid( infos ) ) 
			return new_edition( infos );
		else 
			return false;
	}


	void Project::add_sequence( std::unique_ptr<Sequence>&& sequence )
	{
		UTILCPP_ASSERT_NOT_NULL( sequence );
		m_sequences.push_back( sequence.release() );
	}


	void Project::add_edition( std::unique_ptr<EditionSession>&& edition )
	{
		UTILCPP_ASSERT_NOT_NULL( edition );
		m_edit_sessions.push_back( edition.release() );

		emit edition_begin( m_edit_sessions.back() ); 		
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

	EditionSession* Project::find_edition( const EditionSessionId& session_id )
	{
		if( m_edit_sessions.empty() )
			return nullptr;

		auto find_it = std::find_if( m_edit_sessions.begin(), m_edit_sessions.end(), [&]( EditionSession& edition_session ){ return edition_session.id() == session_id; } );

		if( find_it != m_edit_sessions.end() )
			return &(*find_it);
		else
			return nullptr;
	}

	void Project::select_edition_session( const EditionSessionId& session_id )
	{
		EditionSession* edition_session = find_edition( session_id );

		if( edition_session )
		{
			auto* previous_selected_session = selected_edition_session();

			m_selected_session = edition_session;

			if( previous_selected_session )
			{
				emit edition_deselected( *previous_selected_session );
			}

			emit edition_selected( *selected_edition_session() );
		}

	}





}
}