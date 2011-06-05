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
namespace view
{
    class ProjectView;

    class MainWindow
        : public QMainWindow
    {
    public:

        MainWindow(QWidget *parent);
        

    private:

        boost::scoped_ptr<Ui::MainWindow> m_ui;

    };


}
}


#endif
