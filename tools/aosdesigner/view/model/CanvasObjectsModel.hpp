#ifndef HGUARD_AOSD_VIEW_CANVASOBJECTSMODEL_HPP__
#define HGUARD_AOSD_VIEW_CANVASOBJECTSMODEL_HPP__
#pragma once

#include <map>
#include <QAbstractItemModel>

namespace aosl
{
	class Canvas;
	class Object;
}

namespace aosd
{
namespace view
{

	/** Model representing the trees of Objects in a Canvas.
	**/
	class CanvasObjectsModel
		: public QAbstractItemModel
	{
	public:

		CanvasObjectsModel();
		explicit CanvasObjectsModel( const aosl::Canvas& canvas );
		

		QModelIndex index( int row, int column, const QModelIndex & parent = QModelIndex() ) const;
		QModelIndex parent( const QModelIndex& index ) const;
		Qt::ItemFlags flags( const QModelIndex& index ) const;
		QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const;
		QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;

		int rowCount( const QModelIndex& parent = QModelIndex() ) const;
		int columnCount( const QModelIndex& parent = QModelIndex() ) const;

		void build_registry( const aosl::Canvas& canvas );
		void clear();

		
		
	private:

		struct ObjectInfos
		{
			const aosl::Object* object;
			QModelIndex parent_idx;
		};

		std::map< QModelIndex, ObjectInfos > m_object_registry;

		QModelIndex add( const aosl::Object*, size_t child_idx, QModelIndex parent_index );

		const ObjectInfos* find( QModelIndex index ) const;
	};

}
}


#endif
