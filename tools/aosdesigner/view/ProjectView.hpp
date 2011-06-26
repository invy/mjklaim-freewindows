#ifndef __AOSD_VIEW_PROJECTVIEW_HPP__
#define __AOSD_VIEW_PROJECTVIEW_HPP__
#pragma once

#include <boost/scoped_ptr.hpp>
#include <QDockWidget>

class QTabWidget;

namespace aosd
{
namespace view
{
    class SequenceListView;

    /** Display the basic informations about a Project and the Sequences it contains.
        It allows to switch from one Sequence to another.
    */
    class ProjectView
        : public QDockWidget
    {
        Q_OBJECT
    public:
        
        ProjectView();
        
    
    private slots:

    private:
        
        boost::scoped_ptr<QTabWidget> m_tabs;
        
    };


}
}


#endif
