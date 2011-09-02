#ifndef HGUARD_AOSD_VIEW_LAYERSVIEW_HPP__
#define HGUARD_AOSD_VIEW_LAYERSVIEW_HPP__
#pragma once

#include <QDockWidget>
#include <QTreeView>

namespace aosd
{
namespace view
{
	/** Display the layers of a sequence, the associated objects and their state at the current story stage.
		Allow activating and deactivating layers for the current stage.
	**/
	class LayersView
		: public QDockWidget
	{
		Q_OBJECT
	public:
		
		LayersView()
		{
			setVisible( false );
			setWindowTitle(tr("Layers"));
			setWidget( new QTreeView() );
		}


	private:

	};


}
}

#endif
