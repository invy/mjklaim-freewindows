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

		StoryPath( aosl::Stage_ref first_stage );

		void add_step( aosl::Stage_ref stage_id );

		/** Step back in the path and return the resulting current stage ref. */
		aosl::Stage_ref step_back( std::size_t step_count = 1 );

		aosl::Stage_ref current_stage() const { return m_stages.back(); }
		
		std::size_t stage_count() const { return m_stages.size(); }
		

	private:

		std::vector< aosl::Stage_ref > m_stages; 
		
	};


}


#endif
