#include "view/Dialogs.hpp"

#include <QFileDialog>
#include <QObject>

#include "view/dialog/WelcomeScreen.hpp"
#include "view/dialog/NewProjectDialog.hpp"
#include "view/dialog/NewSequenceDialog.hpp"
#include "view/dialog/NewEditionSessionDialog.hpp"
#include "Paths.hpp"

namespace aosd
{
namespace view
{

	void show_welcome_screen()
	{
		// TODO : reuse the dialog instead of re-creating it each time
		std::unique_ptr<WelcomeScreen> screen( new WelcomeScreen() );
		screen->exec();
	}

	bfs::path request_new_project_path( bfs::path default_path )
	{
		if( default_path.empty() )
			default_path = path::DEFAULT_PROJECTS_DIR;

		return bfs::path( QFileDialog::getExistingDirectory( nullptr
															, QObject::tr("New AOS Designer Project Location")
															, QString::fromStdString( default_path.string() )
															).toStdString() );
	}


	bfs::path request_project_path( bfs::path default_path )
	{
		if( default_path.empty() )
			default_path = path::DEFAULT_PROJECTS_DIR;

		return bfs::path( QFileDialog::getOpenFileName( nullptr
														, QObject::tr( "Open AOS Designer Project" )
														, QString::fromStdString( default_path.string() )
														, QObject::tr( "AOS Designer Project (*.aosp)" )
														).toStdString() );
	}

	template< class InfoType, class DialogType>
	InfoType request_infos()
	{
		std::unique_ptr<DialogType> dialog( new DialogType() );
		if( dialog->exec() )
			return dialog->infos();
		else
			return InfoType();
	}

	core::ProjectInfos request_new_project_infos()
	{
		return request_infos< core::ProjectInfos, NewProjectDialog >();
	}

	core::SequenceInfos request_new_sequence_infos()
	{
		return request_infos< core::SequenceInfos, NewSequenceDialog >();
	}

	core::EditionSessionInfos request_new_edition_session_infos()
	{
		return request_infos< core::EditionSessionInfos, NewEditionSessionDialog >();
	}

}
}