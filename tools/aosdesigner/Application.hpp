#ifndef __AOSD_APPLICATION_HPP__
#define __AOSD_APPLICATION_HPP__
#pragma once

#include <memory>

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

        view::MainWindow* m_main_window;

    };


}


#endif
