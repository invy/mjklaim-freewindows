#ifndef __AOSD_VIEW_STORYVIEW_HPP__
#define __AOSD_VIEW_STORYVIEW_HPP__
#pragma once

#include <QGraphicsView>
#include <QDockWidget>

namespace aosd 
{
namespace view
{

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
