#ifndef __AOSD_VIEW_PROJECTVIEW_HPP__
#define __AOSD_VIEW_PROJECTVIEW_HPP__
#pragma once

#include <QDockWidget>

namespace aosd
{
namespace view
{

    /** Display the basic informations about a Project and the Sequences it contains.
        It allows to switch from one Sequence to another.
    */
    class ProjectView
        : public QDockWidget
    {
        Q_OBJECT
    public:
        
        ProjectView();
        

    private:

        
    };


}
}


#endif
