#ifndef HGUARD_AOSD__STATES_HPP__
#define HGUARD_AOSD__STATES_HPP__
#pragma once

#include <boost/msm/front/states.hpp>

namespace aosd
{
namespace state
{
	// TEMPORARY STATES...
	class Welcome
		: public boost::msm::front::state<>
	{
	};

	class ProjectEdition // TODO : make it a state machine too...
		: public boost::msm::front::state<>
	{
	};

}
}
#endif
