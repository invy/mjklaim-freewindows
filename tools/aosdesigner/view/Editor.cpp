#include "Editor.hpp"

#include "utilcpp/Log.hpp"

#include <QSplitter>
#include <QCloseEvent>

#include "view/CanvasView.hpp"
#include "view/StoryView.hpp"
#include "core/Context.hpp"
#include "core/EditionSession.hpp"

namespace aosd
{
namespace view
{
	Editor::Editor( const  core::EditionSession& edition_session )
		: m_splitter( new QSplitter )
		, m_canvas_view( new CanvasView )
		, m_story_view( new StoryView )
		, m_title( QString::fromStdString( edition_session.name() ) )
		, m_session_id( edition_session.id() )
		, m_is_closing( false )
	{
		m_splitter->setOrientation( Qt::Vertical );

		m_splitter->addWidget( m_canvas_view.get() );
		m_splitter->addWidget( m_story_view.get() );

		setWidget( m_splitter.get() );
		setWindowTitle( m_title );

		setAttribute( Qt::WA_DeleteOnClose, true ); // destroy this editor once closed by the user

		connect( this, SIGNAL( windowStateChanged( Qt::WindowStates, Qt::WindowStates ) ), this, SLOT( react_state_changed( Qt::WindowStates, Qt::WindowStates ) ) );
		
		UTILCPP_LOG << "Created Editor view for edition session \"" << m_title.toStdString() << "\"";
	}

	Editor::~Editor()
	{
		UTILCPP_LOG << "Destroyed Editor view for edition session \"" << m_title.toStdString() << "\"";
	}

	void Editor::react_state_changed( Qt::WindowStates oldState, Qt::WindowStates newState )
	{
		if( newState & Qt::WindowActive // if active...
		&&	oldState ^ Qt::WindowActive // and was not active before
		)
		{
			core::Context::instance().select_edition_session( m_session_id );
		}

	}

	void Editor::closeEvent( QCloseEvent* closeEvent )
	{
		// if the user did close this window, we need to delete the edition session
		if( core::Context::instance().delete_edition( m_session_id ) )
		{
			QMdiSubWindow::closeEvent( closeEvent );
		}
		else
		{
			closeEvent->ignore();
		}
	}



}

}