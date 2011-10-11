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
		clear();

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

			UTILCPP_LOG << "Object : "	<< infos.object() 
						//<< "\n\tindex = " << new_index
						<< "\n\tchild idx = " << infos.idx()
						<< "\n\tparent : " << infos.parent()
						//<< "\n\tparent index = " << parent_idx
						;

		});
	}

	QModelIndex CanvasObjectsModel::add( const aosl::Object* object, size_t child_idx, const QModelIndex& parent_index )
	{
		UTILCPP_ASSERT_NOT_NULL( object );

		const auto index = createIndex( child_idx, 0, (void*)object );
		UTILCPP_ASSERT( index.isValid(), "Generated an invalid index!" );

		ObjectInfos infos;
		infos.parent_idx = parent_index;
		infos.object = object;

		m_object_registry[ index ] = infos;
		m_object_indice[ object ] = index;

		if( !parent_index.isValid() )
		{
			// root object, register also separately
			m_root_objects_indice.push_back( index );
		}

		return index;
	}

	void CanvasObjectsModel::clear()
	{
		m_object_registry.clear();
		m_object_indice.clear();
		m_root_objects_indice.clear();
	}
	

	QModelIndex CanvasObjectsModel::index( int row, int column, const QModelIndex& parent /*= QModelIndex() */ ) const
	{
		if( parent.isValid() )
		{
			const aosl::Object* parent_ = static_cast<const aosl::Object*>( parent.internalPointer() );
			if( parent_ && parent_->children() && !parent_->children()->object().empty() )
			{
				UTILCPP_ASSERT( row < parent_->children()->object().size(), "Invalid row/child idx! idx = " << row << " , child count = " << parent_->children()->object().size() );
				return find_index( parent_->children()->object()[ row ] );
			}
			/*
			auto parent_info = find( parent );

			if( parent_info )
			{
				UTILCPP_ASSERT_NOT_NULL( parent_info->object->children() );
				UTILCPP_ASSERT( row < parent_info->object->children()->object().size(), "Invalid row/child idx! idx = " << row << " , child count = " << parent_info->object->children()->object().size() );

				const aosl::Object& target_child = parent_info->object->children()->object()[ row ];
				return find_index( target_child );

			}
			else
			{
				UTILCPP_ASSERT_IMPOSSIBLE( "Parent not found but provided???" )
			}
			*/

		}
		else if( row < m_root_objects_indice.size() ) // maybe a root object?
		{
			return m_root_objects_indice[ row ];
		}

		return QModelIndex();
	}

	QModelIndex CanvasObjectsModel::parent( const QModelIndex& index ) const
	{
		auto infos = find( index );
		if( infos )
		{
			return infos->parent_idx;
		}
		
		return QModelIndex();
	}

	Qt::ItemFlags CanvasObjectsModel::flags( const QModelIndex& index ) const
	{
		/** auto infos = find( index );
		if( infos )
		{
			return Qt::ItemIsSelectable; // TODO : add flags here if necessary
		}

		return Qt::NoItemFlags;
		*/
		return Qt::ItemIsSelectable;
	}

	QVariant CanvasObjectsModel::data( const QModelIndex& index, int role /*= Qt::DisplayRole */ ) const
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
		if( role == Qt::DisplayRole )
		{
			if( section == 0 )
			{
				return QString( tr("Object Id") );
			}
		}

		return QVariant();
	}

	int CanvasObjectsModel::rowCount( const QModelIndex& parent /*= QModelIndex() */ ) const
	{
		if( parent.isValid() )
		{
			auto parent_infos = find( parent );
			if( parent_infos && parent_infos->object->children() )
			{
				return parent_infos->object->children()->object().size();
			}
			else
			{
				return 0; // no child
			}
		}
		else
		{
			return m_root_objects_indice.size(); // root
		}
		
	}

	int CanvasObjectsModel::columnCount( const QModelIndex& parent /*= QModelIndex() */ ) const
	{
		return 1;
	}


	const CanvasObjectsModel::ObjectInfos* CanvasObjectsModel::find( const QModelIndex& index ) const
	{
		auto find_it = m_object_registry.find( index );
		if( find_it != m_object_registry.end() )
		{
			UTILCPP_ASSERT_NOT_NULL( find_it->second.object );
			return &find_it->second;
		}
		return nullptr;
	}

	QModelIndex CanvasObjectsModel::find_index( const aosl::Object& object ) const
	{
		auto find_it = m_object_indice.find( &object );
		if( find_it != m_object_indice.end() )
		{
			return find_it->second;
		}
		return QModelIndex();
	}

	

}
}