#ifndef HGUARD_AOSD_UTIL_ASSERT_HPP__
#define HGUARD_AOSD_UTIL_ASSERT_HPP__
#pragma once

#include <exception>

#include "util/Log.hpp"

// TODO : move that in hard config file - depends on other possible configurations
#ifdef _DEBUG
	#define AOSD_ASSERTIONS_ON 1
	#define AOSD_ASSERTIONS_LOG_ON 1
	#define AOSD_ASSERTIONS_DEBUGBREAK_ON 1
	#define AOSD_ASSERTIONS_CRASH_ON 1
#else
	#define AOSD_ASSERTIONS_ON 0
	#define AOSD_ASSERTIONS_LOG_ON 0
	#define AOSD_ASSERTIONS_DEBUGBREAK_ON 0
	#define AOSD_ASSERTIONS_CRASH_ON 0
#endif

#define AOSD_DEBUGBREAK ::__debugbreak()

#if AOSD_ASSERTIONS_LOG_ON == 1
	#define AOSD_ASSERTIONS_LOG( expression__, message__ ) \
		AOSD_LOG_ERROR	<< "\n#############################################" \
						<< "\n#### Assertion Failed! : " << #expression__ \
						<< "\n## Function : "	<< __FUNCTION__ \
						<< "\n## File : "		<< __FILE__ \
						<< "\n## Line : "		<< __LINE__ \
						<< "\n##" \
						<< "\n## Message : \n\t\t"	<< message__  \
						<< "\n##" \
						<< "\n#############################################\n\n";
#else 
	#define AOSD_ASSERTIONS_LOG( expression__, message__ )
#endif

#if AOSD_ASSERTIONS_DEBUGBREAK_ON == 1
	#define AOSD_ASSERTIONS_DEBUGBREAK AOSD_DEBUGBREAK
#else 
	#define AOSD_ASSERTIONS_DEBUGBREAK
#endif

#if AOSD_ASSERTIONS_CRASH_ON == 1
	#define AOSD_ASSERTIONS_CRASH  std::terminate()
#else 
	#define AOSD_ASSERTIONS_CRASH
#endif

#define AOSD_ASSERTION_IMPLEMENTATION( expression__, message__ ) \
			AOSD_ASSERTIONS_LOG( expression__, message__ ); \
			AOSD_ASSERTIONS_DEBUGBREAK; \
			AOSD_ASSERTIONS_CRASH;


#if AOSD_ASSERTIONS_ON == 1

	#define AOSD_ASSERT( expression__, message__ ) if( !(expression__) ) { AOSD_ASSERTION_IMPLEMENTATION( expression__, message__ ); }

	#define AOSD_ASSERT_NULL( expression__ ) AOSD_ASSERT( !(expression__), #expression__ " IS NOT NULL! It should be!" )
	#define AOSD_ASSERT_NOT_NULL( expression__ ) AOSD_ASSERT( expression__, #expression__ " IS NULL! It shouldn't be!" )

#else
	
	#define AOSD_ASSERT( expression__, message__ )
	#define AOSD_ASSERT_NULL( expression__ )
	#define AOSD_ASSERT_NOT_NULL( expression__ )

#endif

/////////////////////////////////////////////
// some utility macros

/// Use this macro in functions wich implementation will be written later.
#define AOSD_NOT_IMPLEMENTED_YET \
	AOSD_LOG_ERROR	<< "\n##########################################" \
					<< "\n## !!!! NOT IMPLEMENTED YET !!! " \
					<< "\n## Function : "	<< __FUNCTION__ \
					<< "\n## File : "		<< __FILE__ \
					<< "\n## Line : "		<< __LINE__ \
					<< "\n##########################################\n" \
					; \
					AOSD_DEBUGBREAK

/// Use this macro when you just want to remember to implement a function before compiling
#define AOSD_DO_IT_NOW	static_assert( false, "NOT IMPLEMENTED : DO IT NOW!" )


#endif
