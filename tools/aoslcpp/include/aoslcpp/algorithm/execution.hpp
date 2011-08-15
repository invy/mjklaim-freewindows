#ifndef HGUARD_AOSLCPP_EXECUTION_HPP__
#define HGUARD_AOSLCPP_EXECUTION_HPP__
#pragma once

#include "aosl/aosl_forward.hpp"

namespace aoslcpp
{
	/** Execute the provided Change.
	**/
	void execute( aosl::Canvas& canvas, const aosl::Change& change );

	// TODO or YAGNI : add an optimized version of execute that take a range of changes and sort them by subject id, only getting an object once for all changes applied to it.

	void activate( aosl::Canvas& canvas, const aosl::Object_ref object_ref );
	void deactivate( aosl::Canvas& canvas, const aosl::Object_ref object_ref );
	void switch_state( aosl::Canvas& canvas, const aosl::Object_ref object_ref );

	
}


#endif