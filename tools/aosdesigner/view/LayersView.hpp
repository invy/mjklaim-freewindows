#ifndef HGUARD_AOSD_VIEW_LAYERSVIEW_HPP__
#define HGUARD_AOSD_VIEW_LAYERSVIEW_HPP__
#pragma once

#include <QTreeView>
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


	private:

		void connect_edition( const core::EditionSession& edition_session );
		void disconnect_edition( const core::EditionSession& edition_session );

	};


}
}

#endif
