#include "Editor.hpp"

#include "utilcpp/Log.hpp"

#include <QCloseEvent>
#include <QPushButton>

#include "view/editor/canvas/CanvasView.hpp"
#include "view/editor/story/StoryView.hpp"
#include "core/Context.hpp"
#include "core/Project.hpp"
#include "core/Sequence.hpp"
#include "core/EditionSession.hpp"

namespace aosd
{
namespace view
{
	Editor::Editor( const  core::EditionSession& edition_session )
		: m_canvas_view( new CanvasView )
		, m_story_view( new StoryView )
		, m_title( QString::fromStdString( edition_session.name() ) )
		, m_session_id( edition_session.id() )
		, m_is_closing( false )
	{
		setOrientation( Qt::Vertical );

		addWidget( m_canvas_view.get() );
		addWidget( m_story_view.get() );

		setWindowTitle( m_title );
				
		UTILCPP_LOG << "Created Editor view for edition session \"" << m_title.toStdString() << "\"";

		const auto& project = core::Context::instance().current_project();
		auto sequence = project.find_sequence( edition_session.sequence_id() );
		update( edition_session.canvas(), sequence->library(), project.library() );
	}

	Editor::~Editor()
	{
		UTILCPP_LOG << "Destroyed Editor view for edition session \"" << m_title.toStdString() << "\"";
	}

	
	void Editor::closeEvent( QCloseEvent* closeEvent )
	{
		UTILCPP_ASSERT_NOT_NULL( closeEvent );
		
		m_is_closing = true;

		// the user did close the window : delete the associated session id
		if( core::Context::instance().delete_edition( m_session_id ) )
		{
			QWidget::closeEvent( closeEvent );
		}
		else
		{
			closeEvent->ignore();
		}

		m_is_closing = false;

	}

	void Editor::update( const aosl::Canvas& canvas, const core::Library& sequence_library, const core::Library& project_library )
	{
		m_canvas_view->update( canvas, sequence_library, project_library );
	}


}

}