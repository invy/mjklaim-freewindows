#include "view/DialogPrompt.hpp"

#include "view/WelcomeScreen.hpp"

namespace aosd
{
namespace view
{

	void show_welcome_screen()
	{
		auto screen = new WelcomeScreen();
		screen->exec();
	}


}
}