#include "FreeWindow.hpp"

#include <QMdiArea>
#include <QMdiSubWindow>
#include <QDockWidget>
#include <QMenu>

#include "utilcpp/Assert.hpp"

namespace aosd
{
namespace view
{



	FreeWindow::FreeWindow( QWidget& widget )
		: m_widget( widget )
		, m_window_inside( new QMdiSubWindow )
		, m_window_outside( new QDockWidget )
	{
		setup_inside_window();
		setup_outside_window();
		
	}

	FreeWindow::~FreeWindow()
	{

	}

	void FreeWindow::setup_inside_window()
	{
		auto menu = m_window_inside->systemMenu();
		UTILCPP_ASSERT_NOT_NULL( menu );
		auto float_action = menu->addAction( tr("Float Window") );
		connect( float_action, SIGNAL( pressed() ), this, SLOT( react_get_outside() ) );
	}

	void FreeWindow::setup_outside_window()
	{
		auto title_bar = m_window_outside->titleBarWidget();
		//UTILCPP_ASSERT_NOT_NULL( title_bar );
		if( title_bar )
		{
			auto dock_action = new QAction( tr("Dock Window"), nullptr );
			title_bar->addAction( dock_action );
			connect( dock_action, SIGNAL( pressed() ), this, SLOT( react_get_inside() ) );

		}
		
		m_window_outside->setAllowedAreas( 0 ); // no docking area allowed in this form
	}

	template< class WindowA, class WindowB >
	void move_widget_from_a_to_b( WindowA& a, WindowB& b, QWidget& widget )
	{
		widget.hide();

		a.setWidget( nullptr );
		a.hide();

		b.setWidget( &widget );
		b.show();

		widget.show();
	}

	void FreeWindow::go_inside()
	{
		move_widget_from_a_to_b( *m_window_outside, *m_window_inside, m_widget );
	}

	void FreeWindow::go_outside()
	{
		move_widget_from_a_to_b( *m_window_inside, *m_window_outside, m_widget );
	}

	void FreeWindow::react_get_inside()
	{
		go_inside();
	}

	void FreeWindow::react_get_outside()
	{
		go_outside();
	}




}
}