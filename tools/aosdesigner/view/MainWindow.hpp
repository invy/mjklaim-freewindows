#ifndef __AOSD_VIEW_MAINWINDOW_HPP__
#define __AOSD_VIEW_MAINWINDOW_HPP__
#pragma once

#include <memory>

#include <QMainWindow>

namespace Ui
{
	class MainWindow;
}

namespace aosd
{
namespace core
{
	class Project;
}

namespace view
{
	class ProjectView;

	class MainWindow
		: public QMainWindow
	{
		Q_OBJECT
	public:

		MainWindow( QWidget* parent );
		~MainWindow();

		void add_central_widget( QWidget& widget, const std::string tab_label );
		
	private slots:

		void on_project_open( const core::Project& project );

	private:

		std::unique_ptr<Ui::MainWindow> m_ui;
		std::unique_ptr<QTabWidget> m_central_tabs;
		

	};


}
}


#endif
