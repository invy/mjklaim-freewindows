#ifndef HGUARD_AOSLCPP_SEQUENCEINTERPRETER_HPP__
#define HGUARD_AOSLCPP_SEQUENCEINTERPRETER_HPP__
#pragma once

#include "aoslcpp/StoryPath.hpp"

namespace aosl
{
	class Sequence;
}

namespace aoslcpp
{
	/** Walks through a sequence's to interpret it's story.
	**/
	class SequenceInterpreter
	{
	public:
		
		SequenceInterpreter( const aosl::Sequence& sequence );

		const StoryPath& path() const { return m_path; }

	private:

		const aosl::Sequence& m_sequence;

		StoryPath m_path;

	};


}


#endif
