#include "NewProjectDialog.hpp"

#include "ui_NewProjectDialog.h"

namespace aosd
{
namespace view
{
	

	NewProjectDialog::NewProjectDialog()
		: m_ui( new Ui::NewProjectDialog() )
	{
		m_ui->setupUi( this );
	}

	NewProjectDialog::~NewProjectDialog()
	{

	}

}
}