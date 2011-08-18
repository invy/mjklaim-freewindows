#include "core/StoryWalker.hpp"

#include "core/Sequence.hpp"

#include "aoslcpp/SequenceInterpreter.hpp"

namespace aosd
{
namespace core
{
	

	StoryWalker::StoryWalker( const Sequence& sequence )
		: m_sequence( sequence )
	{
		restart();
	}

	void StoryWalker::restart()
	{
		m_interpreter= m_sequence.new_interpreter();
		
		emit restarted();
	}

}
}