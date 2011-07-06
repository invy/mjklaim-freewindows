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
#include "view/CanvasView.hpp"
#include "view/StoryView.hpp"
#include "view/LogView.hpp"

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
		, m_story_view( new StoryView() )
		, m_log_view( new LogView() )
		, m_canvas_view( new CanvasView() )
	{
		m_ui->setupUi( this );
		
		setWindowTitle( tr("Art Of Sequence") );

		// setup infrastructure
		setCentralWidget( m_central_tabs.get() );

		// use default views setup 
		// TODO : add a way to get a saved view setup
		setup_views_default();
		
		// TEMPORARY :
		auto canvas_view = new CanvasView();
		add_central_widget( *canvas_view, "Canvas" );
		
		connect_signals();
	}


	MainWindow::~MainWindow()
	{

	}


	void MainWindow::on_project_open( const core::Project& project )
	{
		setWindowTitle( tr("Art Of Sequence : ") + QString::fromStdString( project.name() ) );
	}

	void MainWindow::add_central_widget( QWidget& widget, const std::string tab_label )
	{
		m_central_tabs->addTab( &widget, QString::fromStdString( tab_label ) );
	}

	void MainWindow::setup_views_default()
	{

		addDockWidget( Qt::LeftDockWidgetArea, m_project_view.get() );
		tabifyDockWidget( m_project_view.get(), m_changes_view.get() );
		tabifyDockWidget( m_project_view.get(), m_objects_view.get() );

		addDockWidget( Qt::RightDockWidgetArea, m_libraries_view.get() );
		tabifyDockWidget( m_libraries_view.get(), m_layers_view.get() );
		tabifyDockWidget( m_libraries_view.get(), m_toolbox_view.get() );

		addDockWidget( Qt::BottomDockWidgetArea, m_story_view.get() );
		tabifyDockWidget( m_story_view.get(), m_log_view.get() );

	}

	void MainWindow::connect_signals()
	{
		auto& context = core::Context::instance();
		connect( &context, SIGNAL(project_open(const core::Project&)), this, SLOT(on_project_open(const core::Project&)) );
	}

}
}