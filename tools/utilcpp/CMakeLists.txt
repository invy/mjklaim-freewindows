cmake_minimum_required (VERSION 2.8)

# Dependencies:
# TODO : add boost here?

# Important directories :
set( UTILCPP_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} )
set( UTILCPP_INCLUDE_DIR ${UTILCPP_ROOT_DIR}/include )

set( UTILCPP_HEADERS_DIR ${UTILCPP_INCLUDE_DIR}/utilcpp )
set( UTILCPP_SOURCE_DIR ${UTILCPP_ROOT_DIR}/sources )

#--------------------------------------------
# UTILCPP source files

# headers
set( UTILCPP_HEADERS
	${UTILCPP_HEADERS_DIR}/Assert.hpp
	${UTILCPP_HEADERS_DIR}/Log.hpp
	${UTILCPP_HEADERS_DIR}/Singleton.hpp
)

# sources
set( UTILCPP_SOURCES
	${UTILCPP_SOURCE_DIR}/Log.cpp
)

# all source files
set( UTILCPP_ALL_FILES
	${UTILCPP_HEADERS}
	${UTILCPP_SOURCES}
)

# Grouping
source_group( utilcpp FILES ${UTILCPP_ALL_FILES} )

# Make sure required include directories will be available for compilation
set( UTILCPP_INCLUDE_DIR ${UTILCPP_INCLUDE_DIR} PARENT_SCOPE )

include_directories( ${UTILCPP_INCLUDE_DIR} )


# Generate the library
add_library( utilcpp STATIC ${UTILCPP_ALL_FILES} )
