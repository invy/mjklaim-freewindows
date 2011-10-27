#include "LayersView.hpp"

namespace aosd
{
namespace view
{

	LayersView::LayersView()
	{
		setWindowTitle(tr("Layers"));
		//setWidget( new QTreeView() );
	}

	LayersView::~LayersView()
	{
	}

	void LayersView::connect_edition( const core::EditionSession & )
	{

	}

	void LayersView::disconnect_edition( const core::EditionSession & )
	{

	}


}

}