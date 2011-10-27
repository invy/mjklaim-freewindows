#ifndef HGUARD_AOSD_VIEW_LAYERSVIEW_HPP__
#define HGUARD_AOSD_VIEW_LAYERSVIEW_HPP__
#pragma once

#include <QListView>
#include "view/EditionToolView.hpp"

namespace aosd
{
namespace view
{
	/** Display the layers of a sequence, the associated objects and their state at the current story stage.
		Allow activating and deactivating layers for the current stage.
	**/
	class LayersView
		: public EditionToolView
	{

		Q_OBJECT
	public:
		
		LayersView();
		~LayersView();


	private:

		std::unique_ptr< QListView > m_layer_list_view;
		std::unique_ptr< QListView > m_layer_objects_view;


		void begin_edition_session( const core::EditionSession& edition_session ){}
		void end_edition_session( const core::EditionSession& edition_session ){}
		void connect_edition( const core::EditionSession& edition_session );
		void disconnect_edition( const core::EditionSession& edition_session );
		


	};


}
}

#endif
