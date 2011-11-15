#ifndef HGUARD_AOSD_VIEW_FREEWINDOW_HPP__
#define HGUARD_AOSD_VIEW_FREEWINDOW_HPP__
#pragma once

#include <memory>
#include <QObject>

class QWidget;
class QAction;
class QMdiSubWindow;

namespace aosd
{
namespace view
{

	/** Window that can automatically switch from inside an MDI area to outside it.
	**/
	class FreeWindow
		: public QObject
	{
		Q_OBJECT

		

	public:

		typedef QMdiSubWindow	WindowInside;
		typedef QWidget			WindowOutside;
		
		explicit FreeWindow( QWidget& widget );
		~FreeWindow();

		WindowInside& window_inside() { return *m_window_inside; }
		WindowOutside& window_outside() { return m_widget; }

		void go_inside();
		void go_outside();

	private slots:

		void react_get_inside();
		void react_get_outside();
		
	private:

		QWidget& m_widget;

		std::unique_ptr<WindowInside> m_window_inside;

		std::unique_ptr<QAction> m_float_action;
		std::unique_ptr<QAction> m_dock_action;

		void initialize_inside_window();
		void terminate_inside_window();

		void initialize_outside_window();
		void terminate_outside_window();

	};

}
}


#endif
