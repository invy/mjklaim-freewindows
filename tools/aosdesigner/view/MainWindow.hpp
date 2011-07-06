#ifndef HGUARD_AOSD_VIEW_MAINWINDOW_HPP__
#define HGUARD_AOSD_VIEW_MAINWINDOW_HPP__
#pragma once

#include <memory>
#include <QMainWindow>
#include <QTabWidget>

#include "view/ForwardView.hpp"
#include "core/ForwardCore.hpp"

namespace Ui
{
	class MainWindow;
}

namespace aosd
{

namespace view
{
	/** Main window of the application.
		Hold all the views and visual tools but don't display them until getting in edition mode.
	**/
	class MainWindow
		: public QMainWindow
	{
		Q_OBJECT
	public:

		MainWindow( QWidget* parent );
		~MainWindow();

		/** Add a widget in the central part of the window. **/
		void add_central_widget( QWidget& widget, const std::string tab_label );
				
	private slots:

		/** Slot : called when a project have been openned. */
		void on_project_open( const core::Project& project );

	private:

		/** UI file defining the window look. */
		std::unique_ptr<Ui::MainWindow> m_ui;

		/** Tabs at the center of the window. */
		std::unique_ptr<QTabWidget> m_central_tabs;
		

	};


}
}


#endif
