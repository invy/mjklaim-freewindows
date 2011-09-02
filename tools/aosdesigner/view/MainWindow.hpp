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

		MainWindow();
		~MainWindow();

		/** Clear the tabs currently open in the center of the window. */
		void clear_tabs();
		
		/** Open edition mode : all edition views are open or available. **/
		void open_edition();

		/** Close edition mode : disable all editions views. */
		void close_edition();

		
		/** True if we are currently in edition mode, false otherwise. */
		bool is_edition_mode() const { return m_edition_mode; }

				

	private slots:

		/** Slot : called when a project have been opened. */
		void on_project_open( const core::Project& project );

		/** Slot : called when a project have been closed. */
		void on_project_closed( const core::Project& project );

		/** Slot : called when a new sequence have been created. */
		void on_sequence_created( const core::Sequence& sequence );

		/** Slot : called when a sequence have been deleted. */
		void on_sequence_deleted( const core::Sequence& sequence );

		/** Slot : called when a story walk is beginning. */
		void on_storywalk_begin( const core::StoryWalker& storywalker );

		/** Slot : called when a story walk is ending. */
		void on_storywalk_end( const core::StoryWalker& storywalker );

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

		// Actions:
		std::unique_ptr<DesignerActions> m_designer_actions;

		/// Are we in edition mode?
		bool m_edition_mode;
		
		/** Connect our slots to signals we want to react to. */
		void connect_signals();

		/** Setup the views in their default configuration and positions. **/
		void setup_views_default();
		
		/** Create the menus from the actions. */
		void create_menus();

		/** Add  astory path view in the central tabs of the window. **/
		void add_storypath( std::unique_ptr<StoryPathView>&& storypath );

	};


}
}


#endif
