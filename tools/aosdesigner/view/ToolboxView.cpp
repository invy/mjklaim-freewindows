#include "ToolboxView.hpp"

namespace aosd
{
namespace view
{


	ToolboxView::ToolboxView()
	{
		setWindowTitle( tr("Toolbox") );
		setWidget( new QToolBox() );
	}

	void ToolboxView::connect_edition( const core::EditionSession& edition_session )
	{

	}

	void ToolboxView::disconnect_edition( const core::EditionSession& edition_session )
	{

	}

}
}