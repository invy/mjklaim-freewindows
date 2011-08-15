#include "aoslcpp/algorithm/for_each.hpp"

#include "aosl/aosl.hpp"

namespace aoslcpp
{

	void for_each_object( const aosl::List_object& list_objects, std::function< void( const aosl::Object& )> func )
	{
		auto& object_sequence = list_objects.object();
		std::for_each( object_sequence.begin(), object_sequence.end(), [&]( const aosl::Object& object )
		{
			func( object );
			for_each_object( object, func );
		});
	}

	void for_each_object( const aosl::Object& parent, std::function< void( const aosl::Object& )> func )
	{
		if( parent.children() )
		{
			for_each_object( *parent.children(), func );
		}

	}

	void for_each_object( const aosl::Canvas& canvas, std::function< void( const aosl::Object& )> func )
	{
		for_each_object( canvas.objects(), func );
	}


}