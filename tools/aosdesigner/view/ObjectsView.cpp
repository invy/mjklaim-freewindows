#include "ObjectsView.hpp"

#include "core/Context.hpp"
#include "core/Project.hpp"
#include "core/EditionSession.hpp"


namespace aosd
{
namespace view
{



	ObjectsView::ObjectsView()
	{
		setVisible( false );
		setWindowTitle( tr("Objects") );

		setWidget(new QTreeView());

		const auto& context = core::Context::instance();

		connect( &context, SIGNAL( project_open( const core::Project& ) ), this, SLOT( react_project_open( const core::Project& ) ) );
		connect( &context, SIGNAL( project_closed( const core::Project& ) ), this, SLOT( react_project_closed( const core::Project& ) ) );

	}

	void ObjectsView::react_project_open( const core::Project& project )
	{
		connect( &project, SIGNAL( edition_selected( const core::EditionSession& ) ), this, SLOT( react_edition_selected( const core::EditionSession& ) ) );
		connect( &project, SIGNAL( edition_deselected( const core::EditionSession& ) ), this, SLOT( react_edition_deselected( const core::EditionSession& ) ) );

	}

	void ObjectsView::react_project_closed( const core::Project& project )
	{
		disconnect( &project, SIGNAL( edition_deselected( const core::EditionSession& ) ), this, SLOT( react_edition_deselected( const core::EditionSession& ) ) );
		disconnect( &project, SIGNAL( edition_selected( const core::EditionSession& ) ), this, SLOT( react_edition_selected( const core::EditionSession& ) ) );

	}


	void ObjectsView::react_edition_selected( const core::EditionSession& edition_session )
	{
		UTILCPP_LOG << "Objects READ : " << edition_session.name();
	}

	void ObjectsView::react_edition_deselected( const core::EditionSession& edition_session )
	{
		UTILCPP_LOG << "Objects CLEAR : " << edition_session.name();
	}

	



}

}