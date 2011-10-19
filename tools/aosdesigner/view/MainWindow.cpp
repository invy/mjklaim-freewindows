#include "MainWindow.hpp"

#include <QTabWidget>
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
		, m_central_tabs( new QTabWidget() )
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
		setCentralWidget( m_central_tabs.get() );

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
			add_editor( std::unique_ptr<Editor>( new Editor( edition_session ) ) );
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

		clear_tabs();

	}



	void MainWindow::add_editor( std::unique_ptr<Editor>&& editor )
	{
		m_editors.push_back( std::move( editor ) );

		const QString tab_title = m_editors.back()->title();
		m_central_tabs->addTab( m_editors.back().get(), tab_title );

		m_central_tabs->setCurrentIndex( m_central_tabs->count() - 1 );
	}


	void MainWindow::remove_editor( const core::EditionSessionId& edition_session_id )
	{
		auto editor_it = std::find_if( begin(m_editors), end(m_editors), [&]( const std::unique_ptr<Editor>& editor )
		{
			return editor->session_id() == edition_session_id;
		});

		if( editor_it != end(m_editors) )
		{
			auto& editor = *editor_it;
			m_central_tabs->removeTab( m_central_tabs->indexOf( editor.get() ) );
			
			m_editors.erase( editor_it );
		}
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

		clear_tabs();
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


	void MainWindow::clear_tabs()
	{
		m_central_tabs->clear();
		m_editors.clear();
	}

	void MainWindow::create_menus()
	{
		m_designer_actions.setup_menubar( *menuBar() );

	}

	void MainWindow::react_edition_session_begin( const core::EditionSession& edition_session )
	{
		add_editor( std::unique_ptr<Editor>( new Editor( edition_session ) ) );
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

	void MainWindow::select_editor( const core::EditionSessionId& session_id )
	{
		auto find_it = std::find_if( begin(m_editors), end(m_editors), [&]( const std::unique_ptr<Editor>& editor )
		{
			return editor->session_id() == session_id;
		});

		if( find_it != m_editors.end() )
		{
			Editor& editor = **find_it;
			m_central_tabs->setCurrentIndex( m_central_tabs->indexOf( &editor ) );
		}
	}


}
}