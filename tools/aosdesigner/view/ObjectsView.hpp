#ifndef HGUARD_AOSD_VIEW_OBJECTSVIEW_HPP__
#define HGUARD_AOSD_VIEW_OBJECTSVIEW_HPP__
#pragma once

#include <QDockWidget>
#include <QTreeView>

namespace aosd
{
namespace core 
{ 
	class EditionSession; 
	class Project;
}

namespace view
{
	/** Display objects in the canvas, separated as active and inactive, at the current stage of the story.
		Allows editing, adding and removing objects.
	**/
	class ObjectsView
		: public QDockWidget
	{
		Q_OBJECT
	public:
		
		ObjectsView();

	private slots:

		void react_project_open( const core::Project& );
		void react_project_closed( const core::Project& );

		void react_edition_selected( const core::EditionSession& edition_session );
		void react_edition_deselected( const core::EditionSession& edition_session );

	private:

	};


}
}

#endif
