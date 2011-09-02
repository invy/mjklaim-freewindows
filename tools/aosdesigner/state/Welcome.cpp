#include "state/Welcome.hpp"

#include "view/dialog/WelcomeScreen.hpp"


namespace aosd
{
namespace state
{
	void Welcome::show_welcome()
	{
		std::unique_ptr<view::WelcomeScreen> welcome_screen( new view::WelcomeScreen() );
		welcome_screen->exec();
	}

}
}