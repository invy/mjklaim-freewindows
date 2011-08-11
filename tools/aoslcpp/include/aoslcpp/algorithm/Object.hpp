#ifndef HGUARD_AOSLCPP_OBJECT_HPP__
#define HGUARD_AOSLCPP_OBJECT_HPP__
#pragma once

#include <functional>

#include <boost/optional.hpp>

#include "aosl/aosl_forward.hpp"
#include "aosl/object.hpp"

namespace aoslcpp
{
	typedef std::function< void( const aosl::Object& )> ObjectReaderFunc;

	void for_each_object( const aosl::List_object& list_objects, ObjectReaderFunc func );
	void for_each_object( const aosl::Object& object, ObjectReaderFunc func );
	void for_each_object( const aosl::Canvas& canvas, ObjectReaderFunc func );

	
	typedef boost::optional< aosl::Object > ObjectOrNull;

	ObjectOrNull find_object( const aosl::Canvas& canvas, const aosl::Object_ref object_ref );


}


#endif