#include "view/DesignerActions.hpp"

#include "view/ApplicationView.hpp"
#include "core/Context.hpp"

namespace aosd
{
namespace view
{

	DesignerActions::DesignerActions()
		: m_quit( "&Quit", nullptr )
		, m_new_project( "&New Project", nullptr )
		, m_open_project( "&Open Project", nullptr )
		, m_close_project( "&Close Project", nullptr )
	{
		auto quit_tip = tr("Quit AOS Designer");
		m_quit.setStatusTip( quit_tip );
		m_quit.setToolTip( quit_tip );
		m_quit.setShortcut( tr("Ctrl+Q") );
		connect( &m_quit, SIGNAL(triggered()), ApplicationView::instance(), SLOT(quit()) );

		auto* context = &core::Context::instance();
		
		auto new_project_tip = tr("Create a new project. If a project is already open, it will be closed first.");
		m_new_project.setStatusTip( new_project_tip );
		m_new_project.setToolTip( new_project_tip );
		connect( &m_new_project, SIGNAL(triggered()), context, SLOT(new_project()) );

		auto open_project_tip = tr( "Open a project. If a project is already open, it will be closed first." );
		m_open_project.setStatusTip( open_project_tip );
		m_open_project.setToolTip( open_project_tip );
		connect( &m_open_project, SIGNAL(triggered()), context, SLOT(open_project()) );

		auto close_project_tip = tr( "Close the currently open project." );
		m_close_project.setStatusTip( close_project_tip );
		m_close_project.setToolTip( close_project_tip );
		connect( &m_close_project, SIGNAL(triggered()), context, SLOT(close_project()) );
		
		add( m_new_project );
		add( m_open_project );
		add( m_close_project );
		add( m_quit );
		
	}

}
}