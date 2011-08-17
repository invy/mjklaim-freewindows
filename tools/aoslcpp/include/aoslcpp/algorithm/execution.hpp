#ifndef HGUARD_AOSLCPP_EXECUTION_HPP__
#define HGUARD_AOSLCPP_EXECUTION_HPP__
#pragma once

#include "aosl/aosl_forward.hpp"

namespace aoslcpp
{
	void activate( aosl::Object& object );
	void deactivate( aosl::Object& object );
	void switch_state( aosl::Object& object );

	void transform( aosl::Properties_graphic_object& graphic_properties, const aosl::Transformation& transformation );

	void activate( aosl::Canvas& canvas, const aosl::Object_ref object_ref );
	void deactivate( aosl::Canvas& canvas, const aosl::Object_ref object_ref );
	void switch_state( aosl::Canvas& canvas, const aosl::Object_ref object_ref );

	void transform( aosl::Canvas& canvas, const aosl::Object_ref object_ref, const aosl::Transformation& transformation );


	/** Execute the provided Change.
	**/
	void execute( const aosl::Change& change, aosl::Object& object );
	void execute( aosl::Canvas& canvas, const aosl::Change& change );
	void execute( aosl::Canvas& canvas, const aosl::List_change& change_list );
	

}


#endif