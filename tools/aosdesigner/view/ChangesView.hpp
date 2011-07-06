#ifndef HGUARD_AOSD_VIEW_CHANGESVIEW_HPP__
#define HGUARD_AOSD_VIEW_CHANGESVIEW_HPP__
#pragma once

#include <QDockWidget>
#include <QListView>

namespace aosd
{
namespace view
{
	/** Display lists of changes between the current story stage and the previous one.
	**/
	class ChangesView
		: public QDockWidget
	{
		Q_OBJECT
	public:

		ChangesView()
		{
			setWindowTitle( tr("Changes") );
			setWidget( new QListView() );
		}
		
		


	private:

	};


}
}


#endif
