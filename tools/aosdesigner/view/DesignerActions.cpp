#include "view/DesignerActions.hpp"

#include "view/ApplicationView.hpp"

namespace aosd
{
namespace view
{

	DesignerActions::DesignerActions()
		: m_quit( "&Quit", nullptr )
	{
		m_quit.setStatusTip( tr("Quit AOS Designer") );
		m_quit.setShortcut( tr("Ctrl+Q") );
		connect( &m_quit, SIGNAL(triggered()), ApplicationView::instance(), SLOT(quit()) );
		
		add( m_quit );
	}

}
}