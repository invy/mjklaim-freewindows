#ifndef HGUARD_AOSD_STATE_WELCOME_HPP__
#define HGUARD_AOSD_STATE_WELCOME_HPP__
#pragma once

#include <boost/msm/front/states.hpp>
#include "state/Events.hpp"

namespace aosd
{
namespace state
{
	class Welcome
		: public boost::msm::front::state<>
	{
	public:
		
		template< class Event, class FSM >
		void on_entry( const Event&, FSM& fsm )
		{
			show_welcome();
			fsm.process_event( event::open_project() );
		}

	private:

		void show_welcome();


	};

}
}


#endif
