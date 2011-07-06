#ifndef HGUARD_AOSD_APPLICATION_HPP__
#define HGUARD_AOSD_APPLICATION_HPP__
#pragma once

#include <boost/scoped_ptr.hpp>
#include <QApplication>

#include "core/ForwardCore.hpp"
#include "view/ForwardView.hpp"


namespace aosd
{
	/** Application object, provided to Qt to be run and managing the whole state.
	**/
	class Application
		: public QApplication
	{
		Q_OBJECT

	public:

		Application( int &argc, char **argv );
		~Application();

		
	private:

		/// Current context informations of the application : opened project, opened sequence, etc.
		boost::scoped_ptr<core::Context> m_context;

		/// Window of the application.
		boost::scoped_ptr<view::MainWindow> m_main_window;
		
		
	};


}


#endif
