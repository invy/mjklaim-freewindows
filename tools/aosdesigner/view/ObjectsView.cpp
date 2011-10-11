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
		
		m_object_tree_view->setModel( &m_model );
	}


	ObjectsView::~ObjectsView()
	{

	}

	void ObjectsView::fill_object_tree( const core::EditionSession& edition_session )
	{
		m_model.build_registry( edition_session.canvas());
	}

	void ObjectsView::clear()
	{
		m_model.clear();
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