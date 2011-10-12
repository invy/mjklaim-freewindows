#ifndef HGUARD_AOSD_VIEW_OBJECTSVIEW_HPP__
#define HGUARD_AOSD_VIEW_OBJECTSVIEW_HPP__
#pragma once

#include <map>
#include <memory>
#include <QTreeView>
#include "core/EditionSessionId.hpp"
#include "view/EditionToolView.hpp"
#include "view/model/CanvasObjectsModel.hpp"


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
		
		std::map< core::EditionSessionId, std::unique_ptr< CanvasObjectsModel > > m_model_registry;
		
		void begin_edition_session( const core::EditionSession& edition_session );
		void end_edition_session( const core::EditionSession& edition_session );
		void connect_edition( const core::EditionSession& edition_session );
		void disconnect_edition( const core::EditionSession& edition_session );

		CanvasObjectsModel* find_model( const core::EditionSessionId& edition_id );

	};


}
}

#endif
