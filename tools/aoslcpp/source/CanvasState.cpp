#include "aoslcpp/CanvasState.hpp"

#include <functional>

#include "aosl/canvas.hpp"

namespace aoslcpp
{
	// TODO : move that in a header later
	void for_each_object( const aosl::List_object& list_objects, std::function< void( const aosl::Object& )> func );
	void for_each_object( const aosl::Object& object, std::function< void( const aosl::Object& )> func );
	void for_each_object( const aosl::Canvas& canvas, std::function< void( const aosl::Object& )> func );

	void for_each_object( const aosl::Object& object, std::function< void( const aosl::Object& )> func )
	{
		if( object.children() )
		{
			for_each_object( *object.children(), func );
		}

	}

	void for_each_object( const aosl::List_object& list_objects, std::function< void( const aosl::Object& )> func )
	{
		auto& object_sequence = list_objects.object();
		std::for_each( object_sequence.begin(), object_sequence.end(), [&]( const aosl::Object& object )
		{
			func( object );
			for_each_object( object, func );
		});
	}

	// TODO : move that in a header later
	void for_each_object( const aosl::Canvas& canvas, std::function< void( const aosl::Object& )> func )
	{
		auto& objects = canvas.objects();

		for_each_object( objects, func );

	}

	
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

	void CanvasState::activate( aosl::Object_ref object )
	{

	}

	void CanvasState::deactivate( aosl::Object_ref object )
	{

	}

}