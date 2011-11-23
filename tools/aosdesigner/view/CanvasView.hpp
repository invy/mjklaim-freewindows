#ifndef HGUARD_AOSD_VIEW_CANVASVIEW_HPP__
#define HGUARD_AOSD_VIEW_CANVASVIEW_HPP__
#pragma once

#include <memory>
#include <QSplitter>

class QGraphicsView;

namespace aosl
{
	class Canvas;
	class Library;
}

namespace aosd 
{
namespace view
{
	class CanvasGraphicsView;

	/** Display a graphic representation of the canvas of a Sequence 
		at a specific stage of a story being played.
		It allows to edit and move the content of the Canvas for this stage.
	**/
	class CanvasView
		: public QSplitter
	{
		Q_OBJECT
	public:
		
		CanvasView();
		~CanvasView();

	public slots:

		void clear();
		void update( const aosl::Canvas& canvas, const aosl::Library& library );

	private:

		std::unique_ptr<CanvasGraphicsView> m_graphic_view;
		std::unique_ptr<QGraphicsView> m_content_view;

		void initialize_graphic_view();
		void initialize_content_view();


	};


}
}

#endif
