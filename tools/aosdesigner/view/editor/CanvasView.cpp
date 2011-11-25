#include "CanvasView.hpp"


#include "CanvasGraphicsView.hpp"
#include "CanvasInvisibleObjectsView.hpp"

namespace aosd
{
namespace view
{

	CanvasView::CanvasView()
		: m_graphic_view( new CanvasGraphicsView )
		, m_others_view( new CanvasInvisibleObjectsView )
	{
		setOrientation( Qt::Vertical );
		addWidget( m_graphic_view.get() );
		addWidget( m_others_view.get() );

	}

	CanvasView::~CanvasView()
	{

	}

	void CanvasView::clear()
	{

	}

	void CanvasView::update( const aosl::Canvas& canvas )
	{

	}

}
}