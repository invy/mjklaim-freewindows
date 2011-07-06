#include "MainWindow.hpp"

#include <QTabWidget>
#include <QKeyEvent>

#include "ui_MainWindow.h"

#include "core/Context.hpp"
#include "core/Project.hpp"
#include "view/ProjectView.hpp"
#include "view/LibrariesView.hpp"
#include "view/ChangesView.hpp"
#include "view/ObjectsView.hpp"
#include "view/LayersView.hpp"
#include "view/ToolboxView.hpp"
#include "view/LogView.hpp"
#include "view/StoryPathView.hpp"

namespace aosd
{
namespace view
{

	MainWindow::MainWindow( QWidget* parent )
		: QMainWindow( parent )
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

		// setup infrastructure
		setCentralWidget( m_central_tabs.get() );

		// use default views setup 
		// TODO : add a way to get a saved view setup
		setup_views_default();

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

	}


	void MainWindow::add_storypath( StoryPathView& storypath )
	{
		// TEMPORARY :
		static unsigned long next_idx = 0;

		m_central_tabs->addTab( &storypath, QString( "story path %1" ).arg(++next_idx) );
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
	}

	void MainWindow::open_edition()
	{
		m_project_view->setVisible(true);
		m_changes_view->setVisible(true);
		m_objects_view->setVisible(true);
		m_libraries_view->setVisible(true);
		m_layers_view->setVisible(true);
		m_toolbox_view->setVisible(true);

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

		m_project_view->setVisible(false);
		m_changes_view->setVisible(false);
		m_objects_view->setVisible(false);
		m_libraries_view->setVisible(false);
		m_layers_view->setVisible(false);
		m_toolbox_view->setVisible(false);

		m_project_view->setEnabled(false);
		m_changes_view->setEnabled(false);
		m_objects_view->setEnabled(false);
		m_libraries_view->setEnabled(false);
		m_layers_view->setEnabled(false);
		m_toolbox_view->setEnabled(false);
	}

	void MainWindow::keyPressEvent( QKeyEvent* e )
	{
		assert( e );
		
		// THIS IS FOR TEST
		if( e->key() == Qt::Key_O && !is_edition_mode() )
		{
			open_edition();
		}
		else
		{
			if( e->key() == Qt::Key_C && is_edition_mode() )
			{
				close_edition();
			}
		}

		// END OF THE TEST

	}

}
}