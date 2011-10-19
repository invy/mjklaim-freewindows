#include "ObjectsView.hpp"

#include <QStandardItemModel>
#include <QTreeView>

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


	void ObjectsView::connect_edition( const core::EditionSession& edition_session )
	{
		auto model = find_model( edition_session.id() );
		if( model )
			m_object_tree_view->setModel( model );
		else
			begin_model( edition_session );
	}

	void ObjectsView::disconnect_edition( const core::EditionSession& edition_session )
	{
		m_object_tree_view->setModel( nullptr );
	}

	void ObjectsView::begin_edition_session( const core::EditionSession& edition_session )
	{
		begin_model( edition_session );
	}

	void ObjectsView::end_edition_session( const core::EditionSession& edition_session )
	{
		end_model( edition_session.id() );
	}

	CanvasObjectsModel* ObjectsView::find_model( const core::EditionSessionId& edition_id )
	{
		auto find_it = m_model_registry.find( edition_id );
		if( find_it != m_model_registry.end() )
			return find_it->second.get();

		return nullptr;
	}

	void ObjectsView::begin_model( const core::EditionSession& edition_session )
	{
		UTILCPP_ASSERT( m_model_registry.find( edition_session.id() ) == m_model_registry.end(), "Tried to begin edition session already registered : " << edition_session.id() );
		m_model_registry.insert( std::make_pair( edition_session.id(), std::unique_ptr<CanvasObjectsModel>( new CanvasObjectsModel( edition_session.canvas() ) ) ) );
	}

	void ObjectsView::end_model( const core::EditionSessionId& edition_id )
	{
		m_model_registry.erase( edition_id );
	}

	



}

}