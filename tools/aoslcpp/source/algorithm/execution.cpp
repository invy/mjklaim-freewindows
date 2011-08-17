#include "aoslcpp/algorithm/execution.hpp"

#include <functional>
#include <map>

#include "utilcpp/Assert.hpp"

#include "aoslcpp/algorithm/find.hpp"
#include "aosl/aosl.hpp"

namespace aoslcpp
{
	namespace 
	{
		template< class ActionFunc >
		void get_check_act_object( aosl::Canvas& canvas, const aosl::Object_ref object_ref, ActionFunc action )
		{
			auto object = find_object( canvas, object_ref );
			if( object )
				action( *object );
			else
			{
				UTILCPP_LOG_ERROR << "Tried to do \"" << typeid(action).name() << "\" but failed because the object \"" << object_ref << "\" was not found!";
			}
		}

		
				
	}

	


	void activate( aosl::Object& object )
	{
		object.active( true );
	}

	void activate( aosl::Canvas& canvas, const aosl::Object_ref object_ref )
	{
		get_check_act_object( canvas, object_ref, []( aosl::Object& obj ){ activate(obj); } );
	}

	void deactivate( aosl::Object& object )
	{
		object.active( false );
	}

	void deactivate( aosl::Canvas& canvas, const aosl::Object_ref object_ref )
	{
		get_check_act_object( canvas, object_ref, []( aosl::Object& obj ){ deactivate(obj); } );
	}

	void switch_state( aosl::Object& object )
	{
		object.active( !object.active() );
	}

	void switch_state( aosl::Canvas& canvas, const aosl::Object_ref object_ref )
	{
		get_check_act_object( canvas, object_ref, []( aosl::Object& obj ){ switch_state(obj); } );
	}


	void transform( aosl::Properties_graphic_object& graphic_properties, const aosl::Transformation& transformation )
	{
		UTILCPP_NOT_IMPLEMENTED_YET;
	}

	void transform( aosl::Canvas& canvas, const aosl::Object_ref object_ref, const aosl::Transformation& transformation )
	{
		UTILCPP_NOT_IMPLEMENTED_YET;
	}


	void execute( const aosl::Change& change, aosl::Object& object )
	{
		UTILCPP_ASSERT( change.object() == object.id(), "Tried to execute a change \"" << typeid(change).name() 
			<< "\" that should be executed with object \""  << change.object()
			<< "\" but is executed with object \"" << object.id() << "\"!"			
			);

		typedef std::map< const char*, std::function< void ( aosl::Object& object ) > > ChangeFunctionMap;

		const ChangeFunctionMap CHANGE_FUNCTION_MAP = []() -> ChangeFunctionMap 
		{
			ChangeFunctionMap change_function_map;
			change_function_map[ typeid(aosl::Change_activate).name()		] = []( aosl::Object& object ) { activate( object ); };
			change_function_map[ typeid(aosl::Change_deactivate).name()		] = []( aosl::Object& object ) { deactivate( object ); };
			change_function_map[ typeid(aosl::Change_switch).name()			] = []( aosl::Object& object ) { switch_state( object ); };
			// TODO : add transformation change here
			return change_function_map;
		}();

		auto change_type_name = typeid(change).name();
		auto func_it = CHANGE_FUNCTION_MAP.find( change_type_name ); 

		if( func_it != CHANGE_FUNCTION_MAP.end() )
		{
			func_it->second( object );
		}
		else
		{
			UTILCPP_LOG_ERROR << "Algorithm for Change of type \"" << change_type_name << "\" not found! ";
		}
	}


	void execute( aosl::Canvas& canvas, const aosl::Change& change )
	{
		get_check_act_object( canvas, change.object(), [&]( aosl::Object& object )
		{
			execute( change, object );
		});
		
	}

	void execute( aosl::Canvas& canvas, const aosl::List_change& change_list )
	{
		auto sorted_change_list = change_list.change();
		std::sort( sorted_change_list.begin(), sorted_change_list.end(), []( const aosl::Change& a, const aosl::Change& b )
		{
			return a.object() < b.object();
		});

		aosl::Object_ref object_ref("");
		aosl::Object* object = nullptr;

		for( auto it = sorted_change_list.begin(); it != sorted_change_list.end(); ++it )
		{
			const aosl::Change& change = *it;

			if( object_ref != change.object() )
			{
				object_ref = change.object();
				object = find_object( canvas, object_ref );
			}

			UTILCPP_ASSERT_NOT_NULL( object );
			
			execute( change, *object );
		}
	}


	

}