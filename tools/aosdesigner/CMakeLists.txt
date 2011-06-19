cmake_minimum_required( VERSION 2.8 )

# We need Qt as GUI library.
find_package( Qt4 REQUIRED )
include( ${QT_USE_FILE} )
add_definitions( ${QT_DEFINITIONS} )

#####################################################
# Sub-directories.
set( AOSD_DIR ${CMAKE_CURRENT_SOURCE_DIR} )
set( AOSD_CORE_DIR ${AOSD_DIR}/core )
set( AOSD_VIEW_DIR ${AOSD_DIR}/view )
set( AOSD_UTIL_DIR ${AOSD_DIR}/util )
set( AOSD_RC_DIR ${AOSD_VIEW_DIR}/rc )
set( AOSD_UI_DIR ${AOSD_VIEW_DIR}/ui )

#####################################################
# Header files.

# Application header files.
set( AOSD_APPLICATION_HEADERS
    Application.hpp
)

#-----------------------------------------------------------------

# Core objects header files.
set( AOSD_CORE_HEADERS
    ${AOSD_CORE_DIR}/Context.hpp
    ${AOSD_CORE_DIR}/Project.hpp
    ${AOSD_CORE_DIR}/Sequence.hpp
)

#-----------------------------------------------------------------

# Views header files.
set( AOSD_VIEW_HEADERS
    ${AOSD_VIEW_DIR}/MainWindow.hpp
    ${AOSD_VIEW_DIR}/ProjectView.hpp
    ${AOSD_VIEW_DIR}/SequenceListView.hpp
    ${AOSD_VIEW_DIR}/LibrariesView.hpp
    ${AOSD_VIEW_DIR}/ChangesView.hpp
    ${AOSD_VIEW_DIR}/ObjectsView.hpp
    ${AOSD_VIEW_DIR}/LayersView.hpp
    ${AOSD_VIEW_DIR}/ToolboxView.hpp
    ${AOSD_VIEW_DIR}/ThreadView.hpp
    ${AOSD_VIEW_DIR}/CanvasView.hpp
)


#-----------------------------------------------------------------

# Utility header files.
set( AOSD_UTIL_HEADERS
    ${AOSD_UTIL_DIR}/Singleton.hpp
)


#-----------------------------------------------------------------

# All header files.
set( AOSD_ALL_HEADERS  
    ${AOSD_APPLICATION_HEADERS} 
    ${AOSD_CORE_HEADERS}
    ${AOSD_VIEW_HEADERS}
    ${AOSD_UTIL_HEADERS}
)
 

# Header files needs to be processed by Qt's pre-processor to generate Moc files.
QT4_WRAP_CPP( AOSD_VIEW_HEADERS_MOC ${AOSD_ALL_HEADERS} )

# Group generated files in the same isolated virtual directory.
source_group( view\\generated\\moc FILES ${AOSD_VIEW_HEADERS_MOC} )


#####################################################
# Source files.

# Application source files.
set( AOSD_APPLICATION_SOURCES
    main.cpp
    Application.cpp
)

# Views source files.
set( AOSD_VIEW_SOURCES 
    ${AOSD_VIEW_DIR}/MainWindow.cpp
    ${AOSD_VIEW_DIR}/ProjectView.cpp
    ${AOSD_VIEW_DIR}/SequenceListView.cpp
)

#------------------------------------------------------

# Core source files
set( AOSD_CORE_SOURCES
    ${AOSD_CORE_DIR}/Context.cpp
    ${AOSD_CORE_DIR}/Project.cpp
    ${AOSD_CORE_DIR}/Sequence.cpp
    
)

#-----------------------------------------------------------------

# Utility source files.
set( AOSD_UTIL_SOURCES
    
)

#------------------------------------------------------



#####################################################
# Resource files.

set( AOSD_VIEW_RC

)

# RC files need to be processed by Qt wrapper to generate RC headers.
QT4_ADD_RESOURCES( AOSD_VIEW_RESOURCES ${AOSD_VIEW_RC} )

# RC files are isolated in a separate virtual directory.
source_group( view\\rc FILES ${AOSD_VIEW_RESOURCES} )

# Group generated files in the same isolated virtual directory.
source_group( view\\generated\\rc FILES ${AOSD_VIEW_RESOURCES} )

#####################################################
# UI files

set( AOSD_VIEW_UI
    ${AOSD_UI_DIR}/MainWindow.ui
)

# UI files need to be processed by Qt wrapper to generate UI headers.
QT4_WRAP_UI( AOSD_VIEW_HEADERS_UI ${AOSD_VIEW_UI} )

# Group all ui files in the same virtual directory.
source_group( view\\ui FILES ${AOSD_VIEW_UI} )
# Group generated files in the same isolated virtual directory.
source_group( view\\generated\\ui FILES ${AOSD_VIEW_HEADERS_UI} )

###################################################

# Additional groups
source_group( view FILES ${AOSD_VIEW_HEADERS} ${AOSD_VIEW_SOURCES} )
source_group( core FILES ${AOSD_CORE_HEADERS} ${AOSD_CORE_SOURCES} )
source_group( util FILES ${AOSD_UTIL_HEADERS} ${AOSD_UTIL_SOURCES} )
source_group( "" FILES ${AOSD_APPLICATION_HEADERS} ${AOSD_APPLICATION_SOURCES} )

####################################################
# Bind them all together.

# All the compiled sources.
set( AOSD_ALL_SOURCES
    ${AOSD_CORE_SOURCES}
    ${AOSD_APPLICATION_SOURCES}
    ${AOSD_VIEW_SOURCES}
    ${AOSD_VIEW_HEADERS_MOC}
    ${AOSD_VIEW_HEADERS_UI}
    ${AOSD_UTIL_SOURCES}
)

# All the files of the project.
set( AOSD_ALL_FILES ${AOSD_ALL_SOURCES} ${AOSD_ALL_HEADERS} )

add_executable( aosdesigner ${AOSD_ALL_FILES} )

target_link_libraries( aosdesigner ${QT_LIBRARIES} )

include_directories( ${AOSD_DIR} ${CMAKE_CURRENT_BINARY_DIR} )