#include "CanvasObjectsModel.hpp"

#include <algorithm>

#include "utilcpp/Assert.hpp"

#include "aoslcpp/algorithm/iterator.hpp"
#include "aosl/object.hpp"
#include "aosl/canvas.hpp"

namespace aosd
{
namespace view
{
	CanvasObjectsModel::CanvasObjectsModel()
	{
	}
	
	CanvasObjectsModel::CanvasObjectsModel( const aosl::Canvas& canvas )
	{
		build_registry( canvas );
	}

	void CanvasObjectsModel::build_registry( const aosl::Canvas& canvas )
	{
		using namespace aoslcpp;
		// go through the object tree and register each object

		std::map< const aosl::Object*, QModelIndex > parents;
		std::map< const aosl::Object*, QModelIndex > next_parents;
		size_t last_depth = 0;

		std::for_each( objects_iterator_breadth::begin( canvas ), objects_iterator_breadth::end(), [&]( const ObjectTreeNodeInfos& infos )
		{
			if( last_depth != infos.depth() )
			{
				// get one level deeper, change the parents of the next objects
				parents.swap( next_parents );
				next_parents.clear();
				last_depth = infos.depth();
			}

			QModelIndex parent_idx = parents[ infos.parent() ]; // retrieve the model index of the parent or an invalid index if root

			auto new_index = add( infos.object(), infos.idx(), parent_idx );

			if( infos.object()->children() && !infos.object()->children()->object().empty() )
			{
				// this object will be parent of one or more objects deeper : register it for later
				next_parents.insert( std::make_pair( infos.object(), new_index ) );
			}

		});
	}

	QModelIndex CanvasObjectsModel::add( const aosl::Object* object, size_t child_idx, QModelIndex parent_index )
	{
		UTILCPP_ASSERT_NOT_NULL( object );

		const auto index = createIndex( child_idx, 0, (void*)object );
		UTILCPP_ASSERT( index.isValid(), "Generated an invalid index!" );

		ObjectInfos infos;
		infos.parent_idx = parent_index;
		infos.object = object;

		m_object_registry[ index ] = infos;

		return index;
	}

	void CanvasObjectsModel::clear()
	{
		m_object_registry.clear();
	}


	QModelIndex CanvasObjectsModel::index( int row, int column, const QModelIndex & parent /*= QModelIndex() */ ) const
	{
		UTILCPP_NOT_IMPLEMENTED_YET;
		return QModelIndex();
	}

	QModelIndex CanvasObjectsModel::parent( const QModelIndex & index ) const
	{
		auto infos = find( index );
		if( infos )
		{
			return infos->parent_idx;
		}
		
		return QModelIndex();
	}

	Qt::ItemFlags CanvasObjectsModel::flags( const QModelIndex & index ) const
	{
		auto infos = find( index );
		if( infos )
		{
			return Qt::ItemIsSelectable; // TODO : add flags here if necessary
		}

		return Qt::NoItemFlags;
	}

	QVariant CanvasObjectsModel::data( const QModelIndex & index, int role /*= Qt::DisplayRole */ ) const
	{
		auto infos = find( index );
		if( infos )
		{
			switch( role )
			{
			case( Qt::DisplayRole ):
				{
					return QString::fromStdString( infos->object->id() );
				}
				// TODO : add here other informations possible
			}

		}

		return QVariant();
	}

	QVariant CanvasObjectsModel::headerData( int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole */ ) const
	{
		return QVariant();
	}

	int CanvasObjectsModel::rowCount( const QModelIndex & parent /*= QModelIndex() */ ) const
	{
		auto infos = find( parent );
		if( infos && infos->object->children() )
		{
			return infos->object->children()->object().size();
		}

		return 0;
	}

	const CanvasObjectsModel::ObjectInfos* CanvasObjectsModel::find( QModelIndex index ) const
	{
		auto find_it = m_object_registry.find( index );
		if( find_it != m_object_registry.end() )
		{
			UTILCPP_ASSERT_NOT_NULL( find_it->second.object );
			return &find_it->second;
		}
		return nullptr;
	}

	

}
}