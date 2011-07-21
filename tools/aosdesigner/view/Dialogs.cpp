#include "view/Dialogs.hpp"

#include <QFileDialog>
#include <QObject>

#include "view/WelcomeScreen.hpp"
#include "view/NewProjectDialog.hpp"

namespace aosd
{
namespace view
{

	void show_welcome_screen()
	{
		auto screen = new WelcomeScreen();
		screen->exec();
	}

	bfs::path request_new_project_path( bfs::path default_path )
	{
		return bfs::path( QFileDialog::getExistingDirectory( nullptr
															, QObject::tr("New AOS Designer Project Location")
															, QString::fromStdString( default_path.string() )
															).toStdString() );
	}


	bfs::path request_project_path( bfs::path default_path )
	{
		return bfs::path( QFileDialog::getOpenFileName( nullptr
														, QObject::tr( "Open AOS Designer Project" )
														, QString::fromStdString( default_path.string() )
														, QObject::tr( "AOS Designer Project (*.aosp)" )
														).toStdString() );
	}

	void request_new_project_infos()
	{
		auto dialog = new NewProjectDialog();
		dialog->exec();
	}



}
}