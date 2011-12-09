#include "CanvasInvisibleObjectsView.hpp"

#include <QGraphicsScene>

#include "core/Library.hpp"
#include "aosl/canvas.hpp"

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

	void CanvasInvisibleObjectsView::update( const aosl::Canvas& canvas, const core::Library& sequence_library, const core::Library& project_library   )
	{

	}

}
}