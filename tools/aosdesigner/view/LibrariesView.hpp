#ifndef __AOSD_VIEW_LIBRARIESVIEW_HPP__
#define __AOSD_VIEW_LIBRARIESVIEW_HPP__
#pragma once

#include <QDockWidget>
#include <QListView>

namespace aosd
{
namespace view
{

    class LibrariesView
        : public QDockWidget
    {
        Q_OBJECT
    public:
        
        LibrariesView()
        {
            setWindowTitle(tr("Libraries"));
            setWidget( new QListView() );
        }


    private:

    };


}
}

#endif
