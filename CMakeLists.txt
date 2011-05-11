cmake_minimum_required( VERSION 2.8 )

project( ArtOfSequence )

# Use relative paths
# This is mostly to reduce path size for command-line limits on windows
if(WIN32)
  message( "Using relative paths (where possible) ...")
  # This seems to break Xcode projects so definitely don't enable on Apple builds
  set(CMAKE_USE_RELATIVE_PATHS true)
  set(CMAKE_SUPPRESS_REGENERATION true)
endif()

set( EXECUTABLE_OUTPUT_PATH "./Build/" )
set( LIBRARY_OUTPUT_PATH "./Build/" )


add_subdirectory( common ) # Common dependencies files
add_subdirectory( language ) # Language files
add_subdirectory( tools ) # Tools projects
add_subdirectory( players ) # Players projects
