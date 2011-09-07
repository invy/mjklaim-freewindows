#ifndef HGUARD_AOSD_STORYPATHVIEW_HPP__
#define HGUARD_AOSD_STORYPATHVIEW_HPP__
#pragma once

#include <memory>
#include <string>
#include <QWidget>
#include <QSplitter>

namespace aosd
{
	namespace core{ class StoryWalker; }

namespace view
{

	class CanvasView;
	class StoryView;

	/** Display the canvas and the story structure view for a specific path through the stages.
		
	*/
	class StoryPathView
		: public QSplitter
	{
		Q_OBJECT
	public:
		
		explicit StoryPathView( const core::StoryWalker& storywalker );
		~StoryPathView();

		const QString& title() const { return m_title; }

	private:
				
		std::unique_ptr<CanvasView> m_canvas_view;
		std::unique_ptr<StoryView> m_story_view;

		QString m_title;

		
		void connect_storywalker( const core::StoryWalker& storywalker );
		
	};

}
}


#endif