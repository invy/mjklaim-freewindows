#include "Application.hpp"

#include "view/MainWindow.hpp"
#include "core/Project.hpp"

namespace aosd
{
    Application::Application( int &argc, char **argv )
        : QApplication( argc, argv )
        , m_main_window( new view::MainWindow(NULL) )
        , m_project( new core::Project() )
    {
        m_main_window->show();
    }

    Application::~Application()
    {
    }

}