#include "core/StoryWalker.hpp"


#include "aoslcpp/SequenceInterpreter.hpp"

namespace aosd
{
namespace core
{
	

	StoryWalker::StoryWalker( const aoslcpp::SequenceInterpreter& interpreter )
		: m_interpreter( interpreter )
	{
	}

	void StoryWalker::restart( const aoslcpp::SequenceInterpreter& interpreter )
	{
		m_interpreter = interpreter;
		
		emit restarted();
	}

}
}