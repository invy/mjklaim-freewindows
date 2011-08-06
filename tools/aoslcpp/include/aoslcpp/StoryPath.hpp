#ifndef HGUARD_AOSLCPP_STORYPATH_HPP__
#define HGUARD_AOSLCPP_STORYPATH_HPP__
#pragma once

#include <vector>

#include "aosl/stage_ref.hpp"


namespace aoslcpp
{
	/** Path through a story.
	**/
	class StoryPath
	{
	public:

		StoryPath( aosl::Stage_ref first_stage, const std::size_t max_size = 0 );

		void add_step( aosl::Stage_ref stage_id );

		aosl::Stage_ref current_stage() const { return m_stages.back(); }
		

	private:

		std::vector< aosl::Stage_ref > m_stages;

		std::size_t m_max_size;

	};


}


#endif
