#include "StoryPathView.hpp"

#include "view/CanvasView.hpp"
#include "view/StoryView.hpp"
#include "core/StoryWalker.hpp"

namespace aosd
{
namespace view
{
	StoryPathView::StoryPathView( const  core::StoryWalker& storywalker )
		: m_canvas_view( new CanvasView )
		, m_story_view( new StoryView )
	{
		setOrientation( Qt::Vertical );

		addWidget( m_canvas_view.get() );
		addWidget( m_story_view.get() );

		connect_storywalker( storywalker );

	}

	StoryPathView::~StoryPathView()
	{

	}

	void StoryPathView::connect_storywalker( const core::StoryWalker& storywalker )
	{

	}




}

}