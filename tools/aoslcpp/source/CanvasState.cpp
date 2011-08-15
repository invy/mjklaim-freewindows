#include "aoslcpp/CanvasState.hpp"

#include "aoslcpp/algorithm/execution.hpp"

namespace aoslcpp
{
	
	
	CanvasState::CanvasState( const aosl::Canvas& canvas )
		: m_canvas( canvas )
	{
	}
	
	void CanvasState::activate( const aosl::Object_ref object_ref )
	{
		aoslcpp::activate( m_canvas, object_ref );
	}

	void CanvasState::deactivate( const aosl::Object_ref object_ref )
	{
		aoslcpp::deactivate( m_canvas, object_ref );
	}

	void CanvasState::switch_state( const aosl::Object_ref object_ref )
	{
		aoslcpp::switch_state( m_canvas, object_ref );
	}

}