#include "ChangesView.hpp"

namespace aosd
{
namespace view
{


	ChangesView::ChangesView()
	{
		setVisible( false );
		setWindowTitle( tr("Changes") );
		setWidget( new QListView() );
	}

}
}