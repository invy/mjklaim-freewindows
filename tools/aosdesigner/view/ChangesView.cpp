#include "ChangesView.hpp"

namespace aosd
{
namespace view
{


	ChangesView::ChangesView()
	{
		setWindowTitle( tr("Changes") );
		setWidget( new QListView() );
	}

	void ChangesView::connect_edition( const core::EditionSession& edition_session )
	{

	}

	void ChangesView::disconnect_edition( const core::EditionSession& edition_session )
	{

	}

}
}