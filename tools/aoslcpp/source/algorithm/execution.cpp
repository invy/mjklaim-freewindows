#include "aoslcpp/algorithm/execution.hpp"

#include <functional>
#include <map>

#include "utilcpp/Assert.hpp"

#include "aoslcpp/algorithm/algorithm.hpp"
#include "aosl/canvas.hpp"
#include "aosl/object.hpp"
#include "aosl/object_ref.hpp"
#include "aosl/change.hpp"

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
		typedef std::map< const std::string, std::function< void ( aosl::Canvas& canvas, const aosl::Object_ref object_ref ) > > ChangeFunctionMap;
		static const ChangeFunctionMap CHANGE_FUNCTION_MAP = []() -> ChangeFunctionMap {
			ChangeFunctionMap change_function_map;
			change_function_map[ typeid(aosl::Change_activate).name() ] = aoslcpp::activate;
			change_function_map[ typeid(aosl::Change_deactivate).name() ] = aoslcpp::deactivate;
			change_function_map[ typeid(aosl::Change_switch).name() ] = aoslcpp::switch_state;
			return change_function_map;
		}();

		auto change_type_name = typeid(change).name();
		const auto func_it = CHANGE_FUNCTION_MAP.find( change_type_name ); 
		
		if( func_it != CHANGE_FUNCTION_MAP.end() )
		{
			func_it->second( canvas, change.object() );
		}
		else
		{
			UTILCPP_NOT_IMPLEMENTED_YET;
		}
		
	}

	

}