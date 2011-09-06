#include "core/StoryWalker.hpp"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/exception/diagnostic_information.hpp>

#include "utilcpp/Assert.hpp"
#include "utilcpp/Log.hpp"

#include "core/Sequence.hpp"
#include "core/Project.hpp"
#include "aoslcpp/SequenceInterpreter.hpp"
#include "Paths.hpp"

namespace aosd
{
namespace core
{
	

	StoryWalker::StoryWalker( const Project& project, const Sequence& sequence )
		: m_sequence( &sequence )
		, m_project( project )
		, m_interpreter( sequence.make_interpreter() )
		, m_id( to_string( boost::uuids::random_generator()() ) )
	{
		UTILCPP_ASSERT_NOT_NULL( m_sequence ); // TODO : replace this by an throwing an exception
	}

	StoryWalker::StoryWalker( const Project& project, const bfs::path& file_path )
		: m_project( project )
		, m_sequence( nullptr )
		, m_id( to_string( boost::uuids::nil_generator()() ) )
	{
		using namespace boost::property_tree;

		try
		{
			bfs::ifstream file_stream( file_path );

			if( file_stream.fail() )
			{
				UTILCPP_LOG_ERROR << "Failed to open file " << file_path;
				return;
			}

			ptree infos;
			read_xml( file_stream, infos );

			m_id = infos.get<StoryWalkerId>( "storywalk.id" );

			auto sequence_id = infos.get<SequenceId>( "storywalk.sequence" );
			if( !sequence_id.empty() && sequence_id != "NONE" )
			{
				m_sequence = project.find_sequence( sequence_id );
				if( m_sequence )
				{
					m_interpreter = m_sequence->make_interpreter();

					// TODO : inject the path in the interpreter, maybe in another (public) function?
				}
				else
				{
					UTILCPP_LOG_ERROR << "Sequence id not found in the project!";
				}
			}
			else
			{
				UTILCPP_LOG_ERROR << "No valid sequence id!";
			}

		}
		catch( const boost::exception& e )
		{
			UTILCPP_LOG_ERROR <<  boost::diagnostic_information(e);
		}
		

	}


	void StoryWalker::save()
	{
		using namespace boost::property_tree;

		ptree infos;

		// write the sequence id
		infos.put( "storywalk.id", id() );
		infos.put( "storywalk.sequence", m_sequence ? m_sequence->id() : "NONE" );

		// write the path taken in the sequence
		if( m_interpreter )
		{
			m_interpreter->path().for_each_step( [&]( const aoslcpp::StoryPath::Step& step )
			{
				//infos.put( "storywalk.steps.move", step.move );
				//infos.put( "storywalk.steps.stage", step.stage );
			});
		}
		

		const auto& file_path = m_project.directory_path() / path::STORYWALK_FILE( id() );

		try
		{
			namespace bfs = boost::filesystem;
			bfs::ofstream file_stream( file_path );

			write_xml( file_stream, infos );
		}
		catch( const boost::exception& e )
		{
			UTILCPP_LOG_ERROR <<  boost::diagnostic_information(e);
		}

	}

}
}