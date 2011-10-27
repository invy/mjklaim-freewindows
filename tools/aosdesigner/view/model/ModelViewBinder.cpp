#include "ModelViewBinder.hpp"

#include <QAbstractItemView>

#include "utilcpp/Assert.hpp"

namespace aosd
{
namespace view
{


	ModelViewBinder::ModelViewBinder( QAbstractItemView& viewer )
		: m_view( viewer )
	{

	}

	ModelViewBinder::~ModelViewBinder()
	{

	}

	void ModelViewBinder::add( std::unique_ptr< QAbstractItemModel > model, const core::EditionSessionId& session_id )
	{
		UTILCPP_ASSERT( m_registry.find( session_id ) == m_registry.end(), "Tried to begin edition session already registered : " << session_id );
		m_registry.insert( std::make_pair( session_id, std::move( model ) ) );
	}

	void ModelViewBinder::remove( const core::EditionSessionId& session_id )
	{
		m_registry.erase( session_id );
	}

	void ModelViewBinder::clear()
	{
		m_registry.clear();
		m_view.setModel( nullptr );
	}

	bool ModelViewBinder::load( const core::EditionSessionId& session_id )
	{
		auto model = find( session_id );
		if( model )
		{
			bind_to_view( model );
			return true;
		}
		else
			return false;
	}


	void ModelViewBinder::unload()
	{
		m_view.setModel( nullptr );
	}


	QAbstractItemModel* ModelViewBinder::find( const core::EditionSessionId& session_id )
	{
		auto find_it = m_registry.find( session_id );
		if( find_it != m_registry.end() )
			return find_it->second.get();

		return nullptr;
	}

	void ModelViewBinder::bind_to_view( QAbstractItemModel* model )
	{
		m_view.setModel( model );
	}

}
}