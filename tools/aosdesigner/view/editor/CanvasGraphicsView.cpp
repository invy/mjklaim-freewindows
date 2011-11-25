#include "CanvasGraphicsView.hpp"

#include <QGraphicsScene>

#include "aosl/object.hpp"
#include "aosl/canvas.hpp"
#include "aosl/library.hpp"
#include "aoslcpp/algorithm/for_each.hpp"

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

	void CanvasGraphicsView::update( const aosl::Canvas& canvas )
	{
		aoslcpp::for_each_object_depth( canvas, [&]( const aosl::Object& object )
		{
			
		});


	}

	void CanvasGraphicsView::add_graphic_object( const aosl::Object& object )
	{

	}

}
}