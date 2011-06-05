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
    
    class Application
        : public QApplication
    {
        Q_OBJECT

    public:

        Application( int &argc, char **argv );
        ~Application();

        
    private:

        boost::scoped_ptr<view::MainWindow> m_main_window;
        
    };


}


#endif
