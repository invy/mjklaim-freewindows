#ifndef HGUARD_AOSD_VIEW_OBJECTSVIEW_HPP__
#define HGUARD_AOSD_VIEW_OBJECTSVIEW_HPP__
#pragma once

#include <QDockWidget>
#include <QTreeView>

namespace aosd
{
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
		
		ObjectsView()
		{
			setVisible( false );
			setWindowTitle( tr("Objects") );
			
			setWidget(new QTreeView());
		}


	private:

	};


}
}

#endif
