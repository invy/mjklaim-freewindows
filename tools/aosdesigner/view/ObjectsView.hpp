#ifndef HGUARD_AOSD_VIEW_OBJECTSVIEW_HPP__
#define HGUARD_AOSD_VIEW_OBJECTSVIEW_HPP__
#pragma once

#include <QTreeView>
#include "view/EditionToolView.hpp"

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
		: public EditionToolView
	{
		Q_OBJECT
	public:
		
		ObjectsView();
		~ObjectsView();

	private:

		std::unique_ptr<QTreeView> m_object_tree_view;

		
		void fill_object_tree( const core::EditionSession& edition_session );
		void clear();

		void connect_edition( const core::EditionSession& edition_session );
		void disconnect_edition( const core::EditionSession& edition_session );

	};


}
}

#endif
