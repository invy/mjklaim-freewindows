#ifndef HGUARD_AOSD_STATE_EDITINGPROJECT_HPP__
#define HGUARD_AOSD_STATE_EDITINGPROJECT_HPP__
#pragma once

#include "Events.hpp"

#include <boost/msm/front/states.hpp>

namespace aosd
{
namespace state
{
	class DesignerStateMachine;

	class EditingProject
		: public boost::msm::front::state<>
	{
	public:
		
		template< class EventType, class FSM >
		void on_entry( const EventType& event, FSM& statemachine )
		{

		}

		void on_exit();

	private:


	};

}
}


#endif
