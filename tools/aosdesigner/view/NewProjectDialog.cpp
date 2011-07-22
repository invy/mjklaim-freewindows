#include "NewProjectDialog.hpp"


#include "ui_NewProjectDialog.h"
#include "view/Dialogs.hpp"

namespace aosd
{
namespace view
{
	

	NewProjectDialog::NewProjectDialog()
		: m_ui( new Ui::NewProjectDialog() )
	{
		m_ui->setupUi( this );

		connect( m_ui->cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
		connect( m_ui->createButton, SIGNAL(clicked()), this, SLOT(createProject()));
		connect( m_ui->findLocationButton, SIGNAL(clicked()), this, SLOT(findLocation()) );
		
		connect( m_ui->edit_project_name, SIGNAL(changed()), this, SLOT(updateFileName()) );
		connect( m_ui->edit_file_name, SIGNAL(changed()), this, SLOT(checkFileName()) );

		// set a default name
		m_ui->edit_project_name->setText( tr("My Project") );
		
	}

	NewProjectDialog::~NewProjectDialog()
	{

	}

	void NewProjectDialog::findLocation()
	{
		auto location = request_new_project_path();
		if( !location.empty() )
		{
			if( !m_ui->edit_file_name->text().isEmpty() )
			{
				location = location / m_ui->edit_file_name->text().toStdString();
			}
			
			m_ui->edit_location->setText( QString::fromStdString(location.string()) );
		}
	}

	void NewProjectDialog::createProject()
	{
		// TODO : check that the names are filled
		if( !m_ui->edit_file_name->text().isEmpty() && !m_ui->edit_project_name->text().isEmpty() )
		{
			// TODO : check that the location is valid
			// TODO : launch the creation of the project
			accept();
		}
		else
		{
			// TODO : notify the user?
		}
		
	}

	void NewProjectDialog::updateFileName()
	{
		// TODO : update the filename field with only valid name
	}

	void NewProjectDialog::checkFileName()
	{
		// TODO : check that the filename contains only valid names
	}

	core::ProjectInfos NewProjectDialog::project_infos()
	{
		
		auto location = m_ui->edit_location->text();
		auto filename = m_ui->edit_file_name->text();
		auto name = m_ui->edit_project_name->text();

		core::ProjectInfos infos;
		if( !( location.isEmpty() || filename.isEmpty() ) )
		{
			infos.location = boost::filesystem::path( location.toStdString() ) / filename.toStdString();
		}

		infos.name = name.toStdString();
		
		return infos;
	}

}
}