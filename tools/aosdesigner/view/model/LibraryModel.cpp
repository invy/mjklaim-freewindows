#include "LibraryModel.hpp"

#include <algorithm>

#include "aosl/library.hpp"
#include "aosl/resource.hpp"

#include "utilcpp/Assert.hpp"


namespace aosd
{
namespace view
{


	LibraryModel::LibraryModel()
	{
		
	}

	void LibraryModel::update( const aosl::Library& library )
	{
		clear();

		beginResetModel();
		
		// TODO : this version doesn't take account of imports - LET'S DO THIS!!!!

		const auto& resource_list = library.resources().resource();

		std::for_each( begin(resource_list), end(resource_list), [&]( const aosl::Resource& resource )
		{
			m_resources.push_back( &resource );
		});
		
		endResetModel();
	}

	void LibraryModel::clear()
	{
		beginResetModel();
		m_resources.clear();
		endResetModel();
	}

	QModelIndex LibraryModel::index( int row, int column, const QModelIndex& parent /*= QModelIndex() */ ) const
	{
		if( m_resources.empty() )
			return QModelIndex();

		UTILCPP_ASSERT( !parent.isValid(), "Try to ge the index of child of a resource but it's forbidden!" );

		return createIndex( row, column, (void*)m_resources[row] );
	}

	QModelIndex LibraryModel::parent( const QModelIndex& index ) const
	{
		return QModelIndex();
	}

	Qt::ItemFlags LibraryModel::flags( const QModelIndex& index ) const
	{
		return QAbstractItemModel::flags( index ) | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled;
	}

	QVariant LibraryModel::data( const QModelIndex& index, int role /*= Qt::DisplayRole */ ) const
	{
		if( !index.isValid() || m_resources.empty() )
			return QVariant();

		auto resource = m_resources[ index.row() ];
		UTILCPP_ASSERT_NOT_NULL( resource );

		switch( role )
		{
		case( Qt::DisplayRole ):
			{
				switch( index.column() )
				{
				case 0: return QString::fromStdString( resource->id() );
				case 1: return QString::fromStdString( resource->type() );
				}
			}
		default:
			{
				return QVariant();
			}
		}
	}

	QVariant LibraryModel::headerData( int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole */ ) const
	{
		if( role == Qt::DisplayRole )
		{
			switch( section )
			{
			case 0 : return QString( tr("Resource Id") );
			case 1 : return QString( tr("Resource Type") );
			}
		}

		return QVariant();
	}

	bool LibraryModel::hasChildren( const QModelIndex & parent /*= QModelIndex() */ ) const
	{
		if( parent.isValid() )
		{
			return false;
		}

		return !m_resources.empty();
	}

	int LibraryModel::rowCount( const QModelIndex& parent /*= QModelIndex() */ ) const
	{
		if( parent.isValid() )
		{
			return 0;
		}

		return m_resources.size();
	}

	int LibraryModel::columnCount( const QModelIndex& parent /*= QModelIndex() */ ) const
	{
		return 2;
	}

}
}