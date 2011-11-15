#ifndef HGUARD_AOSD_VIEW_FREEWINDOW_HPP__
#define HGUARD_AOSD_VIEW_FREEWINDOW_HPP__
#pragma once

#include <memory>
#include <QObject>

class QWidget;
class QDockWidget;
class QMdiSubWindow;
class QWidget;

namespace aosd
{
namespace view
{

	/** Window that can automatically switch from inside an MDI area to outside it.
	**/
	class FreeWindow
		: public QObject
	{
		Q_OBJECT;
	public:
		
		explicit FreeWindow( QWidget& widget );
		~FreeWindow();

		QMdiSubWindow& window_inside() { return *m_window_inside; }
		QDockWidget& window_outside() { return *m_window_outside; }

		void go_inside();
		void go_outside();

	private slots:

		void react_get_inside();
		void react_get_outside();
		
	private:

		QWidget& m_widget;

		std::unique_ptr<QMdiSubWindow> m_window_inside;
		std::unique_ptr<QDockWidget> m_window_outside;

		void setup_inside_window();
		void setup_outside_window();

	};

}
}


#endif
