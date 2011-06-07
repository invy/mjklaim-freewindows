#include "Application.hpp"

#include "core/Context.hpp"
#include "view/MainWindow.hpp"


namespace aosd
{
    Application::Application( int &argc, char **argv )
        : QApplication( argc, argv )
        , m_context( new core::Context() )
        , m_main_window( new view::MainWindow( nullptr ) )
    {
        using namespace aosd::core;
        
        // temporary : create an empty project
        Context::instance().new_project();

        m_main_window->show();
    }

    Application::~Application()
    {
        using namespace aosd::core;

        
    }

}