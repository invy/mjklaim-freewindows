#ifndef __AOSD_VIEW_LAYERSVIEW_HPP__
#define __AOSD_VIEW_LAYERSVIEW_HPP__
#pragma once

#include <QDockWidget>
#include <QTreeView>

namespace aosd
{
namespace view
{

    class LayersView
        : public QDockWidget
    {
        Q_OBJECT
    public:
        
        LayersView()
        {
            setWindowTitle(tr("Layers"));
            setWidget( new QTreeView() );
        }


    private:

    };


}
}

#endif
