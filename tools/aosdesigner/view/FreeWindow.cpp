#include "FreeWindow.hpp"

#include <QMdiArea>
#include <QMdiSubWindow>
#include <QWidget>
#include <QAction>
#include <QMenu>


#include "utilcpp/Assert.hpp"

namespace aosd
{
namespace view
{

	FreeWindow::FreeWindow( QWidget& widget )
		: m_widget( widget )
		, m_window_inside( new WindowInside )
		, m_dock_action( new QAction( tr("Dock Window"), nullptr ) )
		, m_float_action( new QAction( tr("Float Window"), nullptr ) )
	{
		initialize_inside_window();		
	}

	FreeWindow::~FreeWindow()
	{
		terminate_inside_window();		
	}

	void FreeWindow::initialize_inside_window()
	{
		m_window_inside->systemMenu()->addAction( m_float_action.get() );
		connect( m_float_action.get(), SIGNAL( triggered() ), this, SLOT( react_get_outside() ) );

		m_window_inside->setWindowTitle( m_widget.windowTitle() );
	}

	void FreeWindow::initialize_outside_window()
	{
		m_widget.addAction( m_dock_action.get() );
		
		connect( m_dock_action.get(), SIGNAL( triggered() ), this, SLOT( react_get_inside() ) );
	}

	void FreeWindow::terminate_inside_window()
	{
		m_window_inside->hide();
		m_window_inside->setWidget( nullptr );
		m_window_inside->systemMenu()->removeAction( m_float_action.get() );
	}


	void FreeWindow::terminate_outside_window()
	{
		m_widget.removeAction( m_dock_action.get() );
	}



	void FreeWindow::go_inside()
	{
		m_window_inside->setWidget( &m_widget );
		m_window_inside->show();
	}

	void FreeWindow::go_outside()
	{
		m_window_inside->hide();
		m_window_inside->setWidget( nullptr );

		m_widget.show();

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