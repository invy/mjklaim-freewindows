#ifndef HGUARD_AOSD_CORE_STORYWALKER_HPP__
#define HGUARD_AOSD_CORE_STORYWALKER_HPP__
#pragma once

#include <memory>

namespace aoslcpp
{
	class SequenceInterpreter;
}

namespace aosd
{
namespace core
{


	/** Allow going through a Sequence story and provide informations about the state of this story.
	*/
	class StoryWalker
	{
	public:

		StoryWalker( std::unique_ptr< SequenceInterpreter >&& interpreter );
	
	private:

		std::unique_ptr< SequenceInterpreter > m_interpreter;
	};


}
}


#endif