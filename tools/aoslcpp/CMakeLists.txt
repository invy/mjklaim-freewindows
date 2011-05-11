cmake_minimum_required (VERSION 2.8)

# Important directories :
set( AOSLCPP_INCLUDE_DIR include )
set( AOSLCPP_SOURCE_DIR source )
set( AOSLCPP_HEADER_LANG_DIR ${AOSLCPP_INCLUDE_DIR}/aoslcpp/lang )
set( AOSLCPP_SOURCE_LANG_DIR ${AOSLCPP_SOURCE_DIR}/lang )
set( AOSLCPP_SCRIPT_DIR script )

#--------------------------------------------
# Ask the user if he wants us to generate the source code.
option( AOSLCPP_GENERATE_AOSL_SOURCES "Turn on if you want to generate the AOSL source code." OFF )

if( AOSLCPP_GENERATE_AOSL_SOURCES ) # do we nee to generate the source code from the aosl xsd file?
	# Generate the source code from the xsd file (see the script)
	message( "Generating source code for AOSL language..." )
	execute_process( COMMAND python generate_cpp.py
					WORKING_DIRECTORY ${AOSLCPP_SCRIPT_DIR}
	)
	
endif()

#--------------------------------------------

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

#--------------------------------------------


# verify that we did get the generated files
set( AOSLCPP_LANG_ALL_FILES 
        ${AOSLCPP_LANG_HEADERS} 
        ${AOSLCPP_LANG_INLINES}
        ${AOSLCPP_LANG_SOURCES}
    )
list( LENGTH AOSLCPP_LANG_ALL_FILES AOSLCPP_LANG_FILES_COUNT )

message( "Found lang sources count = " ${AOSLCPP_LANG_FILES_COUNT} )

if( ${AOSLCPP_LANG_FILES_COUNT} EQUAL 0 )

	# no lang files found! 
	message( FATAL_ERROR "Couldn't find AOSL language source files! Use option AOSLCPP_GENERATE_AOSL_SOURCES to generate the sources!" )
	
endif()

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
