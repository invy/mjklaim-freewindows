cmake_minimum_required( VERSION 2.8 )

# We need Qt as GUI library.
find_package( Qt4 REQUIRED )
include( ${QT_USE_FILE} )
add_definitions( ${QT_DEFINITIONS} )

#####################################################
# Sub-directories.
set( AOSDESIGNER_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} )
set( AOSDESIGNER_CORE_DIR ${AOSDESIGNER_ROOT_DIR}/core )
set( AOSDESIGNER_VIEW_DIR ${AOSDESIGNER_ROOT_DIR}/view )
set( AOSDESIGNER_RC_DIR ${AOSDESIGNER_VIEW_DIR}/rc )
set( AOSDESIGNER_UI_DIR ${AOSDESIGNER_VIEW_DIR}/ui )
set( AOSDESIGNER_DIALOG_DIR ${AOSDESIGNER_VIEW_DIR}/dialog )
set( AOSDESIGNER_VIEW_MODEL_DIR ${AOSDESIGNER_VIEW_DIR}/model )

#####################################################
# Header files.

# Application header files.
set( AOSDESIGNER_APPLICATION_HEADERS
	${AOSDESIGNER_ROOT_DIR}/Application.hpp
	${AOSDESIGNER_ROOT_DIR}/Paths.hpp
)

#-----------------------------------------------------------------

# Core objects header files.
set( AOSDESIGNER_CORE_HEADERS
	${AOSDESIGNER_CORE_DIR}/ForwardCore.hpp
	${AOSDESIGNER_CORE_DIR}/Context.hpp
	${AOSDESIGNER_CORE_DIR}/Project.hpp
	${AOSDESIGNER_CORE_DIR}/Sequence.hpp
	${AOSDESIGNER_CORE_DIR}/SequenceId.hpp
	${AOSDESIGNER_CORE_DIR}/ProjectInfos.hpp
	${AOSDESIGNER_CORE_DIR}/SequenceInfos.hpp
	${AOSDESIGNER_CORE_DIR}/EditionSession.hpp
	${AOSDESIGNER_CORE_DIR}/EditionSessionId.hpp
	${AOSDESIGNER_CORE_DIR}/Library.hpp
	${AOSDESIGNER_CORE_DIR}/Resource.hpp
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
	${AOSDESIGNER_VIEW_DIR}/Editor.hpp
	${AOSDESIGNER_VIEW_DIR}/Dialogs.hpp
	${AOSDESIGNER_VIEW_DIR}/DesignerActions.hpp
	${AOSDESIGNER_VIEW_DIR}/EditionToolView.hpp
)


# Dialog header files.
set( AOSDESIGNER_DIALOG_HEADERS
	${AOSDESIGNER_DIALOG_DIR}/WelcomeScreen.hpp
	${AOSDESIGNER_DIALOG_DIR}/NewProjectDialog.hpp
	${AOSDESIGNER_DIALOG_DIR}/NewSequenceDialog.hpp
	${AOSDESIGNER_DIALOG_DIR}/NewEditionSessionDialog.hpp
)

# View-model header files.
set( AOSDESIGNER_VIEW_MODEL_HEADERS
	${AOSDESIGNER_VIEW_MODEL_DIR}/CanvasObjectsModel.hpp
	${AOSDESIGNER_VIEW_MODEL_DIR}/CanvasLayersModel.hpp
	${AOSDESIGNER_VIEW_MODEL_DIR}/LayerObjectsModel.hpp
	${AOSDESIGNER_VIEW_MODEL_DIR}/LastChangesModel.hpp
	${AOSDESIGNER_VIEW_MODEL_DIR}/LibraryModel.hpp
	${AOSDESIGNER_VIEW_MODEL_DIR}/ModelViewBinder.hpp
)

#-----------------------------------------------------------------

# All header files.
set( AOSDESIGNER_ALL_HEADERS  
	${AOSDESIGNER_APPLICATION_HEADERS}
	${AOSDESIGNER_CORE_HEADERS}
	${AOSDESIGNER_VIEW_HEADERS}
	${AOSDESIGNER_DIALOG_HEADERS}
	${AOSDESIGNER_VIEW_MODEL_HEADERS}
)

# Headers that depends on QObject
set( AOSDESIGNER_QOBJECT_HEADERS
	${AOSDESIGNER_APPLICATION_HEADERS}
	${AOSDESIGNER_CORE_HEADERS}
	${AOSDESIGNER_VIEW_HEADERS}
	${AOSDESIGNER_DIALOG_HEADERS}
	${AOSDESIGNER_VIEW_MODEL_HEADERS}
)
 

# Header files needs to be processed by Qt's pre-processor to generate Moc files.
QT4_WRAP_CPP( AOSDESIGNER_QOBJECT_HEADERS_MOC ${AOSDESIGNER_QOBJECT_HEADERS} )

# Group generated files in the same isolated virtual directory.
source_group( generated\\moc FILES ${AOSDESIGNER_QOBJECT_HEADERS_MOC} )


#####################################################
# Source files.

# Application source files.
set( AOSDESIGNER_APPLICATION_SOURCES
	${AOSDESIGNER_ROOT_DIR}/main.cpp
	${AOSDESIGNER_ROOT_DIR}/Application.cpp
	${AOSDESIGNER_ROOT_DIR}/Paths.cpp
)


# Views source files.
set( AOSDESIGNER_VIEW_SOURCES 
	${AOSDESIGNER_VIEW_DIR}/ApplicationView.cpp
	${AOSDESIGNER_VIEW_DIR}/MainWindow.cpp
	${AOSDESIGNER_VIEW_DIR}/ProjectView.cpp
	${AOSDESIGNER_VIEW_DIR}/SequenceListView.cpp
	${AOSDESIGNER_VIEW_DIR}/LibrariesView.cpp
	${AOSDESIGNER_VIEW_DIR}/LogView.cpp
	${AOSDESIGNER_VIEW_DIR}/ObjectsView.cpp
	${AOSDESIGNER_VIEW_DIR}/StoryView.cpp
	${AOSDESIGNER_VIEW_DIR}/LayersView.cpp
	${AOSDESIGNER_VIEW_DIR}/ToolboxView.cpp
	${AOSDESIGNER_VIEW_DIR}/CanvasView.cpp
	${AOSDESIGNER_VIEW_DIR}/ChangesView.cpp
	${AOSDESIGNER_VIEW_DIR}/Editor.cpp
	${AOSDESIGNER_VIEW_DIR}/Dialogs.cpp
	${AOSDESIGNER_VIEW_DIR}/DesignerActions.cpp
	${AOSDESIGNER_VIEW_DIR}/EditionToolView.cpp
)


# Dialog source files.
set( AOSDESIGNER_DIALOG_SOURCES 
	${AOSDESIGNER_DIALOG_DIR}/WelcomeScreen.cpp
	${AOSDESIGNER_DIALOG_DIR}/NewProjectDialog.cpp
	${AOSDESIGNER_DIALOG_DIR}/NewSequenceDialog.cpp
	${AOSDESIGNER_DIALOG_DIR}/NewEditionSessionDialog.cpp
)


# View-model source files.
set( AOSDESIGNER_VIEW_MODEL_SOURCES 
	${AOSDESIGNER_VIEW_MODEL_DIR}/CanvasObjectsModel.cpp
	${AOSDESIGNER_VIEW_MODEL_DIR}/CanvasLayersModel.cpp
	${AOSDESIGNER_VIEW_MODEL_DIR}/LayerObjectsModel.cpp
	${AOSDESIGNER_VIEW_MODEL_DIR}/LastChangesModel.cpp
	${AOSDESIGNER_VIEW_MODEL_DIR}/LibraryModel.cpp
	${AOSDESIGNER_VIEW_MODEL_DIR}/ModelViewBinder.cpp
)

#------------------------------------------------------

# Core source files
set( AOSDESIGNER_CORE_SOURCES
	${AOSDESIGNER_CORE_DIR}/Context.cpp
	${AOSDESIGNER_CORE_DIR}/Project.cpp
	${AOSDESIGNER_CORE_DIR}/Sequence.cpp
	${AOSDESIGNER_CORE_DIR}/EditionSession.cpp
	${AOSDESIGNER_CORE_DIR}/EditionSessionId.cpp
	${AOSDESIGNER_CORE_DIR}/Library.cpp
	${AOSDESIGNER_CORE_DIR}/Resource.cpp
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
	${AOSDESIGNER_UI_DIR}/NewProjectDialog.ui
	${AOSDESIGNER_UI_DIR}/NewSequenceDialog.ui
	${AOSDESIGNER_UI_DIR}/NewEditionSessionDialog.ui
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
source_group( designer\\view\\dialog FILES ${AOSDESIGNER_DIALOG_HEADERS} ${AOSDESIGNER_DIALOG_SOURCES} )
source_group( designer\\view\\model FILES ${AOSDESIGNER_VIEW_MODEL_HEADERS} ${AOSDESIGNER_VIEW_MODEL_SOURCES} )
source_group( designer\\core FILES ${AOSDESIGNER_CORE_HEADERS} ${AOSDESIGNER_CORE_SOURCES} )
source_group( designer FILES ${AOSDESIGNER_APPLICATION_HEADERS} ${AOSDESIGNER_APPLICATION_SOURCES} )

####################################################
# Bind them all together.

# All the compiled sources.
set( AOSDESIGNER_ALL_SOURCES
	${AOSDESIGNER_CORE_SOURCES}
	${AOSDESIGNER_APPLICATION_SOURCES}
	${AOSDESIGNER_VIEW_SOURCES}
	${AOSDESIGNER_DIALOG_SOURCES}
	${AOSDESIGNER_VIEW_MODEL_SOURCES}
	${AOSDESIGNER_QOBJECT_HEADERS_MOC}
	${AOSDESIGNER_VIEW_HEADERS_UI}
	${AOSDESIGNER_VIEW_RESOURCES}
)

# All the files of the project.
set( AOSDESIGNER_ALL_FILES ${AOSDESIGNER_ALL_SOURCES} ${AOSDESIGNER_ALL_HEADERS} )

include_directories( 
	${AOSDESIGNER_ROOT_DIR} 
	${CMAKE_CURRENT_BINARY_DIR} 
	${AOSLCPP_INCLUDE_DIRS}
	${UTILCPP_INCLUDE_DIR}
)

# Make sure there is no console on windows : make Qt use it's own WinMain().
link_libraries( ${QT_LIBRARIES} )
if(WIN32)
	LINK_LIBRARIES( ${QT_QTMAIN_LIBRARY} )
endif(WIN32)

add_executable( aosdesigner WIN32 ${AOSDESIGNER_ALL_FILES} )
target_link_libraries( aosdesigner ${QT_LIBRARIES} utilcpp aoslcpp  )

set( AOSDESIGNER_BUILD_MODE "$(Configuration)" ) #until I find a cross-platform way to get the configuration...

# We need the AOSL definition file in the build directory
add_custom_command( 
	TARGET aosdesigner 
	POST_BUILD 
	COMMAND ${CMAKE_COMMAND} -E copy ${AOSL_XSD_FILE} ${BUILD_DIR}/${AOSDESIGNER_BUILD_MODE} 
) 
