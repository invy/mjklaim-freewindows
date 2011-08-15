#ifndef HGUARD_AOSLCPP_FOREACH_HPP__
#define HGUARD_AOSLCPP_FOREACH_HPP__
#pragma once

#include "aoslcpp/algorithm/function.hpp"


namespace aoslcpp
{

	void for_each_object( const aosl::List_object& list_objects, ObjectReaderFunc func );
	void for_each_object( const aosl::Object& object, ObjectReaderFunc func );
	void for_each_object( const aosl::Canvas& canvas, ObjectReaderFunc func );


}


#endif
