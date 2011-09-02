#ifndef HGUARD_AOSD_VIEW_DESIGNERACTIONS_HPP__
#define HGUARD_AOSD_VIEW_DESIGNERACTIONS_HPP__
#pragma once

#include <QAction>

namespace aosd
{
namespace view
{
	/** Provide actions for manipulating the Designer(the application).
	*/
	class DesignerActions
	{
	public:

		DesignerActions();

		/** Setup a full main menu. 
		**/
		void setup_menubar( QMenuBar& menubar );

		const QAction& quit() const { return m_quit; }
		const QAction& new_project() const { return m_new_project; }
		const QAction& open_project() const { return m_open_project; }
		const QAction& close_project() const { return m_close_project; }

		const QAction& new_sequence() const { return m_new_sequence; }
		const QAction& save_project() const { return m_save_project; }
		const QAction& restore_project() const { return m_restore_project; }

		const QAction& new_storypath() const { return m_new_storypath; }
	

		QAction& quit() { return m_quit; }
		QAction& new_project() { return m_new_project; }
		QAction& open_project() { return m_open_project; }
		QAction& close_project() { return m_close_project; }

		QAction& new_sequence() { return m_new_sequence; }
		QAction& save_project() { return m_save_project; }
		QAction& restore_project() { return m_restore_project; }

		QAction& new_storypath() { return m_new_storypath; }

	
	private:

		QAction m_quit;
		QAction m_new_project;
		QAction m_open_project;
		QAction m_close_project;

		QAction m_new_sequence;
		QAction m_save_project;
		QAction m_restore_project;

		QAction m_new_storypath;
		
	};

}
}


#endif