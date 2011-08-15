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

set( AOSLCPP_ALGORITHM_HEADERS_DIR ${AOSLCPP_HEADERS_DIR}/algorithm )
set( AOSLCPP_ALGORITHM_SOURCES_DIR ${AOSLCPP_SOURCE_DIR}/algorithm )

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

#### Headers 

# algorithms headers
set( AOSLCPP_ALGORITHM_HEADERS
	${AOSLCPP_ALGORITHM_HEADERS_DIR}/algorithm.hpp
	${AOSLCPP_ALGORITHM_HEADERS_DIR}/function.hpp
	${AOSLCPP_ALGORITHM_HEADERS_DIR}/find.hpp
	${AOSLCPP_ALGORITHM_HEADERS_DIR}/for_each.hpp
)

# tool types headers
set( AOSLCPP_TOOL_HEADERS
	${AOSLCPP_HEADERS_DIR}/common.hpp
	
	${AOSLCPP_HEADERS_DIR}/SequenceInterpreter.hpp
	${AOSLCPP_HEADERS_DIR}/StoryPath.hpp
	${AOSLCPP_HEADERS_DIR}/CanvasState.hpp
	${AOSLCPP_HEADERS_DIR}/NavigationState.hpp
	
)

# all original headers
set( AOSLCPP_ORIGINAL_HEADERS
	${AOSLCPP_ALGORITHM_HEADERS}
	${AOSLCPP_TOOL_HEADERS}	
)

#### Sources

# algorithm sources
set( AOSLCPP_ALGORITHM_SOURCES
	${AOSLCPP_ALGORITHM_SOURCES_DIR}/find.cpp
	${AOSLCPP_ALGORITHM_SOURCES_DIR}/for_each.cpp
)


# tool types sources
set( AOSLCPP_TOOL_SOURCES
	${AOSLCPP_SOURCE_DIR}/SequenceInterpreter.cpp
	${AOSLCPP_SOURCE_DIR}/StoryPath.cpp
	${AOSLCPP_SOURCE_DIR}/CanvasState.cpp
	${AOSLCPP_SOURCE_DIR}/NavigationState.cpp
	
)

set( AOSLCPP_ORIGINAL_SOURCES
	${AOSLCPP_ALGORITHM_SOURCES}
	${AOSLCPP_TOOL_SOURCES}
)

#### All 

# all algorithms files
set( AOSLCPP_ALGORITHM_ALL_FILES 
	${AOSLCPP_ALGORITHM_HEADERS}
	${AOSLCPP_ALGORITHM_SOURCES}
)

# all tools files
set( AOSLCPP_TOOL_ALL_FILES 
	${AOSLCPP_TOOL_HEADERS}
	${AOSLCPP_TOOL_SOURCES}
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
source_group( aoslcpp\\algorithm	FILES ${AOSLCPP_ALGORITHM_ALL_FILES})
source_group( aoslcpp 				FILES ${AOSLCPP_TOOL_ALL_FILES} 	)

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
	${UTILCPP_INCLUDE_DIR}
)


# Generate the library
add_library( aoslcpp STATIC ${AOSLCPP_SOURCES} ${AOSLCPP_HEADERS} )
target_link_libraries( aoslcpp ${XERCESC_LIBRARY} utilcpp )

# Add the test projects
add_subdirectory( ./test )
