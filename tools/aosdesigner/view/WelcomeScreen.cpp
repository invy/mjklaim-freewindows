#include "view/WelcomeScreen.hpp"

#include <QImage>
#include "ui_WelcomeScreen.h"

#include "core/Context.hpp"

namespace aosd
{
namespace view
{

	WelcomeScreen::WelcomeScreen()
		: m_ui( new Ui::WelcomeScreen(  ) )
	{
		m_ui->setupUi( this );
		m_ui->logo_display->setPixmap( QPixmap::fromImage( QImage( ":/images/welcome_logo" ) ) );

		connect( m_ui->button_new_project, SIGNAL(clicked()), SLOT(on_pushed_new_project()) );
		connect( m_ui->button_open_project, SIGNAL(clicked()), SLOT(on_pushed_open_project()) );
	}

	WelcomeScreen::~WelcomeScreen()
	{

	}

	void WelcomeScreen::on_pushed_new_project()
	{
		core::Context::instance().new_project();
		
	}

	void WelcomeScreen::on_pushed_open_project()
	{

	}

}
}