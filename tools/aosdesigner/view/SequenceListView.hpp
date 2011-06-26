#ifndef __AOSD_VIEW_SEQUENCELISTVIEW_HPP__
#define __AOSD_VIEW_SEQUENCELISTVIEW_HPP__
#pragma once

#include <utility>

#include <QListView>
#include <QStringListModel>

class QListView;

namespace aosd
{
namespace core
{
    class Project;
}
namespace view
{

    /** Display the list of Sequences in the currently open project
        and allow selection of the current Sequence to display.
    */
    class SequenceListView
        : public QListView
    {
        Q_OBJECT
    public:
        
        /** Constructor. */
        SequenceListView();

    private slots:

        void on_project_changed( const core::Project& );
        void on_project_open( const core::Project& );
        void on_project_closed( const core::Project& );

    private:

        QStringListModel m_string_list;

        /** Read the Sequences in the provided project and retrieve their data
            to be displayed in this widget.
        */
        void read_sequences( const core::Project& project );

        /** Clear the displayed infos. */
        void clear();

    };



}
}


#endif
