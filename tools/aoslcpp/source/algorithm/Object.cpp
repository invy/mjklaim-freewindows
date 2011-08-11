#include "aoslcpp/algorithm/object.hpp"

#include "aosl/canvas.hpp"
#include "aosl/sequence.hpp"

namespace aoslcpp
{
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

	void for_each_object( const aosl::Canvas& canvas, std::function< void( const aosl::Object& )> func )
	{
		auto& objects = canvas.objects();

		for_each_object( objects, func );

	}
	

}