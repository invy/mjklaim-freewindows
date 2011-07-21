#include "view/ApplicationView.hpp"

#include <QTimer>

#include "view/WelcomeScreen.hpp"
#include "view/MainWindow.hpp"
#include "view/DesignerActions.hpp"

namespace aosd
{
namespace view
{


	ApplicationView::ApplicationView( int &argc, char **argv )
		: QApplication( argc, argv )
		, m_main_window( new MainWindow() )
	{
		show_main_window();
	}

	ApplicationView::~ApplicationView()
	{

	}

	void ApplicationView::show_main_window()
	{
		m_main_window->show();
	}

	int ApplicationView::run( Callback callback_on_ready )
	{
		QTimer::singleShot(0, this, SLOT(on_ready()));

		m_on_ready = callback_on_ready;
		return this->exec();
	}

	void ApplicationView::on_ready()
	{
		if( m_on_ready )
			m_on_ready();
	}


}
}