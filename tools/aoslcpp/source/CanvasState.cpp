#include "aoslcpp/CanvasState.hpp"

#include "aoslcpp/algorithm/for_each.hpp"
#include "aoslcpp/algorithm/find.hpp"

namespace aoslcpp
{
	
	
	CanvasState::CanvasState( const aosl::Canvas& canvas )
		: m_canvas( canvas )
	{
		for_each_object( canvas, [&]( const aosl::Object& object )
		{
			if( object.active() )
			{
				m_active_objects.push_back( object.id() );
			}
			else
			{
				m_unactive_objects.push_back( object.id() );
			}

		});
	}
	
	void CanvasState::activate( aosl::Object_ref object_ref )
	{
		auto object = find_object( m_canvas, object_ref );

		if( object )
		{
			object->active( true );
		}
	}

	void CanvasState::deactivate( aosl::Object_ref object_ref )
	{
		auto object = find_object( m_canvas, object_ref );

		if( object )
		{
			object->active( false );
		}
	}

	void CanvasState::switch_state( aosl::Object_ref object_ref )
	{
		auto object = find_object( m_canvas, object_ref );

		if( object )
		{
			object->active( !object->active() );
		}
	}

}