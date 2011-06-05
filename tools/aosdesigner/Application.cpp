#include "Application.hpp"

#include "core/Context.hpp"
#include "view/MainWindow.hpp"


namespace aosd
{
    Application::Application( int &argc, char **argv )
        : QApplication( argc, argv )
        , m_main_window( new view::MainWindow( nullptr ) )
    {
        using namespace aosd::core;
        Context::create();

        // temporary : create an empty project
        Context::instance().new_project();

        m_main_window->show();
    }

    Application::~Application()
    {
        using namespace aosd::core;

        Context::destroy();
    }

}