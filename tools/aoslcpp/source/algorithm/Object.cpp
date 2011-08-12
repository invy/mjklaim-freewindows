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
	

	ObjectOrNull find_object( const aosl::Canvas& canvas, const aosl::Object_ref object_ref )
	{
		return find_object( canvas.objects(), object_ref );
	}

	ObjectOrNull find_object( const aosl::List_object& list_objects, const aosl::Object_ref object_ref )
	{
		const auto& objects = list_objects.object();
		
		for( auto it = objects.begin(); it != objects.end(); ++it )
		{
			const auto& object = *it;
			if( object.id() == object_ref )
				return object;

			find_object( object, object_ref );
		}

		return ObjectOrNull();
	}

	ObjectOrNull find_object( const aosl::Object& object, const aosl::Object_ref object_ref )
	{
		return object.children() ? find_object( *object.children(), object_ref ) : ObjectOrNull();
	}


}