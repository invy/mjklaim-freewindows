#ifndef HGUARD_AOSLCPP_NAVIGATIONSTATE_HPP__
#define HGUARD_AOSLCPP_NAVIGATIONSTATE_HPP__
#pragma once

#include <vector>

#include "aosl/navigation.hpp"

namespace aoslcpp
{
	/** Provide the current navigation choices at a specific stage in a sequence's story.
	*/
	class NavigationState
	{
	public:

		NavigationState( const aosl::Navigation& default_navigation );

		void update( aosl::Navigation& stage_navigation );

		const aosl::Navigation& current() const { return m_current_navigation; }


	private:

		aosl::Navigation m_default_navigation;
		aosl::Navigation m_current_navigation;

	};


}


#endif
