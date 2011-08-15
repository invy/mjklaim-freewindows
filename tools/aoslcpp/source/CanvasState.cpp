#include "aoslcpp/CanvasState.hpp"

#include "aoslcpp/algorithm/for_each.hpp"
#include "aoslcpp/algorithm/find.hpp"

namespace aoslcpp
{
	
	
	CanvasState::CanvasState( const aosl::Canvas& canvas )
		: m_canvas( canvas )
	{
	}
	
	void CanvasState::activate( aosl::Object_ref object_ref )
	{
		change_object( object_ref, []( aosl::Object& object){ object.active( true ); } );
	}

	void CanvasState::deactivate( aosl::Object_ref object_ref )
	{
		change_object( object_ref, []( aosl::Object& object){ object.active( false ); } );
	}

	void CanvasState::switch_state( aosl::Object_ref object_ref )
	{
		change_object( object_ref, []( aosl::Object& object){ object.active( !object.active() ); } );
	}

	void CanvasState::change_object( aosl::Object_ref object_ref, std::function< void (aosl::Object&) > func )
	{
		auto object = find_object( m_canvas, object_ref );

		if( object )
		{
			func( *object );
		}
	}

}