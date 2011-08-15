#include "StoryPathView.hpp"

#include "view/CanvasView.hpp"
#include "view/StoryView.hpp"

namespace aosd
{
namespace view
{
	StoryPathView::StoryPathView()
		: m_canvas_view( new CanvasView )
		, m_story_view( new StoryView )
	{
		setOrientation( Qt::Vertical );

		addWidget( m_canvas_view.get() );
		addWidget( m_story_view.get() );

	}

	StoryPathView::~StoryPathView()
	{

	}




}

}