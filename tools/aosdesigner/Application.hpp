#ifndef __AOSD_APPLICATION_HPP__
#define __AOSD_APPLICATION_HPP__
#pragma once

#include <boost/scoped_ptr.hpp>

#include <QApplication>

namespace aosd
{
    namespace view
    {
        class MainWindow;
    }
    namespace core
    {
        class Project;
    }
    

    class Application
        : public QApplication
    {
        Q_OBJECT

    public:

        Application( int &argc, char **argv );
        ~Application();

        bool is_project_open() const { return m_project; }

        core::Project& project() { return *m_project; }
        const core::Project& project()  const { return *m_project; }
        
    private:

        boost::scoped_ptr<view::MainWindow> m_main_window;
        boost::scoped_ptr<core::Project> m_project;

    };


}


#endif
