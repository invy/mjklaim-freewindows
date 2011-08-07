#ifndef HGUARD_AOSD_VIEW_PROJECTVIEW_HPP__
#define HGUARD_AOSD_VIEW_PROJECTVIEW_HPP__
#pragma once

#include <memory>

#include <QDockWidget>

class QTabWidget;

namespace aosd
{
namespace view
{
	class SequenceListView;

	/** Display the basic informations about a Project and the Sequences it contains.
		Allows edition of those informations.
	*/
	class ProjectView
		: public QDockWidget
	{
		Q_OBJECT
	public:
		
		ProjectView();
		~ProjectView();
		
	
	private slots:

	private:
		
		/// Tabs with different views of the informations of this project.
		std::unique_ptr<QTabWidget> m_tabs;
		
	};


}
}


#endif
