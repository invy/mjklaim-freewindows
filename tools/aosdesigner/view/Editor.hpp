#ifndef HGUARD_AOSD_EDITOR_HPP__
#define HGUARD_AOSD_EDITOR_HPP__
#pragma once

#include <memory>
#include <string>
#include <QMdiSubWindow>

#include "core/EditionSessionId.hpp"

class QSplitter;

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
		: public QMdiSubWindow
	{
		Q_OBJECT
	public:
		
		explicit Editor( const core::EditionSession& edition_session );
		~Editor();

		QString title() const { return m_title; }

		core::EditionSessionId session_id() const { return m_session_id; }

		bool is_closing() const { return m_is_closing; }

	private slots:

		void react_state_changed( Qt::WindowStates oldState, Qt::WindowStates newState );

	private:
				
		std::unique_ptr<QSplitter> m_splitter;
		std::unique_ptr<CanvasView> m_canvas_view;
		std::unique_ptr<StoryView> m_story_view;


		QString m_title;
		core::EditionSessionId m_session_id;

		bool m_is_closing;
		
		/** We need to delete the edition session when closed. */
		void closeEvent( QCloseEvent* closeEvent );
	};

}
}


#endif