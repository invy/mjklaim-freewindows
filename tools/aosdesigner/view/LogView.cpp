#include "LogView.hpp"

namespace aosd
{

namespace view
{



	LogView::LogView()
	{
		setVisible( false );
		setWindowTitle(tr("Log"));
		setWidget( new QListView() );
	}

}

}