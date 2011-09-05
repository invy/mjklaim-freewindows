#include "core/StoryWalker.hpp"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include "core/Sequence.hpp"
#include "core/Project.hpp"
#include "aoslcpp/SequenceInterpreter.hpp"

namespace aosd
{
namespace core
{
	

	StoryWalker::StoryWalker( const Project& project, const Sequence& sequence, const aoslcpp::SequenceInterpreter& interpreter )
		: m_interpreter( interpreter )
		, m_sequence( sequence )
		, m_project( project )
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
		infos.put( "storywalk.sequence", m_sequence.id() );

		// write the path taken in the sequence
		m_interpreter.path().for_each_step( [&]( const aoslcpp::StoryPath::Step& step )
		{
			infos.put( "storywalk.steps.move", step.move );
			infos.put( "storywalk.steps.stage", step.stage );
		});

	}

}
}