#include "ToolboxView.hpp"

namespace aosd
{
namespace view
{


	ToolboxView::ToolboxView()
	{
		setVisible( false );
		setWindowTitle( tr("Toolbox") );
		setWidget( new QToolBox() );
	}

}
}