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

		/** Add  astory path view in the central tabs of the window. **/
		void add_storypath( StoryPathView& storypath );

		/** Clear the tabs currently open in the center of the window. */
		void clear_tabs();
		
		/** Open edition mode : all edition views are open or available. **/
		void open_edition();

		/** Close edition mode : disable all editions views. */
		void close_edition();

		
		/** True if we are currently in edition mode, false otherwise. */
		bool is_edition_mode() const { return m_edition_mode; }

				
	protected:

		void keyPressEvent( QKeyEvent * );

	private slots:

		/** Slot : called when a project have been opened. */
		void on_project_open( const core::Project& project );

	private:

		/** UI file defining the window look. */
		std::unique_ptr<Ui::MainWindow> m_ui;

		/** Tabs at the center of the window. */
		std::unique_ptr<QTabWidget> m_central_tabs;

		// Components of the edition interface:
		std::unique_ptr<ProjectView> m_project_view;
		std::unique_ptr<ChangesView> m_changes_view;
		std::unique_ptr<ObjectsView> m_objects_view;
		std::unique_ptr<LibrariesView> m_libraries_view;
		std::unique_ptr<LayersView> m_layers_view;
		std::unique_ptr<ToolboxView> m_toolbox_view;
		std::unique_ptr<LogView> m_log_view;


		/// Are we in edition mode?
		bool m_edition_mode;
		
		/** Connect our slots to signals we want to react to. */
		void connect_signals();

		/** Setup the views in their default configuration and positions. **/
		void setup_views_default();
		

	};


}
}


#endif
