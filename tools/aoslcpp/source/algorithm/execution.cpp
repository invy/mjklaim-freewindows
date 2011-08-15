#include "aoslcpp/algorithm/execution.hpp"

#include <functional>

#include "aoslcpp/algorithm/algorithm.hpp"
#include "aosl/canvas.hpp"
#include "aosl/object.hpp"
#include "aosl/object_ref.hpp"

namespace aoslcpp
{
	namespace
	{
		template< class Function >
		void change_object( const aosl::Canvas& canvas, const aosl::Object_ref object_ref, Function func )
		{
			auto object = find_object( canvas, object_ref );

			if( object )
			{
				func( *object );
			}
		}

	}

	void activate( aosl::Canvas& canvas, const aosl::Object_ref object_ref )
	{
		change_object( canvas, object_ref, []( aosl::Object& object){ object.active( true ); } );
	}

	void deactivate( aosl::Canvas& canvas, const aosl::Object_ref object_ref )
	{
		change_object( canvas, object_ref, []( aosl::Object& object){ object.active( false ); } );
	}

	void switch_state( aosl::Canvas& canvas, const aosl::Object_ref object_ref )
	{
		change_object( canvas, object_ref, []( aosl::Object& object){ object.active( !object.active() ); } );
	}

	void execute( aosl::Canvas& canvas, const aosl::Change& change )
	{

	}

	

}