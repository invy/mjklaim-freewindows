#include "CanvasInvisibleObjectsView.hpp"

#include <QGraphicsScene>

namespace aosd
{
namespace view
{

	CanvasInvisibleObjectsView::CanvasInvisibleObjectsView()
		: m_scene( new QGraphicsScene )
	{
		setFixedHeight( 80 );
		setBackgroundBrush( QBrush( QColor( Qt::darkGreen ) ) );


		setScene( m_scene.get() );
	}

	CanvasInvisibleObjectsView::~CanvasInvisibleObjectsView()
	{

	}

	void CanvasInvisibleObjectsView::clear()
	{

	}

	void CanvasInvisibleObjectsView::update( const aosl::Canvas& canvas, const aosl::Library& library )
	{

	}

}
}