#include "state/DesignerStateMachine.hpp"

#include <boost/msm/back/state_machine.hpp>
#include <boost/msm/front/state_machine_def.hpp>

#include "state/States.hpp"
#include "state/Events.hpp"

namespace aosd
{
namespace state
{
	namespace
	{
		class DesignerStateMachineDef
			: public boost::msm::front::state_machine_def< DesignerStateMachineDef >
		{
		public:

			typedef Welcome initial_state;

			struct transition_table : public boost::mpl::vector
			<
				_row< Welcome			, event::open_project		, ProjectEdition		>
			,	_row< ProjectEdition	, event::close_project		, Welcome				>
			>
			{};

		};

	}

	class DesignerStateMachine::StateMachine
		: public boost::msm::back::state_machine< DesignerStateMachineDef >
	{

	};

	DesignerStateMachine::DesignerStateMachine()
		: m_state_machine( new DesignerStateMachine::StateMachine() )
	{

	}

	DesignerStateMachine::~DesignerStateMachine()
	{

	}

	void DesignerStateMachine::start()
	{
		m_state_machine->start();
	}


}
}