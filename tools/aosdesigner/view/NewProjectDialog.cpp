#include "NewProjectDialog.hpp"


#include "ui_NewProjectDialog.h"
#include "view/Dialogs.hpp"
#include "Paths.hpp"

namespace aosd
{
namespace view
{
	

	NewProjectDialog::NewProjectDialog()
		: m_ui( new Ui::NewProjectDialog() )
	{
		m_ui->setupUi( this );

		connect( m_ui->button_cancel, SIGNAL(clicked()), this, SLOT(reject()));
		connect( m_ui->button_create, SIGNAL(clicked()), this, SLOT(create_project()));
		connect( m_ui->button_find_location, SIGNAL(clicked()), this, SLOT(find_location()) );
		
		connect( m_ui->edit_project_name, SIGNAL(textChanged(const QString&)), this, SLOT(update_codename()) );
		connect( m_ui->edit_codename, SIGNAL(textChanged(const QString&)), this, SLOT(check_codename()) );

		connect( m_ui->edit_codename, SIGNAL(textChanged(const QString&)), this, SLOT(update_project_file()) );
		connect( m_ui->edit_dir_location, SIGNAL(textChanged(const QString&)), this, SLOT(update_project_file()) );


		// set a defaults
		m_ui->edit_project_name->setText( tr("My Project") );
		m_ui->edit_dir_location->setText( QString::fromStdString( path::DEFAULT_PROJECTS_DIR.string() ) );
		
		m_ui->edit_project_file_location->setReadOnly( true );
	}

	NewProjectDialog::~NewProjectDialog()
	{

	}

	void NewProjectDialog::find_location()
	{
		auto location = request_new_project_path();
		if( !location.empty() )
		{
			m_ui->edit_dir_location->setText( QString::fromStdString(location.string()) );
		}
	}

	void NewProjectDialog::create_project()
	{
		// TODO : check that the names are filled
		if( !m_ui->edit_dir_location->text().isEmpty() 
		&&	!m_ui->edit_project_name->text().isEmpty() 
		)
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

	void NewProjectDialog::update_codename()
	{
		// TODO : update the filename field with only valid name
		
	}

	void NewProjectDialog::check_codename()
	{
		// TODO : check that the filename contains only valid names
	}

	core::ProjectInfos NewProjectDialog::project_infos()
	{
		
		auto location = m_ui->edit_dir_location->text();
		auto codename = m_ui->edit_codename->text();
		auto name = m_ui->edit_project_name->text();

		core::ProjectInfos infos;
		if( !( location.isEmpty() || codename.isEmpty() ) )
		{
			infos.location = boost::filesystem::path( location.toStdString() ) / codename.toStdString();
		}

		infos.name = name.toStdString();
		infos.codename = codename.toStdString();
		
		return infos;
	}

	void NewProjectDialog::update_project_file()
	{
		auto dir_location = m_ui->edit_dir_location->text();
		auto codename = m_ui->edit_codename->text();
		if( ! ( dir_location.isEmpty() || codename.isEmpty() )  )
		{
			namespace bsf = boost::filesystem;
			bfs::path directory_path = dir_location.toStdString();
			bfs::path project_filename = path::PROJECT_FILE( codename.toStdString() );
			bfs::path project_file_path =  directory_path / codename.toStdString() / project_filename;

			m_ui->edit_project_file_location->setText( QString::fromStdString( project_file_path.string() ) );
		}
	}

}
}