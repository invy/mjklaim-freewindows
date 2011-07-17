#ifndef HGUARD_AOSD_VIEW_NEWPROJECTDIALOG_HPP__
#define HGUARD_AOSD_VIEW_NEWPROJECTDIALOG_HPP__
#pragma once

#include <memory>
#include <QDialog>

namespace Ui { class NewProjectDialog; }

namespace aosd
{
namespace view
{
	/** Dialog used to ask the user details on a new project to create.
	*/
	class NewProjectDialog
		: public QDialog
	{
	public:

		NewProjectDialog();
		~NewProjectDialog();

	
	private:

		std::unique_ptr< Ui::NewProjectDialog > m_ui;
		
	};
}
}


#endif