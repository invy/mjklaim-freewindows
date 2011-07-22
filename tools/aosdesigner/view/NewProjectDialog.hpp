#ifndef HGUARD_AOSD_VIEW_NEWPROJECTDIALOG_HPP__
#define HGUARD_AOSD_VIEW_NEWPROJECTDIALOG_HPP__
#pragma once

#include <memory>
#include <QDialog>

#include "core/ProjectInfos.hpp"

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
		Q_OBJECT;
	public:

		NewProjectDialog();
		~NewProjectDialog();

		/** Provide the basic informations about the project described by the user. */
		core::ProjectInfos project_infos();

	private slots:

		// TODO : rename those to match the naming convetion!!!!
		void findLocation();
		void createProject();
		void updateFileName();
		void checkFileName();

	
	private:

		std::unique_ptr< Ui::NewProjectDialog > m_ui;

		
	};
}
}


#endif