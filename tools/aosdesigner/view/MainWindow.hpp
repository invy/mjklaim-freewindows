#ifndef __AOSD_VIEW_MAINWINDOW_HPP__
#define __AOSD_VIEW_MAINWINDOW_HPP__
#pragma once

#include <boost/scoped_ptr.hpp>

#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

namespace aosd
{
namespace core
{
    class Project;
}

namespace view
{
    class ProjectView;

    class MainWindow
        : public QMainWindow
    {
        Q_OBJECT
    public:

        MainWindow( QWidget* parent );
        
    private slots:

        void on_project_open( const core::Project& project );

    private:

        boost::scoped_ptr<Ui::MainWindow> m_ui;
        

    };


}
}


#endif
