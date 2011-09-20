#include "EditionToolView.hpp"

#include "core/Context.hpp"
#include "core/Project.hpp"
#include "core/EditionSession.hpp"

namespace aosd
{
namespace view
{


	view::EditionToolView::EditionToolView()
	{
		setAttribute( Qt::WA_ShowWithoutActivating ); // THINK : should it be child class relative?
		deactivate();

		const auto& context = core::Context::instance();

		connect( &context, SIGNAL( project_open( const core::Project& ) ), this, SLOT( react_project_open( const core::Project& ) ) );
		connect( &context, SIGNAL( project_closed( const core::Project& ) ), this, SLOT( react_project_closed( const core::Project& ) ) );

		if( context.is_project_open() )
			react_project_open( context.current_project() );
	}

	view::EditionToolView::~EditionToolView()
	{

	}

	void view::EditionToolView::react_project_open( const core::Project& project )
	{
		connect( &project, SIGNAL( edition_begin() ), this, SLOT( react_edition_begin() ) );
		connect( &project, SIGNAL( edition_end() ), this, SLOT( react_edition_end() ) );

		connect( &project, SIGNAL( edition_selected( const core::EditionSession& ) ), this, SLOT( react_edition_selected( const core::EditionSession& ) ) );
		connect( &project, SIGNAL( edition_deselected( const core::EditionSession& ) ), this, SLOT( react_edition_deselected( const core::EditionSession& ) ) );
		
	}

	void view::EditionToolView::react_project_closed( const core::Project& project )
	{
		disconnect( &project, 0, this, 0 );
	}

	void EditionToolView::react_edition_begin()
	{
		activate();
	}

	void EditionToolView::react_edition_end()
	{
		deactivate();
	}


	void view::EditionToolView::react_edition_selected( const core::EditionSession& edition_session )
	{
		connect_edition( edition_session );
	}

	void view::EditionToolView::react_edition_deselected( const core::EditionSession& edition_session )
	{
		disconnect_edition( edition_session );
	}

	void  view::EditionToolView::change_state( bool is_active )
	{
		setVisible( is_active );
		setEnabled( is_active );
			
	}


	
}
}