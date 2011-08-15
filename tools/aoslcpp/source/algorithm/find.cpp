#include "aoslcpp/algorithm/find.hpp"

#include "aosl/aosl.hpp"

namespace aoslcpp
{

	optional<aosl::Object> find_object( const aosl::Canvas& canvas, const aosl::Object_ref object_ref )
	{
		return find_object( canvas.objects(), object_ref );
	}

	optional<aosl::Object> find_object( const aosl::List_object& list_objects, const aosl::Object_ref object_ref )
	{
		const auto& objects = list_objects.object();

		for( auto it = objects.begin(); it != objects.end(); ++it )
		{
			const auto& object = *it;
			if( object.id() == object_ref )
				return object;

			find_object( object, object_ref );
		}

		return optional<aosl::Object>();
	}

	optional<aosl::Object> find_object( const aosl::Object& object, const aosl::Object_ref object_ref )
	{
		return object.children() ? find_object( *object.children(), object_ref ) : optional<aosl::Object>();
	}

}