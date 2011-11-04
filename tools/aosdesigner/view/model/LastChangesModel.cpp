#include "LastChangesModel.hpp"

#include <utility>

#include "utilcpp/Assert.hpp"

#include "aoslcpp/algorithm/find.hpp"
#include "aoslcpp/StoryPath.hpp"
#include "aosl/canvas.hpp"
#include "aosl/change.hpp"
#include "aosl/move.hpp"

namespace aosd
{
namespace view
{
	
	LastChangesModel::LastChangesModel()
	{

	}

	void LastChangesModel::update( const aoslcpp::StoryPath& current_path, const aosl::Canvas& canvas, const aosl::Story& story )
	{
		clear();

		auto last_move = aoslcpp::find_move( story, current_path.last_move() );

		if( last_move )
		{
			beginResetModel();

			const auto& last_changes = last_move->change();
			std::for_each( std::begin(last_changes), std::end(last_changes), [&]( const aosl::Change& change ){ m_last_changes.push_back(&change); });

			endResetModel();
		}

		
	}

	void LastChangesModel::clear()
	{
		beginResetModel();

		m_last_changes.clear();

		endResetModel();
	}

	QModelIndex LastChangesModel::index( int row, int column, const QModelIndex& parent /*= QModelIndex() */ ) const
	{
		if( m_last_changes.empty() )
			return QModelIndex();

		UTILCPP_ASSERT( !parent.isValid(), "Try to ge the index of child of a last change but it's forbidden!" );

		return createIndex( row, column, (void*)m_last_changes[row] );
	}

	QModelIndex LastChangesModel::parent( const QModelIndex& index ) const
	{
		return QModelIndex();
	}

	Qt::ItemFlags LastChangesModel::flags( const QModelIndex& index ) const
	{
		return QAbstractItemModel::flags( index ) | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled;
	}

	QVariant LastChangesModel::data( const QModelIndex& index, int role /*= Qt::DisplayRole */ ) const
	{
		if( !index.isValid() || m_last_changes.empty() )
			return QVariant();

		auto change = m_last_changes[ index.row() ];
		UTILCPP_ASSERT_NOT_NULL( change );

		switch( role )
		{
		case( Qt::DisplayRole ):
			{
				switch( index.column() )
				{
				case 0: return QString::fromStdString( change->type() );
				case 1: return QString::fromStdString( change->object() );
				}
				
			}
		default:
			{
				return QVariant();
			}
		}
	}

	QVariant LastChangesModel::headerData( int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole */ ) const
	{
		if( role == Qt::DisplayRole )
		{
			switch( section )
			{
			case 0 : return QString( tr("Change Type") );
			case 1 : return QString( tr("Object Id") );
			}
		}

		return QVariant();
	}

	bool LastChangesModel::hasChildren( const QModelIndex & parent /*= QModelIndex() */ ) const
	{
		if( parent.isValid() )
		{
			return false;
		}

		return !m_last_changes.empty();
	}

	int LastChangesModel::rowCount( const QModelIndex& parent /*= QModelIndex() */ ) const
	{
		if( parent.isValid() )
		{
			return 0;
		}

		return m_last_changes.size();
	}

	int LastChangesModel::columnCount( const QModelIndex& parent /*= QModelIndex() */ ) const
	{
		return 2;
	}

}
}