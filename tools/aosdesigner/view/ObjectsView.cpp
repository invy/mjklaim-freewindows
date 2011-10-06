#include "ObjectsView.hpp"

#include <QStandardItemModel>

#include "core/Context.hpp"
#include "core/Project.hpp"
#include "core/EditionSession.hpp"

#include "aoslcpp/algorithm/iterator.hpp"


namespace aosd
{
namespace view
{

	ObjectsView::ObjectsView()
		: m_object_tree_view( new QTreeView() )
	{
		setWindowTitle( tr("Objects") );
		setWidget( m_object_tree_view.get() );
		
	}


	ObjectsView::~ObjectsView()
	{

	}

	void ObjectsView::fill_object_tree( const core::EditionSession& edition_session )
	{
		auto* object_tree = new QStandardItemModel();

		using namespace aoslcpp;

		for( auto it = objects_iterator_depth( edition_session.canvas() ); it != objects_iterator_depth(); ++it )
		{
			const ObjectTreeNodeInfos& info = *it;

			UTILCPP_ASSERT_NOT_NULL( info.object() );
			const auto& object = *info.object();
			auto* item = new QStandardItem( QString::fromStdString( object.id() ) );
			object_tree->insertRow( info.depth(), item );
			
		}

		m_object_tree_view->setModel( object_tree );
	}

	void ObjectsView::clear()
	{
		m_object_tree_view->setModel( new QStandardItemModel() ); // TODO : find a better way to clear it
	}

	void ObjectsView::connect_edition( const core::EditionSession& edition_session )
	{
		// TODO : connect interesting signals
		fill_object_tree( edition_session );
	}

	void ObjectsView::disconnect_edition( const core::EditionSession& edition_session )
	{
		clear();
		// TODO : disconnect interesting signals

		
	}

	



}

}