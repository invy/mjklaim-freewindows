#ifndef __AOSD_VIEW_THREADVIEW_HPP__
#define __AOSD_VIEW_THREADVIEW_HPP__
#pragma once

#include <QGraphicsView>
#include <QDockWidget>

namespace aosd 
{
namespace view
{

    class ThreadView
        : public QDockWidget
    {
        Q_OBJECT
    public:

        ThreadView()
        {
            setWindowTitle( tr("Thread") );
            setWidget( new QGraphicsView() );
        }


    private:

    };


}
}

#endif
