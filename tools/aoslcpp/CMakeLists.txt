cmake_minimum_required (VERSION 2.8)

# Dependencies:

find_package( XSD )
if( NOT XSD_FOUND )
	message( SEND_ERROR "AOS Designer requires XSD library, NOT FOUND!" )
endif()

# Important directories :
set( AOSLCPP_INCLUDE_DIR include )
set( AOSLCPP_SOURCE_DIR source )
set( AOSLCPP_HEADER_LANG_DIR ${AOSLCPP_INCLUDE_DIR}/aoslcpp/aosl )
set( AOSLCPP_SOURCE_LANG_DIR ${AOSLCPP_SOURCE_DIR}/aosl )
set( AOSLCPP_SCRIPT_DIR script )


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

message( "Found AOSLCPP source files count = " ${AOSLCPP_LANG_FILES_COUNT} )

if( ${AOSLCPP_LANG_FILES_COUNT} EQUAL 0 )

	# no lang files found! 
	message( FATAL_ERROR "Couldn't find AOSL language source files! Use scripts to generate the sources!" )
	
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

# Make sure required include directories will be available for compilation
include_directories( 
	${AOSLCPP_INCLUDE_DIR} 
	${XSD_INCLUDE_DIR} 
)

# Generate the library
add_library( aoslcpp SHARED ${AOSLCPP_SOURCES} ${AOSLCPP_HEADERS} )
target_link_libraries( aoslcpp ${XERCESC_LIBRARY} )

# Add the test projects
add_subdirectory( ./test )
