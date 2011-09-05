#include "core/StoryWalker.hpp"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/exception/diagnostic_information.hpp>

#include "utilcpp/Log.hpp"

#include "core/Sequence.hpp"
#include "core/Project.hpp"
#include "aoslcpp/SequenceInterpreter.hpp"
#include "Paths.hpp"

namespace aosd
{
namespace core
{
	

	StoryWalker::StoryWalker( const Project& project, const Sequence& sequence, const aoslcpp::SequenceInterpreter& interpreter )
		: m_interpreter( interpreter )
		, m_sequence( sequence )
		, m_project( project )
		, m_id( to_string( boost::uuids::random_generator()() ) )
	{
	}

	void StoryWalker::restart( const aoslcpp::SequenceInterpreter& interpreter )
	{
		m_interpreter = interpreter;
		
		emit restarted();
	}

	void StoryWalker::save()
	{
		using namespace boost::property_tree;

		ptree infos;

		// write the sequence id
		infos.put( "storywalk.id", id() );
		infos.put( "storywalk.sequence", m_sequence.id() );

		// write the path taken in the sequence
		/**m_interpreter.path().for_each_step( [&]( const aoslcpp::StoryPath::Step& step )
		{
			infos.put( "storywalk.steps.move", step.move );
			infos.put( "storywalk.steps.stage", step.stage );
		});**/

		const auto& file_path = m_project.directory_path() / path::STORYWALK_FILE( id() );

		try
		{
			namespace bfs = boost::filesystem;
			bfs::ofstream file_stream( file_path );

			write_xml( file_stream, infos );
		}
		catch( const boost::exception& e )
		{
			// TODO : add logging here
			UTILCPP_LOG_ERROR <<  boost::diagnostic_information(e);
		}

	}

}
}