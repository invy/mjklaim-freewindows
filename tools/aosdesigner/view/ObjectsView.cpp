#include "ObjectsView.hpp"

namespace aosd
{
namespace view
{



	ObjectsView::ObjectsView()
	{
		setVisible( false );
		setWindowTitle( tr("Objects") );

		setWidget(new QTreeView());
	}

}

}