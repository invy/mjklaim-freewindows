#include "MainWindow.hpp"

#include <QTabWidget>

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
		
		connect_signals();

	}


	MainWindow::~MainWindow()
	{

	}


	void MainWindow::on_project_open( const core::Project& project )
	{
		setWindowTitle( tr("Art Of Sequence : ") + QString::fromStdString( project.name() ) );

		// TEMPORARY
		StoryPathView* storypath1 = new StoryPathView;
		StoryPathView* storypath2 = new StoryPathView;
		add_storypath( *storypath1 );
		add_storypath( *storypath2 );
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
		
	}

	void MainWindow::connect_signals()
	{
		auto& context = core::Context::instance();
		connect( &context, SIGNAL(project_open(const core::Project&)), this, SLOT(on_project_open(const core::Project&)) );
	}

}
}