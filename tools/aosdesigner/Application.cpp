#include "Application.hpp"

#include "core/Context.hpp"
#include "view/ApplicationView.hpp"
#include "view/Dialogs.hpp"

namespace aosd
{
	Application::Application( int &argc, char **argv )
		: m_context( new core::Context() )
		, m_view( new view::ApplicationView( argc, argv ) )
	{
		
	}

	Application::~Application()
	{
		
	}

	int Application::run()
	{
		return m_view->run( [&](){ start(); } );
	}

	void Application::exit()
	{
		m_view->exit();
	}

	void Application::start()
	{
		view::show_welcome_screen();
	}


}