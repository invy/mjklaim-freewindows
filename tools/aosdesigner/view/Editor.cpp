#include "Editor.hpp"

#include "utilcpp/Log.hpp"

#include <QCloseEvent>
#include <QMdiSubWindow>
#include <QDockWidget>
#include <QPushButton>

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
		, m_window_inside( new QMdiSubWindow )
		, m_window_outside( new QDockWidget )
		, m_title( QString::fromStdString( edition_session.name() ) )
		, m_session_id( edition_session.id() )
		, m_is_closing( false )
		, m_is_inside( true )
	{
		setOrientation( Qt::Vertical );

		addWidget( m_canvas_view.get() );
		addWidget( m_story_view.get() );

		m_window_inside->hide();
		m_window_outside->hide();

		auto switch_button = new QPushButton();
		connect( switch_button, SIGNAL( pressed() ), this, SLOT( switch_side() )  );
		addWidget( switch_button );

		setWindowTitle( m_title );

		setAttribute( Qt::WA_DeleteOnClose ); // make sure this editor will be automatically deleted if closed - not if removed from the main window

		connect( m_window_inside.get(), SIGNAL( windowStateChanged( Qt::WindowStates, Qt::WindowStates ) ), this, SLOT( react_state_changed( Qt::WindowStates, Qt::WindowStates ) ) );
		
		move_inside();

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

	void Editor::move_inside()
	{
		m_window_outside->setWidget(nullptr);
		m_window_outside->hide();

		m_window_inside->setWidget( this );
		m_window_inside->show();
		show();

		m_is_inside = true;
	}

	void Editor::move_outside()
	{
		m_window_inside->setWidget(nullptr);
		m_window_inside->hide();

		m_window_outside->setWidget( this );
		m_window_outside->show();
		show();

		m_is_inside = false;
	}

	void Editor::switch_side()
	{
		if( is_inside() )
			move_outside();
		else
			move_inside();
	}

	QWidget& Editor::window_inside()
	{
		return *m_window_inside;
	}

	QWidget& Editor::window_outside()
	{
		return *m_window_outside;
	}

	QWidget& Editor::current_window()
	{
		if( is_inside() )
			return window_inside();
		else
			return window_outside();
	}


}

}