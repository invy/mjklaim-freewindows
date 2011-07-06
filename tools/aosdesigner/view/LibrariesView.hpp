#ifndef HGUARD_AOSD_VIEW_LIBRARIESVIEW_HPP__
#define HGUARD_AOSD_VIEW_LIBRARIESVIEW_HPP__
#pragma once

#include <QDockWidget>
#include <QListView>

namespace aosd
{
namespace view
{
	/** Display lists of resources for each libraries used in the current sequence.
		Allow editing, adding and removing resources from libraries.
	**/
	class LibrariesView
		: public QDockWidget
	{
		Q_OBJECT
	public:
		
		LibrariesView()
		{
			setWindowTitle(tr("Libraries"));
			setWidget( new QListView() );
		}


	private:

	};


}
}

#endif
