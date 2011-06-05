#ifndef __AOSD_CORE__CONTEXT_HPP__
#define __AOSD_CORE__CONTEXT_HPP__
#pragma once

#include <boost/scoped_ptr.hpp>
#include <boost/filesystem/path.hpp>

#include <QObject>

#include "util/Singleton.hpp"

namespace aosd
{
namespace core
{
    class Project;

    /** Singleton that hold the current context of the application, 
        like the current project to work on and the open sequence.
    */
    class Context
        : public util::Singleton< Context >
        , public QObject
    {
        Q_OBJECT
    public:
        
        /** Create a new empty project and set it as the current project.
            If there was already a project open, it will be closed first.
        */
        void new_project();

        /** Open a project located at the provided path. */
        void open_project( const boost::filesystem::path& project_path );
        
        /** Close the currently open project. */
        void close_project();
        
        /** @return True if there is a project open currently. */
        bool is_project_open() const { return m_project; }

        /** Current project open for edition. */
        const Project& project_open() const { return *m_project; }
        
    signals:

        /** Signal : a project have been open. */
        void on_project_open( const Project& project );

        /** Signal : the currently open project have been modified. */
        void on_project_changed( const Project& project );

        /** Signal : the currently open project will be closed. */
        void on_project_close( const Project& project );
        

    private:

        /// The currently open project or null if none.
        boost::scoped_ptr< Project > m_project;

        /** Open a project that have been loaded. */
        void open_project( Project& project );

    };



}
}


#endif
