cmake_minimum_required( VERSION 2.8 )

# We need Qt as GUI library.
find_package( Qt4 REQUIRED )
INCLUDE( ${QT_USE_FILE} )
ADD_DEFINITIONS( ${QT_DEFINITIONS} )

#####################################################
# Sub-directories.

# set( AOSD_RC_DIR ${} )
# set( AOSD_UI_DIR ${} )

#####################################################
# Header files.

# Application header files.
set( AOSD_VIEW_APPLICATION_HEADERS
    Application.hpp
    MainWindow.hpp
)

# Views in the application header files.
set( AOSD_VIEW_HEADERS
    ${AOSD_VIEW_APPLICATION_HEADERS}
    
)

# Header files needs to be processed by Qt's pre-processor to generate Moc files.
QT4_WRAP_CPP( AOSD_VIEW_HEADERS_MOC ${AOSD_VIEW_HEADERS} )


#####################################################
# Source files.

# Application source files.
set( AOSD_VIEW_APPLICATION_SOURCES
    Application.cpp
    MainWindow.cpp
)

# Views in the application source files.
set( AOSD_VIEW_SOURCES 
    ${AOSD_VIEW_APPLICATION_SOURCES}
)

#####################################################
# Resource files.

set( AOSD_VIEW_RC

)

# RC files need to be processed by Qt wrapper to generate RC headers.
QT4_ADD_RESOURCES( AOSD_VIEW_RESOURCES ${AOSD_VIEW_RC} )

# RC files are isolated in a separate virtual directory.
source_group( rc AOSD_VIEW_RESOURCES )

#####################################################
# UI files

set( AOSD_VIEW_UI

)

# UI files need to be processed by Qt wrapper to generate UI headers.
QT4_WRAP_UI( AOSD_VIEW_HEADERS_UI ${AOSD_VIEW_UI} )

# Group all ui files in the same virtual directory.
source_group( ui AOSD_VIEW_UI )

####################################################
# Bind them all together.

# All the compiled sources.
set( AOSD_ALL_SOURCES 
    ${AOSD_VIEW_SOURCES}
    ${AOSD_VIEW_HEADERS_MOC}
    ${AOSD_VIEW_HEADERS_UI}
)

# Group generated files in the same isolated virtual directory.
source_group( generated FILES 
    ${AOSD_VIEW_HEADERS_MOC} 
    ${AOSD_VIEW_HEADERS_UI}
)

# All the files of the project.
set( AOSD_ALL_FILES ${AOSD_ALL_SOURCES} ${AOSD_VIEW_HEADERS} )

add_library( aos_view ${AOSD_ALL_FILES} )

target_link_libraries( aos_view ${QT_LIBRARIES} )

include_directories( ${CMAKE_CURRENT_BINARY_DIR} )