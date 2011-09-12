#include "ObjectsView.hpp"

#include <QStandardItemModel>

#include "core/Context.hpp"
#include "core/Project.hpp"
#include "core/EditionSession.hpp"


namespace aosd
{
namespace view
{

	ObjectsView::ObjectsView()
		: m_object_tree_view( new QTreeView() )
	{
		setVisible( false );
		setWindowTitle( tr("Objects") );

		setWidget( m_object_tree_view.get() );
		

		const auto& context = core::Context::instance();

		connect( &context, SIGNAL( project_open( const core::Project& ) ), this, SLOT( react_project_open( const core::Project& ) ) );
		connect( &context, SIGNAL( project_closed( const core::Project& ) ), this, SLOT( react_project_closed( const core::Project& ) ) );

	}


	ObjectsView::~ObjectsView()
	{

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
		connect_edition( edition_session );
		fill_object_tree( edition_session );
		activate();
	}

	void ObjectsView::react_edition_deselected( const core::EditionSession& edition_session )
	{
		disconnect_edition( edition_session );
		deactivate();
		clear();
	}

	void ObjectsView::activate()
	{
		setEnabled( true );
		setVisible( true );
	}

	void ObjectsView::deactivate()
	{
		setEnabled( false );
		setVisible( false );
	}

	void ObjectsView::fill_object_tree( const core::EditionSession& edition_session )
	{
		auto* object_tree = new QStandardItemModel();

		unsigned int row = 0;
		edition_session.foreach_object( [&]( const aosl::Object& object )
		{
			auto* item = new QStandardItem( QString::fromStdString( object.id() ) );
			object_tree->insertRow( row, item );
			++ row;
		});

		m_object_tree_view->setModel( object_tree );
	}

	void ObjectsView::clear()
	{
		m_object_tree_view->setModel( new QStandardItemModel() ); // TODO : find a better way to clear it
	}

	void ObjectsView::connect_edition( const core::EditionSession& edition_session )
	{
		// TODO : connect interesting signals
	}

	void ObjectsView::disconnect_edition( const core::EditionSession& edition_session )
	{
		// TODO : disconnect interesting signals
	}

	



}

}