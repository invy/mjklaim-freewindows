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
		const auto& context = core::Context::instance();

		connect( &context, SIGNAL( project_open( const core::Project& ) ), this, SLOT( react_project_open( const core::Project& ) ) );
		connect( &context, SIGNAL( project_closed( const core::Project& ) ), this, SLOT( react_project_closed( const core::Project& ) ) );
	}

	view::EditionToolView::~EditionToolView()
	{

	}

	void view::EditionToolView::react_project_open( const core::Project& project )
	{
		connect( &project, SIGNAL( edition_selected( const core::EditionSession& ) ), this, SLOT( react_edition_selected( const core::EditionSession& ) ) );
		connect( &project, SIGNAL( edition_deselected( const core::EditionSession& ) ), this, SLOT( react_edition_deselected( const core::EditionSession& ) ) );

	}

	void view::EditionToolView::react_project_closed( const core::Project& project )
	{
		disconnect( &project, SIGNAL( edition_deselected( const core::EditionSession& ) ), this, SLOT( react_edition_deselected( const core::EditionSession& ) ) );
		disconnect( &project, SIGNAL( edition_selected( const core::EditionSession& ) ), this, SLOT( react_edition_selected( const core::EditionSession& ) ) );

	}

	void view::EditionToolView::react_edition_selected( const core::EditionSession& edition_session )
	{
		connect_edition( edition_session );
		activate();
	}

	void view::EditionToolView::react_edition_deselected( const core::EditionSession& edition_session )
	{
		disconnect_edition( edition_session );
		deactivate();
	}

	void view::EditionToolView::activate()
	{
		setEnabled( true );
		setVisible( true );
	}

	void view::EditionToolView::deactivate()
	{
		setEnabled( false );
		setVisible( false );
	}

}
}