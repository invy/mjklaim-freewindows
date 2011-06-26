#ifndef __AOSD_VIEW_TOOLBOXVIEW_HPP__
#define __AOSD_VIEW_TOOLBOXVIEW_HPP__
#pragma once

#include <QDockWidget>
#include <QToolBox>

namespace aosd
{
namespace view
{

    class ToolboxView
        : public QDockWidget
    {
        Q_OBJECT
    public:
        
        ToolboxView()
        {
            setWindowTitle( tr("Toolbox") );
            setWidget( new QToolBox() );
        }


    private:

    };


}
}


#endif
