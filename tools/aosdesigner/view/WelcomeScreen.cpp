#include "view/WelcomeScreen.hpp"

#include <QImage>
#include "ui_WelcomeScreen.h"

namespace aosd
{
namespace view
{

	WelcomeScreen::WelcomeScreen()
		: m_ui( new Ui::WelcomeScreen(  ) )
	{
		m_ui->setupUi( this );
		m_ui->logo_display->setPixmap( QPixmap::fromImage( QImage( ":/images/welcome_logo" ) ) );
	}

	WelcomeScreen::~WelcomeScreen()
	{

	}

}
}