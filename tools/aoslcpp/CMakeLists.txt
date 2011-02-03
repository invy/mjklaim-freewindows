cmake_minimum_required (VERSION 2.8)
project( AOSLCPP )

# Important directories :
set( AOSLCPP_INCLUDE_DIR ./include )
set( AOSLCPP_SOURCE_DIR ./source )
set( AOSLCPP_HEADER_LANG_DIR ${AOSLCPP_INCLUDE_DIR}/aoslcpp/lang )
set( AOSLCPP_SOURCE_LANG_DIR ${AOSLCPP_SOURCE_DIR}/lang )
set( AOSLCPP_SCRIPT_DIR ./script )

#---------------------------------------------
# First, generate the sources by calling the code generator script...

execute_process( COMMAND python generate_cpp.py
				WORKING_DIRECTORY ${AOSLCPP_SCRIPT_DIR}
)

#--------------------------------------------

# Get all headers...
file( GLOB_RECURSE AOSLCPP_HEADERS 
	${AOSLCPP_INCLUDE_DIR}/*.hpp
	${AOSLCPP_INCLUDE_DIR}/*.inl
)

# Get all sources...
file( GLOB_RECURSE AOSLCPP_SOURCES 
	${AOSLCPP_SOURCE_DIR}/*.cpp
)

# Get only the generated headers...
file( GLOB_RECURSE AOSLCPP_LANG_HEADERS 
	${AOSLCPP_HEADER_LANG_DIR}/*.hpp
)
file( GLOB_RECURSE AOSLCPP_LANG_INLINES 
	${AOSLCPP_HEADER_LANG_DIR}/*.inl
)

# Get only the generated sources...
file( GLOB_RECURSE AOSLCPP_LANG_SOURCES 
	${AOSLCPP_SOURCE_LANG_DIR}/*.cpp
)

# Remove 

# Make sure the generated code is isolated in a separate virtual folder in IDEs supporting them
source_group( lang\\headers FILES ${AOSLCPP_LANG_HEADERS} )
source_group( lang\\headers\\impl FILES ${AOSLCPP_LANG_INLINES} )
source_group( lang\\sources FILES ${AOSLCPP_LANG_SOURCES} )


# Make sure include directory will be available to projects using this lib
include_directories( ${AOSLCPP_INCLUDE_DIR} )

# Generate the library
add_library( aoslcpp SHARED ${AOSLCPP_SOURCES} ${AOSLCPP_HEADERS} )

# Add the test projects
add_subdirectory( ./test )
