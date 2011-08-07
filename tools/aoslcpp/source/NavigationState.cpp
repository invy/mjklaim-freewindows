#include "aoslcpp/NavigationState.hpp"

#include <algorithm>

namespace aoslcpp
{
	NavigationState::NavigationState( const aosl::Navigation& default_navigation )
		: m_default_navigation( default_navigation )
		, m_current_navigation( default_navigation )
	{

	}

	void NavigationState::update( aosl::Navigation& stage_navigation )
	{
		m_current_navigation = m_default_navigation;

		const auto& stage_events = stage_navigation.event();

		std::for_each( stage_events.begin(), stage_events.end(), [&]( const aosl::Event& event )
		{
			m_current_navigation.event().push_back( event );
		});

	}


}