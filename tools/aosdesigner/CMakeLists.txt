cmake_minimum_required( VERSION 2.8 )

add_subdirectory( core )
add_subdirectory( view )


set( AOSDESIGNER_SOURCES
    main.cpp
)


add_executable( aosdesigner ${AOSDESIGNER_SOURCES} )
target_link_libraries( aosdesigner 
    aosd_core 
    aosd_view 
)
