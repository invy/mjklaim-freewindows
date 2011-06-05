#include "MainWindow.hpp"

#include "ui_MainWindow.h"

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
        
        addDockWidget( Qt::LeftDockWidgetArea, new ProjectView() );

    }

}
}