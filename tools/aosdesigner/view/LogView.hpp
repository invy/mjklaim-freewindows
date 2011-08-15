#ifndef HGUARD_AOSD_VIEW_LOGVIEW_HPP__
#define HGUARD_AOSD_VIEW_LOGVIEW_HPP__
#pragma once

#include <QDockWidget>
#include <QListView>

namespace aosd
{
namespace view
{
	/** Display the logs of activity of the application. 
	**/
	class LogView
		: public QDockWidget
	{
		Q_OBJECT
	public:

		LogView()
		{
			setWindowTitle(tr("Log"));
			setWidget( new QListView() );
		}


	private:

	};


}
}

#endif
