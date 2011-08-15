#ifndef HGUARD_AOSLCPP_FUNCTION_HPP__
#define HGUARD_AOSLCPP_FUNCTION_HPP__
#pragma once

#include <functional>

#include "aosl/aosl_forward.hpp"


namespace aoslcpp
{

	typedef std::function< void( const aosl::Object& )> ObjectReaderFunc;
	
}


#endif
