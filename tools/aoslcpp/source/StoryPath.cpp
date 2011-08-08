#include "aoslcpp/StoryPath.hpp"

#include "utilcpp/Assert.hpp"

namespace aoslcpp
{
	


	StoryPath::StoryPath( aosl::Stage_ref first_stage )
	{
		add_step( first_stage );
	}

	void StoryPath::add_step( aosl::Stage_ref stage_id )
	{
		m_stages.push_back( stage_id );
	}

	aosl::Stage_ref StoryPath::step_back( std::size_t step_count )
	{
		UTILCPP_ASSERT( step_count > 0, "Invalid step count : " << step_count );

		while( m_stages.size() > 1 && step_count != 0 )
		{
			m_stages.pop_back();
			--step_count;
		}

		return m_stages.back();
	}

}