#ifndef HGUARD_AOSD_STATE_APPLICATIONSM_HPP__
#define HGUARD_AOSD_STATE_APPLICATIONSM_HPP__
#pragma once

#include <memory>

namespace aosd
{
namespace state
{
	
	class DesignerStateMachine
	{
	public:
	
		DesignerStateMachine();
		~DesignerStateMachine();

		void start();
		

	private:

		class StateMachine;
		std::unique_ptr<StateMachine> m_state_machine;

	};

}
}


#endif
