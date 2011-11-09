#ifndef HGUARD_AOSD_VIEW_MAINWINDOW_HPP__
#define HGUARD_AOSD_VIEW_MAINWINDOW_HPP__
#pragma once

#include <memory>
#include <QMainWindow>

#include "view/ForwardView.hpp"
#include "core/ForwardCore.hpp"
#include "core/EditionSessionId.hpp"
#include "view/DesignerActions.hpp"

class QMdiArea;

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

		/** Clear the windows currently open in the center of the window. */
		void clear_windows();
		
		/** Open edition mode : all edition views are open or available. **/
		void open_edition();

		/** Close edition mode : disable all editions views. */
		void close_edition();
		
		/** Add a window in the main window. */
		void add_window( std::unique_ptr<QWidget> window );

		/** True if we are currently in edition mode, false otherwise. */
		bool is_edition_mode() const { return m_edition_mode; }

	public slots:

		/** Select visually the editor corresponding to the provided session id. */
		void select_editor( core::EditionSessionId session_id );

		/** Create an editor for an edition session. */
		void create_editor( const core::EditionSession& edition_session );

	private slots:

		/** Slot : called when a project have been opened. */
		void react_project_open( const core::Project& project );

		/** Slot : called when a project have been closed. */
		void react_project_closed( const core::Project& project );

		/** Slot : called when a new sequence have been created. */
		void react_sequence_created( const core::Sequence& sequence );

		/** Slot : called when a sequence have been deleted. */
		void react_sequence_deleted( const core::Sequence& sequence );

		/** Slot : called when an edition session is beginning. */
		void react_edition_session_begin( const core::EditionSession& edition_session );

		/** Slot : called when an edition session is ending. */
		void react_edition_session_end( const core::EditionSession& edition_session );

	private:

		/** UI file defining the window look. */
		std::unique_ptr<Ui::MainWindow> m_ui;

		/** Tabs at the center of the window. */
		std::unique_ptr<QMdiArea> m_central_area;

		// Components of the edition interface:
		std::unique_ptr<ProjectView> m_project_view;
		std::unique_ptr<ChangesView> m_changes_view;
		std::unique_ptr<ObjectsView> m_objects_view;
		std::unique_ptr<LibrariesView> m_libraries_view;
		std::unique_ptr<LayersView> m_layers_view;
		std::unique_ptr<ToolboxView> m_toolbox_view;
		std::unique_ptr<LogView> m_log_view;


		// Manage and provide main actions (in the main menu for example)
		DesignerActions m_designer_actions;

		/// Are we in edition mode?
		bool m_edition_mode;
		
		/** Connect our slots to signals we want to react to. */
		void connect_signals();

		/** Create the menus from the actions. */
		void create_menus();

		/** Setup the views in their default configuration and positions. **/
		void setup_views_default();
		

		
	};


}
}


#endif
