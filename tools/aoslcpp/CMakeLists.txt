cmake_minimum_required (VERSION 2.8)

# Dependencies:

find_package( XSD )
if( NOT XSD_FOUND )
	message( SEND_ERROR "AOS Designer requires XSD library, NOT FOUND!" )
endif()

# Important directories :
set( AOSLCPP_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} )
set( AOSLCPP_INCLUDE_DIR ${AOSLCPP_ROOT_DIR}/include )

set( AOSLCPP_HEADERS_DIR ${AOSLCPP_INCLUDE_DIR}/aoslcpp )
set( AOSLCPP_SOURCE_DIR ${AOSLCPP_ROOT_DIR}/source )

set( AOSLCPP_AOSL_HEADERS_DIR ${AOSLCPP_HEADERS_DIR}/aosl )
set( AOSLCPP_AOSL_SOURCES_DIR ${AOSLCPP_SOURCE_DIR}/aosl )

set( AOSLCPP_SCRIPT_DIR script )


#--------------------------------------------
# AOSL generated files:
# Get only the generated headers...
file( GLOB_RECURSE AOSLCPP_AOSL_HEADERS 
	${AOSLCPP_AOSL_HEADERS_DIR}/*.hpp
)
file( GLOB_RECURSE AOSLCPP_AOSL_INLINES 
	${AOSLCPP_AOSL_HEADERS_DIR}/*.inl
)

# Get only the generated sources...
file( GLOB_RECURSE AOSLCPP_AOSL_SOURCES 
	${AOSLCPP_AOSL_SOURCES_DIR}/*.cpp
)

#--------------------------------------------
# AOSLCPP original (not generated) files

# headers
set( AOSLCPP_ORIGINAL_HEADERS
	${AOSLCPP_HEADERS_DIR}/aoslcpp.hpp
	${AOSLCPP_HEADERS_DIR}/common.hpp
	${AOSLCPP_HEADERS_DIR}/SequenceInterpreter.hpp
	${AOSLCPP_HEADERS_DIR}/StoryPath.hpp
)

# sources
set( AOSLCPP_ORIGINAL_SOURCES
	${AOSLCPP_SOURCE_DIR}/SequenceInterpreter.cpp
	${AOSLCPP_SOURCE_DIR}/StoryPath.cpp
)

# all original files
set( AOSLCPP_ORIGINAL_ALL_FILES
	${AOSLCPP_ORIGINAL_HEADERS}
	${AOSLCPP_ORIGINAL_SOURCES}
)


#--------------------------------------------
# verify that we did get the generated files
set( AOSLCPP_AOSL_ALL_FILES 
        ${AOSLCPP_AOSL_HEADERS} 
        ${AOSLCPP_AOSL_INLINES}
        ${AOSLCPP_AOSL_SOURCES}
    )
list( LENGTH AOSLCPP_AOSL_ALL_FILES AOSLCPP_AOSL_FILES_COUNT )

message( "Found AOSLCPP source files count = " ${AOSLCPP_AOSL_FILES_COUNT} )

if( ${AOSLCPP_AOSL_FILES_COUNT} EQUAL 0 )

	# no aosl files found! 
	message( FATAL_ERROR "Couldn't find AOSL aosl source files! Use scripts to generate the sources!" )
	
endif()

#--------------------------------------------

# Get all headers...
set( AOSLCPP_HEADERS 
	${AOSLCPP_ORIGINAL_HEADERS}
	${AOSLCPP_AOSL_HEADERS}
	${AOSLCPP_AOSL_INLINES}
)

# Get all sources...
set( AOSLCPP_SOURCES 
	${AOSLCPP_ORIGINAL_SOURCES}
	${AOSLCPP_AOSL_SOURCES}
)

# Make sure the generated code is isolated in a separate virtual folder in IDEs supporting them
source_group( aoslcpp\\aosl 		FILES ${AOSLCPP_AOSL_HEADERS}   	)
source_group( aoslcpp\\aosl\\inline FILES ${AOSLCPP_AOSL_INLINES} 		)
source_group( aoslcpp\\aosl\\source FILES ${AOSLCPP_AOSL_SOURCES} 		)
source_group( aoslcpp 				FILES ${AOSLCPP_ORIGINAL_ALL_FILES} )

# Make sure required include directories will be available for compilation
set( AOSLCPP_INCLUDE_DIRS
	${AOSLCPP_INCLUDE_DIR}
	${XSD_INCLUDE_DIR} 
	PARENT_SCOPE
)

include_directories( 
	${AOSLCPP_INCLUDE_DIR}
	${AOSLCPP_HEADERS_DIR}
	${XSD_INCLUDE_DIR} 
)


# Generate the library
add_library( aoslcpp STATIC ${AOSLCPP_SOURCES} ${AOSLCPP_HEADERS} )
target_link_libraries( aoslcpp ${XERCESC_LIBRARY} )

# Add the test projects
add_subdirectory( ./test )
