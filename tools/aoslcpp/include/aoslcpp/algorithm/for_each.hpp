#ifndef HGUARD_AOSLCPP_FOREACH_HPP__
#define HGUARD_AOSLCPP_FOREACH_HPP__
#pragma once

#include "aoslcpp/algorithm/function.hpp"


namespace aoslcpp
{

	/** Apply the given function to every Object in the given Canvas.
		The function will be called for all the objects of the object trees.

		@param canvas		Canvas that contains the Objects we will iterate through.
		@param func			Function to call for each Object.
	*/
	void for_each_object( const aosl::Canvas& canvas, ObjectReaderFunc func );

	/** Apply the given function to every child Object of a given parent Object.
		The function will be called recursively for all the children of the parent.

		@param parent		Parent object to start looking in for Objects. Will be ignored.
		@param func			Function to call for each Object.
	*/
	void for_each_object( const aosl::Object& parent, ObjectReaderFunc func );

}


#endif
