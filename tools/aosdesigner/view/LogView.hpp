#ifndef __AOSD_VIEW_LOGVIEW_HPP__
#define __AOSD_VIEW_LOGVIEW_HPP__
#pragma once

#include <QDockWidget>
#include <QListView>

namespace aosd
{
	namespace view
	{

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
