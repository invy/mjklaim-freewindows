#ifndef HGUARD_AOSD_VIEW_DESIGNERACTIONS_HPP__
#define HGUARD_AOSD_VIEW_DESIGNERACTIONS_HPP__
#pragma once

#include "view/ActionsProvider.hpp"

namespace aosd
{
namespace view
{
	/** Provide actions for manipulating the Designer(the application).
	*/
	class DesignerActions
		: public ActionsProvider
	{
		Q_OBJECT
	public:

		DesignerActions();

		const QAction& quit() const { return m_quit; }
		const QAction& new_project() const { return m_new_project; }
		const QAction& open_project() const { return m_open_project; }
		const QAction& close_project() const { return m_close_project; }
	

	
	private:

		QAction m_quit;
		QAction m_new_project;
		QAction m_open_project;
		QAction m_close_project;
		
	};

}
}


#endif