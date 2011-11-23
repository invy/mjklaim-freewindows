#include "CanvasGraphicsView.hpp"

#include <QGraphicsScene>

namespace aosd
{
namespace view
{
	
	CanvasGraphicsView::CanvasGraphicsView()
		: m_scene( new QGraphicsScene )
	{

		setBackgroundBrush( QBrush( QColor( Qt::black ) ) );
		setScene( m_scene.get() );
	}

	CanvasGraphicsView::~CanvasGraphicsView()
	{

	}

	void CanvasGraphicsView::clear()
	{

	}

	void CanvasGraphicsView::update( const aosl::Canvas& canvas, const aosl::Library& library )
	{

	}

}
}