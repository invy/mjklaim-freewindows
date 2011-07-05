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
	{
		m_ui->setupUi( this );
		
		setWindowTitle( tr("Art Of Sequence") );

		setCentralWidget( m_central_tabs.get() );

		auto project_view = new ProjectView();
		addDockWidget( Qt::LeftDockWidgetArea, project_view );
		tabifyDockWidget( project_view, new ChangesView() );
		tabifyDockWidget( project_view, new ObjectsView() );
		
		auto libraries_view = new LibrariesView();
		addDockWidget( Qt::RightDockWidgetArea, libraries_view );
		tabifyDockWidget( libraries_view, new LayersView() );
		tabifyDockWidget( libraries_view, new ToolboxView() );
		
		auto story_view = new StoryView();
		addDockWidget( Qt::BottomDockWidgetArea, story_view );
		tabifyDockWidget( story_view, new LogView() );

		
		auto canvas_view = new CanvasView();
		add_central_widget( *canvas_view, "Canvas" );
		
		auto& context = core::Context::instance();
		connect( &context, SIGNAL(project_open(const core::Project&)), this, SLOT(on_project_open(const core::Project&)) );

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

}
}