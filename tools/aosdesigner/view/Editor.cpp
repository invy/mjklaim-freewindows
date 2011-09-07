#include "Editor.hpp"

#include "view/CanvasView.hpp"
#include "view/StoryView.hpp"
#include "core/EditionSession.hpp"

namespace aosd
{
namespace view
{
	Editor::Editor( const  core::EditionSession& edition_session )
		: m_canvas_view( new CanvasView )
		, m_story_view( new StoryView )
		, m_title( QString::fromStdString( edition_session.name() ) )
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




}

}