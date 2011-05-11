cmake_minimum_required( VERSION 2.8 )

set( XSD_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR} )

message( "LibXSD is in " ${XSD_INCLUDE_DIR} )

# Get all headers...
file( GLOB_RECURSE XSD_HEADERS 
	*.hxx
	*.ixx
)

# Get all sources...
file( GLOB_RECURSE XSD_SOURCES 
	*.cxx
)

set_source_files_properties( ${XSD_HEADERS} ${XSD_SOURCES} PROPERTIES LANGUAGE CXX )

include_directories( ${XSD_INCLUDE_DIR} )

add_custom_target( libxsd SOURCES ${XSD_HEADERS} ${XSD_SOURCES} )
