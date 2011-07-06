#ifndef HGUARD_AOSD_VIEW_STORYVIEW_HPP__
#define HGUARD_AOSD_VIEW_STORYVIEW_HPP__
#pragma once

#include <QGraphicsView>
#include <QDockWidget>

namespace aosd 
{
namespace view
{
	/** Display a schematic graph of the story structure.
		Allows moving from stage to stage, editing, adding and removing stages
		and other story manipulations.
	**/
	class StoryView
		: public QDockWidget
	{
		Q_OBJECT
	public:

		StoryView()
		{
			setWindowTitle( tr("Story") );
			setWidget( new QGraphicsView() );
		}


	private:

	};


}
}

#endif
