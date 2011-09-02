#include "MainWindow.hpp"

#include <QTabWidget>
#include <QKeyEvent>

#include "ui_MainWindow.h"

#include "core/Context.hpp"
#include "core/Project.hpp"
#include "core/Sequence.hpp"
#include "view/ProjectView.hpp"
#include "view/LibrariesView.hpp"
#include "view/ChangesView.hpp"
#include "view/ObjectsView.hpp"
#include "view/LayersView.hpp"
#include "view/ToolboxView.hpp"
#include "view/LogView.hpp"
#include "view/StoryPathView.hpp"
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
		, m_designer_actions( new DesignerActions() )
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


	void MainWindow::on_project_open( const core::Project& project )
	{
		setWindowTitle( tr("Art Of Sequence : ") + QString::fromStdString( project.name() ) );

		connect( &project, SIGNAL(storywalk_begin(const core::StoryWalker&)), this, SLOT(on_storywalk_begin(const core::StoryWalker&)) );
		connect( &project, SIGNAL(storywalk_end(const core::StoryWalker&)), this, SLOT(on_storywalk_end(const core::StoryWalker&)) );

		connect( &project, SIGNAL(sequence_created(const core::Sequence&)), this, SLOT(on_sequence_created(const core::Sequence&)) );
		connect( &project, SIGNAL(sequence_deleted(const core::Sequence&)), this, SLOT(on_sequence_deleted(const core::Sequence&)) );

	}


	void MainWindow::on_project_closed( const core::Project& project )
	{
		setWindowTitle( tr("Art Of Sequence") );
	}



	void MainWindow::add_storypath( std::unique_ptr<StoryPathView>&& storypath )
	{
		m_central_tabs->addTab( storypath.release(), "NO NAME : MAKE IT WORK NOW!" );
	}


	void MainWindow::setup_views_default()
	{
		addDockWidget( Qt::LeftDockWidgetArea, m_project_view.get() );
		tabifyDockWidget( m_project_view.get(), m_changes_view.get() );
		tabifyDockWidget( m_project_view.get(), m_objects_view.get() );

		addDockWidget( Qt::RightDockWidgetArea, m_libraries_view.get() );
		tabifyDockWidget( m_libraries_view.get(), m_layers_view.get() );
		tabifyDockWidget( m_libraries_view.get(), m_toolbox_view.get() );

		addDockWidget( Qt::BottomDockWidgetArea, m_log_view.get() );
		m_log_view->setVisible(false); // don't display it if not needed by the user
		
	}

	void MainWindow::connect_signals()
	{
		auto& context = core::Context::instance();

		connect( &context, SIGNAL(project_open(const core::Project&)), this, SLOT(on_project_open(const core::Project&)) );
		connect( &context, SIGNAL(project_closed(const core::Project&)), this, SLOT(on_project_closed(const core::Project&)) );

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
	}

	void MainWindow::create_menus()
	{
		// THINK : maybe move all that in designer_actions ?
		auto menu_designer = menuBar()->addMenu(tr("&Designer"));
		
		menu_designer->addAction( &m_designer_actions->new_project() );
		menu_designer->addAction( &m_designer_actions->open_project() );
		menu_designer->addAction( &m_designer_actions->close_project() );
		menu_designer->addSeparator();
		menu_designer->addAction( &m_designer_actions->quit() );

	}

	void MainWindow::on_storywalk_begin( const core::StoryWalker& storywalker )
	{
		add_storypath( std::unique_ptr<StoryPathView>( new StoryPathView( storywalker ) ) );
	}

	void MainWindow::on_storywalk_end( const core::StoryWalker& storywalker )
	{
		UTILCPP_NOT_IMPLEMENTED_YET;
	}

	void MainWindow::on_sequence_created( const core::Sequence& sequence )
	{
		// NOT SURE BUT OH WELL : we need to open a new story path
		UTILCPP_NOT_IMPLEMENTED_YET;
	}

	void MainWindow::on_sequence_deleted( const core::Sequence& sequence )
	{
		// we need to remove all the storypaths from the central view.
		UTILCPP_NOT_IMPLEMENTED_YET;
	}


}
}