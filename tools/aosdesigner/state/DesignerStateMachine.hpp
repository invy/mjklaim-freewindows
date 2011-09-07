#ifndef HGUARD_AOSD_STATE_DESIGNERSTATEMACHINE_HPP__
#define HGUARD_AOSD_STATE_DESIGNERSTATEMACHINE_HPP__
#pragma once

#include <memory>

#include <boost/msm/back/state_machine.hpp>
#include <boost/msm/front/state_machine_def.hpp>

#include "state/Idle.hpp"
#include "state/Welcome.hpp"
#include "state/EditingProject.hpp"

#include "state/Events.hpp"


namespace aosd
{
namespace state
{
	class DesignerStateMachineDef
		: public boost::msm::front::state_machine_def< DesignerStateMachineDef >
	{	
	public:

		typedef Welcome initial_state;

		struct transition_table : public boost::mpl::vector
			<	_row< Welcome			, event::open_project		, EditingProject	>
			,	_row< EditingProject	, event::closed_project		, Idle				>
			,	_row< Idle				, event::open_project		, EditingProject	>
			>
		{};

	};
	
	class DesignerStateMachine
		: public boost::msm::back::state_machine< DesignerStateMachineDef >
	{
	public:


	private:

	};

}
}


#endif
