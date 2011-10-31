#ifndef HGUARD_AOSD_VIEW_LAYEROBJECTSMODEL_HPP__
#define HGUARD_AOSD_VIEW_LAYEROBJECTSMODEL_HPP__
#pragma once

#include <vector>
#include <QAbstractListModel>

namespace aosl
{
	class Layer;
	class Object;
	class Canvas;
}

namespace aosd
{
namespace view
{

	class LayerObjectsModel
		: public QAbstractListModel
	{
		Q_OBJECT
	public:

		LayerObjectsModel();
		explicit LayerObjectsModel( const aosl::Canvas& canvas, const aosl::Layer& layer );
		
		int rowCount( const QModelIndex& parent = QModelIndex() ) const;
		QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const;

		void update( const aosl::Canvas& canvas, const aosl::Layer& layer );
		void clear();


	private:

		std::vector< const aosl::Object* > m_layer_objects;

	};

}
}


#endif
