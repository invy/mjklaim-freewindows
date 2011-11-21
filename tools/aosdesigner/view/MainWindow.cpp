#include "MainWindow.hpp"

#include <QMdiArea>
#include <QKeyEvent>

#include "ui_MainWindow.h"

#include "core/Context.hpp"
#include "core/Project.hpp"
#include "core/Sequence.hpp"
#include "core/EditionSession.hpp"
#include "view/ProjectView.hpp"
#include "view/LibrariesView.hpp"
#include "view/ChangesView.hpp"
#include "view/ObjectsView.hpp"
#include "view/LayersView.hpp"
#include "view/ToolboxView.hpp"
#include "view/LogView.hpp"
#include "view/Editor.hpp"
#include "view/DesignerActions.hpp"

namespace aosd
{
namespace view
{

	MainWindow::MainWindow()
		: QMainWindow( nullptr )
		, m_edition_mode( false )
		, m_ui( new Ui::MainWindow )
		, m_central_area( new QMdiArea() )
		, m_project_view( new ProjectView() )
		, m_changes_view( new ChangesView() )
		, m_objects_view( new ObjectsView() )
		, m_libraries_view( new LibrariesView() )
		, m_layers_view( new LayersView() )
		, m_toolbox_view( new ToolboxView() )
		, m_log_view( new LogView() )
	{
		m_ui->setupUi( this );
		
		setWindowTitle( tr("Art Of Sequence") );

		// basic infrastructure
		setCentralWidget( m_central_area.get() );

		// use default views setup 
		// TODO : add a way to get a saved view setup
		setup_views_default();
		create_menus();

		// don't allow edition without something to edit first!
		close_edition();

		connect_signals();

	}


	MainWindow::~MainWindow()
	{
		if( core::Context::instance().is_project_open() )
			core::Context::instance().close_project();
		clear_windows();
	}


	void MainWindow::react_project_open( const core::Project& project )
	{
		setWindowTitle( tr("%1 - Art Of Sequence").arg( QString::fromStdString( project.name() ), 0 ) );

		connect( &project, SIGNAL(edition_session_begin(const core::EditionSession&)), this, SLOT(react_edition_session_begin(const core::EditionSession&)) );
		connect( &project, SIGNAL(edition_session_end(const core::EditionSession&)), this, SLOT(react_edition_session_end(const core::EditionSession&)) );

		connect( &project, SIGNAL(sequence_created(const core::Sequence&)), this, SLOT(react_sequence_created(const core::Sequence&)) );
		connect( &project, SIGNAL(sequence_deleted(const core::Sequence&)), this, SLOT(react_sequence_deleted(const core::Sequence&)) );

		const auto* initial_session_selection = project.selected_edition_session();

		project.foreach_edition( [&]( const core::EditionSession& edition_session ) 
		{
			create_editor( edition_session );
		});

		if( initial_session_selection )
		{
			core::Context::instance().select_edition_session( initial_session_selection->id() );
			select_editor( initial_session_selection->id() );
		}
		
	}


	void MainWindow::react_project_closed( const core::Project& project )
	{
		setWindowTitle( tr("Art Of Sequence") );

		disconnect( &project, 0, this, 0 );

		clear_windows();

	}


	void MainWindow::setup_views_default()
	{
		// Tabs should be on the top of windows, not at the bottom
		setTabPosition( Qt::LeftDockWidgetArea, QTabWidget::North );
		setTabPosition( Qt::RightDockWidgetArea, QTabWidget::North );
		setTabPosition( Qt::BottomDockWidgetArea, QTabWidget::North );
		setTabPosition( Qt::TopDockWidgetArea, QTabWidget::North );

		addDockWidget( Qt::LeftDockWidgetArea, m_project_view.get() );
		tabifyDockWidget( m_project_view.get(), m_changes_view.get() );
		tabifyDockWidget( m_project_view.get(), m_objects_view.get() );

		addDockWidget( Qt::RightDockWidgetArea, m_libraries_view.get() );
		tabifyDockWidget( m_libraries_view.get(), m_layers_view.get() );
		tabifyDockWidget( m_libraries_view.get(), m_toolbox_view.get() );

		addDockWidget( Qt::BottomDockWidgetArea, m_log_view.get() );

	}

	void MainWindow::connect_signals()
	{
		auto& context = core::Context::instance();

		connect( &context, SIGNAL(project_open(const core::Project&)), this, SLOT(react_project_open(const core::Project&)) );
		connect( &context, SIGNAL(project_closed(const core::Project&)), this, SLOT(react_project_closed(const core::Project&)) );

	}

	void MainWindow::open_edition()
	{
		/*m_project_view->setVisible(true);
		m_changes_view->setVisible(true);
		m_objects_view->setVisible(true);
		m_libraries_view->setVisible(true);
		m_layers_view->setVisible(true);
		m_toolbox_view->setVisible(true);
		*/
		m_project_view->setEnabled(true);
		m_changes_view->setEnabled(true);
		m_objects_view->setEnabled(true);
		m_libraries_view->setEnabled(true);
		m_layers_view->setEnabled(true);
		m_toolbox_view->setEnabled(true);

		m_edition_mode = true;
	}

	void MainWindow::close_edition()
	{
		m_edition_mode = false;

		clear_windows();
		/*
		m_project_view->setVisible(false);
		m_changes_view->setVisible(false);
		m_objects_view->setVisible(false);
		m_libraries_view->setVisible(false);
		m_layers_view->setVisible(false);
		m_toolbox_view->setVisible(false);
		*/
		m_project_view->setEnabled(false);
		m_changes_view->setEnabled(false);
		m_objects_view->setEnabled(false);
		m_libraries_view->setEnabled(false);
		m_layers_view->setEnabled(false);
		m_toolbox_view->setEnabled(false);

	}


	void MainWindow::clear_windows()
	{
		// we don't want to 'close' the windows, just remove them!
		auto window_list = m_central_area->subWindowList();
		std::for_each( window_list.begin(), window_list.end(), [&]( QMdiSubWindow* window )
		{
			m_central_area->removeSubWindow( window );
		});

		m_editors.clear();

	}

	void MainWindow::create_menus()
	{
		m_designer_actions.setup_menubar( *menuBar() );

	}

	void MainWindow::react_edition_session_begin( const core::EditionSession& edition_session )
	{
		create_editor( edition_session );
	}

	void MainWindow::react_edition_session_end( const core::EditionSession& edition_session )
	{
		remove_editor( edition_session.id() );
	}

	void MainWindow::react_sequence_created( const core::Sequence& sequence )
	{
		// THINK : ?
	}

	void MainWindow::react_sequence_deleted( const core::Sequence& sequence )
	{
		UTILCPP_NOT_IMPLEMENTED_YET;
	}

	void MainWindow::select_editor( core::EditionSessionId session_id )
	{
		auto editor = find_editor( session_id );

		if( editor )
		{
			editor->setFocus();
		}
	}

	void MainWindow::create_editor( const core::EditionSession& edition_session )
	{
		add_editor( std::unique_ptr<Editor>( new Editor( edition_session ) ) );
	}

	void MainWindow::add_editor( std::unique_ptr<Editor> editor )
	{
		m_central_area->addSubWindow( editor.get() );
		
		const auto session_id = editor->session_id();
		m_editors.insert( std::make_pair( session_id, std::move(editor) ) );

		m_editors[session_id]->show();
		
	}

	void MainWindow::remove_editor( core::EditionSessionId session_id )
	{
		auto editor_it = m_editors.find( session_id );

		if( editor_it != end(m_editors) )
		{
			auto& editor = editor_it->second;
			if( editor->is_closing() ) 
			{
				// make sure that if the editor is already closing, we just let it go - qt should delete it for us
				editor_it->second.release();
			}
			else
			{
				// remove the editor without closing it
				m_central_area->removeSubWindow( editor.get() );
			}
			m_editors.erase( editor_it );
		}
		
	}

	Editor* MainWindow::find_editor( core::EditionSessionId session_id )
	{
		auto find_it = m_editors.find( session_id );

		if( find_it != end(m_editors) )
			return find_it->second.get();
		else 
			return nullptr;
	}

	void MainWindow::closeEvent( QCloseEvent* closeEvent )
	{
		// TODO : here ask the user about closing the project without saving

		QMainWindow::closeEvent( closeEvent );
	}


}
}