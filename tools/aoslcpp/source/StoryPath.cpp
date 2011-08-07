#include "aoslcpp/StoryPath.hpp"


namespace aoslcpp
{
	


	StoryPath::StoryPath( aosl::Stage_ref first_stage, const std::size_t max_size )
		: m_max_size( max_size )
	{
		if( m_max_size > 0 )
		{
			m_stages.reserve( max_size ); // don't optimize yet...but if it don't cost anything, who cares?
		}

		add_step( first_stage );
	}

	void StoryPath::add_step( aosl::Stage_ref stage_id )
	{
		m_stages.push_back( stage_id );
	}

}