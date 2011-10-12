#ifndef HGUARD_AOSD_EDITOR_HPP__
#define HGUARD_AOSD_EDITOR_HPP__
#pragma once

#include <memory>
#include <string>
#include <QWidget>
#include <QSplitter>

#include "core/EditionSessionId.hpp"

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
		: public QSplitter // THINK : maybe a QDockWidget + setCentralWidget( new QSplitter() ) might be better?
	{
		Q_OBJECT
	public:
		
		explicit Editor( const core::EditionSession& edition_session );
		~Editor();

		const QString& title() const { return m_title; }

		const core::EditionSessionId& session_id() const { return m_session_id; }


	private slots:

		void showEvent( QShowEvent* event );
		void hideEvent( QHideEvent* event );


	private:
				
		std::unique_ptr<CanvasView> m_canvas_view;
		std::unique_ptr<StoryView> m_story_view;


		QString m_title;
		core::EditionSessionId m_session_id;
		
		void connect_edition( const core::EditionSession& edition_session );
		
	};

}
}


#endif