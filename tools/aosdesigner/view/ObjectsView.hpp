#ifndef __AOSD_VIEW_OBJECTSVIEW_HPP__
#define __AOSD_VIEW_OBJECTSVIEW_HPP__
#pragma once

#include <QDockWidget>
#include <QTreeView>

namespace aosd
{
namespace view
{

    class ObjectsView
        : public QDockWidget
    {
        Q_OBJECT
    public:
        
        ObjectsView()
        {
            setWindowTitle( tr("Objects") );
            
            setWidget(new QTreeView());
        }


    private:

    };


}
}

#endif
