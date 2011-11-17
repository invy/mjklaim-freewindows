#include "LibrariesView.hpp"

namespace aosd
{
namespace view
{

	LibrariesView::LibrariesView()
	{
		setWindowTitle(tr("Libraries"));
		setWidget( new QListView() );
	}

	void LibrariesView::connect_edition( const core::EditionSession& edition_session )
	{

	}

	void LibrariesView::disconnect_edition( const core::EditionSession& edition_session )
	{

	}

}

}