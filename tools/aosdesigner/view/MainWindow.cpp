#include "MainWindow.hpp"

#include "ui_MainWindow.h"

#include "core/Context.hpp"
#include "core/Project.hpp"
#include "view/ProjectView.hpp"

namespace aosd
{
namespace view
{

    MainWindow::MainWindow( QWidget *parent )
        : QMainWindow( parent )
        , m_ui( new Ui::MainWindow )
    {
        m_ui->setupUi( this );
        
        setWindowTitle( tr("Art Of Sequence") );

        addDockWidget( Qt::LeftDockWidgetArea, new ProjectView() );
        
        auto& context = core::Context::instance();
        connect( &context, SIGNAL(project_open(const core::Project&)), this, SLOT(on_project_open(const core::Project&)) );

    }

    void MainWindow::on_project_open( const core::Project& project )
    {
        setWindowTitle( tr("Art Of Sequence : ") + QString::fromStdString( project.name() ) );
    }

}
}