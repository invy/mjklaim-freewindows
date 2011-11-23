#include "CanvasView.hpp"

#include <QGraphicsView>

#include "view/CanvasGraphicsView.hpp"

namespace aosd
{
namespace view
{

	CanvasView::CanvasView()
		: m_graphic_view( new CanvasGraphicsView )
		, m_content_view( new QGraphicsView )
	{
		initialize_graphic_view();
		initialize_content_view();

		setOrientation( Qt::Vertical );
		addWidget( m_graphic_view.get() );
		addWidget( m_content_view.get() );

	}

	CanvasView::~CanvasView()
	{

	}

	void CanvasView::initialize_graphic_view()
	{

	}

	void CanvasView::initialize_content_view()
	{
		m_content_view->setFixedHeight( 80 );
		// TODO : add horizontal layout 
	}

	void CanvasView::clear()
	{

	}

	void CanvasView::update( const aosl::Canvas& canvas, const aosl::Library& library )
	{

	}

}
}