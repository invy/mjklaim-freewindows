cmake_minimum_required( VERSION 2.8 )

# We need Qt as GUI library.
find_package( Qt4 REQUIRED )
include( ${QT_USE_FILE} )
add_definitions( ${QT_DEFINITIONS} )

#####################################################
# Sub-directories.
set( AOSDESIGNER_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} )
set( AOSDESIGNER_CORE_DIR ${AOSDESIGNER_ROOT_DIR}/core )
set( AOSDESIGNER_STATE_DIR ${AOSDESIGNER_ROOT_DIR}/state )
set( AOSDESIGNER_VIEW_DIR ${AOSDESIGNER_ROOT_DIR}/view )
set( AOSDESIGNER_UTIL_DIR ${AOSDESIGNER_ROOT_DIR}/util )
set( AOSDESIGNER_RC_DIR ${AOSDESIGNER_VIEW_DIR}/rc )
set( AOSDESIGNER_UI_DIR ${AOSDESIGNER_VIEW_DIR}/ui )

#####################################################
# Header files.

# Application header files.
set( AOSDESIGNER_APPLICATION_HEADERS
    Application.hpp
)

#-----------------------------------------------------------------

# Core objects header files.
set( AOSDESIGNER_CORE_HEADERS
	${AOSDESIGNER_CORE_DIR}/ForwardCore.hpp
    ${AOSDESIGNER_CORE_DIR}/Context.hpp
    ${AOSDESIGNER_CORE_DIR}/Project.hpp
    ${AOSDESIGNER_CORE_DIR}/Sequence.hpp
)

#-----------------------------------------------------------------

# States header files.
set( AOSDESIGNER_STATE_HEADERS
	${AOSDESIGNER_STATE_DIR}/Events.hpp
	${AOSDESIGNER_STATE_DIR}/DesignerStateMachine.hpp
	${AOSDESIGNER_STATE_DIR}/Welcome.hpp
	${AOSDESIGNER_STATE_DIR}/EditingProject.hpp
	${AOSDESIGNER_STATE_DIR}/Idle.hpp
)

#-----------------------------------------------------------------

# Views header files.
set( AOSDESIGNER_VIEW_HEADERS
	${AOSDESIGNER_VIEW_DIR}/ForwardView.hpp
	${AOSDESIGNER_VIEW_DIR}/ApplicationView.hpp
    ${AOSDESIGNER_VIEW_DIR}/MainWindow.hpp
    ${AOSDESIGNER_VIEW_DIR}/ProjectView.hpp
    ${AOSDESIGNER_VIEW_DIR}/SequenceListView.hpp
    ${AOSDESIGNER_VIEW_DIR}/LibrariesView.hpp
    ${AOSDESIGNER_VIEW_DIR}/ChangesView.hpp
    ${AOSDESIGNER_VIEW_DIR}/ObjectsView.hpp
    ${AOSDESIGNER_VIEW_DIR}/LayersView.hpp
    ${AOSDESIGNER_VIEW_DIR}/ToolboxView.hpp
    ${AOSDESIGNER_VIEW_DIR}/StoryView.hpp
	${AOSDESIGNER_VIEW_DIR}/LogView.hpp
    ${AOSDESIGNER_VIEW_DIR}/CanvasView.hpp
	${AOSDESIGNER_VIEW_DIR}/StoryPathView.hpp
	${AOSDESIGNER_VIEW_DIR}/WelcomeScreen.hpp
	${AOSDESIGNER_VIEW_DIR}/Dialogs.hpp
	${AOSDESIGNER_VIEW_DIR}/ActionsProvider.hpp
	${AOSDESIGNER_VIEW_DIR}/DesignerActions.hpp
)


#-----------------------------------------------------------------

# Utility header files.
set( AOSDESIGNER_UTIL_HEADERS
    ${AOSDESIGNER_UTIL_DIR}/Singleton.hpp
)


#-----------------------------------------------------------------

# All header files.
set( AOSDESIGNER_ALL_HEADERS  
    ${AOSDESIGNER_APPLICATION_HEADERS}
    ${AOSDESIGNER_CORE_HEADERS}
	${AOSDESIGNER_STATE_HEADERS}
    ${AOSDESIGNER_VIEW_HEADERS}
    ${AOSDESIGNER_UTIL_HEADERS}
)

# Headers that depends on QObject
set( AOSDESIGNER_QOBJECT_HEADERS
	${AOSDESIGNER_APPLICATION_HEADERS}
	${AOSDESIGNER_CORE_HEADERS}
	${AOSDESIGNER_VIEW_HEADERS}
)
 

# Header files needs to be processed by Qt's pre-processor to generate Moc files.
QT4_WRAP_CPP( AOSDESIGNER_QOBJECT_HEADERS_MOC ${AOSDESIGNER_QOBJECT_HEADERS} )

# Group generated files in the same isolated virtual directory.
source_group( generated\\moc FILES ${AOSDESIGNER_QOBJECT_HEADERS_MOC} )


#####################################################
# Source files.

# Application source files.
set( AOSDESIGNER_APPLICATION_SOURCES
    main.cpp
    Application.cpp
)

# Views source files.
set( AOSDESIGNER_VIEW_SOURCES 
    ${AOSDESIGNER_VIEW_DIR}/ApplicationView.cpp
	${AOSDESIGNER_VIEW_DIR}/MainWindow.cpp
    ${AOSDESIGNER_VIEW_DIR}/ProjectView.cpp
    ${AOSDESIGNER_VIEW_DIR}/SequenceListView.cpp
	${AOSDESIGNER_VIEW_DIR}/StoryPathView.cpp
	${AOSDESIGNER_VIEW_DIR}/WelcomeScreen.cpp
	${AOSDESIGNER_VIEW_DIR}/Dialogs.cpp
	${AOSDESIGNER_VIEW_DIR}/DesignerActions.cpp
)

#------------------------------------------------------

# Core source files
set( AOSDESIGNER_CORE_SOURCES
    ${AOSDESIGNER_CORE_DIR}/Context.cpp
    ${AOSDESIGNER_CORE_DIR}/Project.cpp
    ${AOSDESIGNER_CORE_DIR}/Sequence.cpp
    
)

#------------------------------------------------------

# States source files
set( AOSDESIGNER_STATE_SOURCES
	${AOSDESIGNER_STATE_DIR}/DesignerStateMachine.cpp
	${AOSDESIGNER_STATE_DIR}/EditingProject.cpp
	${AOSDESIGNER_STATE_DIR}/Welcome.cpp
	${AOSDESIGNER_STATE_DIR}/Idle.cpp
)

#-----------------------------------------------------------------

# Utility source files.
set( AOSDESIGNER_UTIL_SOURCES
    
)

#------------------------------------------------------



#####################################################
# Resource files.

set( AOSDESIGNER_VIEW_RC
	${AOSDESIGNER_RC_DIR}/AOSDesigner.qrc
)

# RC files need to be processed by Qt wrapper to generate RC headers.
QT4_ADD_RESOURCES( AOSDESIGNER_VIEW_RESOURCES ${AOSDESIGNER_VIEW_RC} )

# RC files are isolated in a separate virtual directory.
source_group( designer\\view\\rc FILES ${AOSDESIGNER_VIEW_RC} )

# Group generated files in the same isolated virtual directory.
source_group( designer\\view\\generated\\rc FILES ${AOSDESIGNER_VIEW_RESOURCES} )

#####################################################
# UI files

set( AOSDESIGNER_VIEW_UI
    ${AOSDESIGNER_UI_DIR}/MainWindow.ui
	${AOSDESIGNER_UI_DIR}/WelcomeScreen.ui
)

# UI files need to be processed by Qt wrapper to generate UI headers.
QT4_WRAP_UI( AOSDESIGNER_VIEW_HEADERS_UI ${AOSDESIGNER_VIEW_UI} )

# Group all ui files in the same virtual directory.
source_group( designer\\view\\ui FILES ${AOSDESIGNER_VIEW_UI} )
# Group generated files in the same isolated virtual directory.
source_group( designer\\view\\generated\\ui FILES ${AOSDESIGNER_VIEW_HEADERS_UI} )

###################################################

# Additional groups
source_group( designer\\view FILES ${AOSDESIGNER_VIEW_HEADERS} ${AOSDESIGNER_VIEW_SOURCES} )
source_group( designer\\core FILES ${AOSDESIGNER_CORE_HEADERS} ${AOSDESIGNER_CORE_SOURCES} )
source_group( designer\\state FILES ${AOSDESIGNER_STATE_HEADERS} ${AOSDESIGNER_STATE_SOURCES} )
source_group( designer\\util FILES ${AOSDESIGNER_UTIL_HEADERS} ${AOSDESIGNER_UTIL_SOURCES} )
source_group( designer FILES ${AOSDESIGNER_APPLICATION_HEADERS} ${AOSDESIGNER_APPLICATION_SOURCES} )

####################################################
# Bind them all together.

# All the compiled sources.
set( AOSDESIGNER_ALL_SOURCES
    ${AOSDESIGNER_CORE_SOURCES}
	${AOSDESIGNER_STATE_SOURCES}
    ${AOSDESIGNER_APPLICATION_SOURCES}
    ${AOSDESIGNER_VIEW_SOURCES}
    ${AOSDESIGNER_QOBJECT_HEADERS_MOC}
    ${AOSDESIGNER_VIEW_HEADERS_UI}
	${AOSDESIGNER_VIEW_RESOURCES}
    ${AOSDESIGNER_UTIL_SOURCES}
)

# All the files of the project.
set( AOSDESIGNER_ALL_FILES ${AOSDESIGNER_ALL_SOURCES} ${AOSDESIGNER_ALL_HEADERS} )

include_directories( 
	${AOSDESIGNER_ROOT_DIR} 
	${CMAKE_CURRENT_BINARY_DIR} 
	${AOSLCPP_INCLUDE_DIRS}
)

add_executable( aosdesigner ${AOSDESIGNER_ALL_FILES} )
target_link_libraries( aosdesigner ${QT_LIBRARIES} aoslcpp )
