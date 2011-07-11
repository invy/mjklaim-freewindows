#ifndef HGUARD_AOSD_APPLICATION_HPP__
#define HGUARD_AOSD_APPLICATION_HPP__
#pragma once

#include <memory>
#include <QApplication>

#include "core/ForwardCore.hpp"
#include "view/ForwardView.hpp"

namespace aosd
{
	namespace state{ class DesignerStateMachine; }

	/** Application object, provided to Qt to be run and managing the whole state.
	**/
	class Application
		: public QApplication
	{
		Q_OBJECT

	public:

		Application( int &argc, char **argv );
		~Application();

		/** Display the welcome screen in the center of the window. */
		void show_welcome();
		
	private:

		/// Current context informations of the application : opened project, opened sequence, etc.
		std::unique_ptr<core::Context> m_context;

		/// Window of the application.
		std::unique_ptr<view::MainWindow> m_main_window;
		
		std::unique_ptr<state::DesignerStateMachine> m_state_machine;
	};


}


#endif
