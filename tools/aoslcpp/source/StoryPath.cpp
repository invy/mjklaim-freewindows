#include "aoslcpp/StoryPath.hpp"

#include "utilcpp/Assert.hpp"

namespace aoslcpp
{

	void StoryPath::add_step( aosl::Move_ref move_ref, aosl::Stage_ref stage_ref )
	{
		m_steps.push_back( Step( move_ref, stage_ref ) );
	}

	void StoryPath::step_back( std::size_t step_count )
	{
		UTILCPP_ASSERT( step_count > 0, "Invalid step count for stepping back : " << step_count );

		while( can_step_back() && step_count != 0 ) // we need to have at least one step
		{
			m_steps.pop_back();
			--step_count;
		}

	}

}