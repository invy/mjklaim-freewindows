#include "Editor.hpp"

#include "utilcpp/Log.hpp"

#include "view/CanvasView.hpp"
#include "view/StoryView.hpp"
#include "core/Context.hpp"
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
		, m_objects_model( edition_session.canvas() )
	{
		setOrientation( Qt::Vertical );

		addWidget( m_canvas_view.get() );
		addWidget( m_story_view.get() );

		connect_edition( edition_session );

	}

	Editor::~Editor()
	{

	}

	void Editor::connect_edition( const core::EditionSession& edition_session )
	{

	}

	void Editor::showEvent( QShowEvent* event )
	{
		QWidget::showEvent( event );

		core::Context::instance().select_edition_session( m_session_id );

	}

	void Editor::hideEvent( QHideEvent* event )
	{
		QWidget::hideEvent( event );

	}




}

}