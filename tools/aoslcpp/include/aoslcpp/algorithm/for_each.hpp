#ifndef HGUARD_AOSLCPP_FOREACH_HPP__
#define HGUARD_AOSLCPP_FOREACH_HPP__
#pragma once

#include <functional>
#include "aosl/aosl_forward.hpp"

namespace aoslcpp
{

	/** Apply the given (READ-ONLY) function to every Object in the given Canvas. 
		The function will be called for all the objects of the object trees.

		@param canvas		Canvas that contains the Objects we will iterate through.
		@param func			Function to call for each Object.
	*/
	void for_each_object( const aosl::Canvas& canvas, std::function< void( const aosl::Object& )> func );

	/** Apply the given (READ-ONLY) function to every child Object of a given parent Object. READ-ONLY
		The function will be called recursively for all the children of the parent.

		@param parent		Parent object to start looking in for Objects. Will be ignored.
		@param func			Function to call for each Object.
	*/
	void for_each_object( const aosl::Object& parent, std::function< void( const aosl::Object& )> func );

}


#endif
