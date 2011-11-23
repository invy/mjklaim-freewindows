#include "CanvasGraphicsView.hpp"

#include <QGraphicsScene>

namespace aosd
{
namespace view
{
	
	CanvasGraphicsView::CanvasGraphicsView()
		: m_scene( new QGraphicsScene )
	{

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