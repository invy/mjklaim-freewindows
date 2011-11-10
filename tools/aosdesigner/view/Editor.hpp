#ifndef HGUARD_AOSD_EDITOR_HPP__
#define HGUARD_AOSD_EDITOR_HPP__
#pragma once

#include <memory>
#include <string>
#include <QSplitter>

#include "core/EditionSessionId.hpp"

class QSplitter;
class QDockWidget;
class QMdiSubWindow;

namespace aosd
{
	namespace core{ class EditionSession; }

namespace view
{

	class CanvasView;
	class StoryView;

	/** Display the canvas and the story structure view for a specific path through the stages.
		Every information displayed is dependent on the path followed in the sequence.
	*/
	class Editor
		: public QSplitter
	{
		Q_OBJECT
	public:
		
		explicit Editor( const core::EditionSession& edition_session );
		~Editor();

		QString title() const { return m_title; }

		core::EditionSessionId session_id() const { return m_session_id; }

		bool is_closing() const { return m_is_closing; }
		bool is_inside() const { return m_is_inside; }

		QWidget& window_inside();
		QWidget& window_outside();
		QWidget& current_window();

	private slots:

		void react_state_changed( Qt::WindowStates oldState, Qt::WindowStates newState );

		void switch_side();
		void move_inside();
		void move_outside();

	private:
		
		std::unique_ptr<CanvasView> m_canvas_view;
		std::unique_ptr<StoryView> m_story_view;

		std::unique_ptr<QMdiSubWindow> m_window_inside;
		std::unique_ptr<QDockWidget> m_window_outside;

		QString m_title;
		core::EditionSessionId m_session_id;

		bool m_is_closing;
		bool m_is_inside;
		
		/** We need to delete the edition session when closed. */
		void closeEvent( QCloseEvent* closeEvent );

		
	};

}
}


#endif