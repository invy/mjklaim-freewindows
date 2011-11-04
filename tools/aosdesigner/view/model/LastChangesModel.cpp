#include "LastChangesModel.hpp"

#include <utility>

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
			std::for_each( std::begin(last_move), std::end(last_move), [&]( const aosl::Change& change ){ m_last_changes.push_back(&change); });

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

	}

	QModelIndex LastChangesModel::parent( const QModelIndex& index ) const
	{

	}

	Qt::ItemFlags LastChangesModel::flags( const QModelIndex& index ) const
	{

	}

	QVariant LastChangesModel::data( const QModelIndex& index, int role /*= Qt::DisplayRole */ ) const
	{

	}

	QVariant LastChangesModel::headerData( int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole */ ) const
	{

	}

	bool LastChangesModel::hasChildren( const QModelIndex & parent /*= QModelIndex() */ ) const
	{

	}

	int LastChangesModel::rowCount( const QModelIndex& parent /*= QModelIndex() */ ) const
	{

	}

	int LastChangesModel::columnCount( const QModelIndex& parent /*= QModelIndex() */ ) const
	{

	}

}
}