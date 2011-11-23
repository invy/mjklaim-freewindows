#ifndef HGUARD_AOSD_VIEW_CANVASGRAPHICSVIEW_HPP__
#define HGUARD_AOSD_VIEW_CANVASGRAPHICSVIEW_HPP__
#pragma once

#include <memory>
#include <QGraphicsView>

class QGraphicsScene;


namespace aosl
{
	class Canvas;
	class Library;
}


namespace aosd
{
namespace view
{

	/** Display the graphics view of a canvas.
		
	*/
	class CanvasGraphicsView
		: public QGraphicsView
	{
		Q_OBJECT
	public:

		CanvasGraphicsView();
		~CanvasGraphicsView();

	public slots:

			void clear();
			void update( const aosl::Canvas& canvas, const aosl::Library& library );

	private:

		std::unique_ptr<QGraphicsScene> m_scene;
		
	};


}
}


#endif