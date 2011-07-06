#include "Application.hpp"

#include "core/Context.hpp"
#include "view/MainWindow.hpp"
#include "view/WelcomeScreen.hpp"


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
		show_welcome(); // TODO : replace this by entering a state machine
		m_main_window->open_edition();
	}

	Application::~Application()
	{
		
	}


	void Application::show_welcome()
	{
		
		auto welcome_screen = new view::WelcomeScreen();
		welcome_screen->exec();
	}

}