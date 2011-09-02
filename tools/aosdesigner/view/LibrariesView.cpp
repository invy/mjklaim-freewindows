#include "LibrariesView.hpp"

namespace aosd
{
namespace view
{



	LibrariesView::LibrariesView()
	{
		setVisible( false );
		setWindowTitle(tr("Libraries"));
		setWidget( new QListView() );
	}

}

}