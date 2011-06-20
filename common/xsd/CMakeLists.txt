cmake_minimum_required( VERSION 2.8 )

# libxsd : xsdlibrary + xerces sources and headers

###############################################
# First, include all the xsd files - it's an header-only library
set( XSD_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR} )

# Get all headers...
file( GLOB_RECURSE XSD_HEADERS *.hxx *.ixx )

source_group( xsd FILES ${XSD_HEADERS} )

# Get all sources...
file( GLOB_RECURSE XSD_SOURCES *.cxx )

# Make sure those files are interpreted as C++ sources
set_source_files_properties( ${XSD_SOURCES} PROPERTIES LANGUAGE CXX )

# We need to have access to all the headers
include_directories( ${XSD_INCLUDE_DIR} )

message( "XSD include dir : " ${XSD_INCLUDE_DIR} )

###############################################
# Now we need also Xerces sources!
set( XERCES_SOURCE_DIR ${XERCES_SOURCE_DIR}/../xerces/src )
set( XERCES_INCLUDE_DIR ${XERCES_SOURCE_DIR} )

# Headers 
file( GLOB_RECURSE XERCES_HEADERS ${XERCES_INCLUDE_DIR}/*.h* )

source_group( xerces\\headers FILES ${XERCES_HEADERS} )

# Sources
file( GLOB_RECURSE XERCES_SOURCES_CPP ${XERCES_SOURCE_DIR}/*.cpp )
file( GLOB_RECURSE XERCES_SOURCES_C ${XERCES_SOURCE_DIR}/*.c )

set( XERCES_SOURCES ${XERCES_SOURCES_CPP} ${XERCES_SOURCES_C} )

source_group( xerces\\sources FILES ${XERCES_SOURCES} )

# We need to have access to all the headers
include_directories( ${XERCES_INCLUDE_DIR} )

#add_definitions( XERCES_STATIC_LIBRARY )

message( "Xerces include dir : " ${XERCES_INCLUDE_DIR} )

###############################################

# Compile all together
add_library( libxsd STATIC 
    ${XSD_HEADERS} ${XSD_SOURCES} 
    ${XERCES_HEADERS} ${XERCES_SOURCES}
)

set_target_properties( libxsd PROPERTIES LINKER_LANGUAGE CXX )
