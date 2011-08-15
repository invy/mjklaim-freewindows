#ifndef HGUARD_AOSLCPP_FIND_HPP__
#define HGUARD_AOSLCPP_FIND_HPP__
#pragma once

#include <boost/optional.hpp>

#include "aosl/aosl_forward.hpp"

namespace aoslcpp
{
	using boost::optional;

	optional<aosl::Object> find_object( const aosl::Canvas& canvas, const aosl::Object_ref object_ref );
	optional<aosl::Object> find_object( const aosl::List_object& list_objects, const aosl::Object_ref object_ref );
	optional<aosl::Object> find_object( const aosl::Object& object, const aosl::Object_ref object_ref );
	
}


#endif
