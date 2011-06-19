#ifndef __AOSD_VIEW_CHANGESVIEW_HPP__
#define __AOSD_VIEW_CHANGESVIEW_HPP__
#pragma once

#include <QDockWidget>
#include <QListView>

namespace aosd
{
namespace view
{

    class ChangesView
        : public QDockWidget
    {
        Q_OBJECT
    public:

        ChangesView()
        {
            setWindowTitle( tr("Changes") );
            setWidget( new QListView() );
        }
        
        


    private:

    };


}
}


#endif
