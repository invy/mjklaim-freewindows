#include "Application.hpp"

#include "view/MainWindow.hpp"
#include "core/Sequence.hpp"

namespace aosd
{
    Application::Application( int &argc, char **argv )
        : QApplication( argc, argv )
        , m_main_window( new view::MainWindow(NULL) )
    {
        m_main_window->show();
    }

}