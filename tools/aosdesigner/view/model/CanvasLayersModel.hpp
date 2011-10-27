#ifndef HGUARD_AOSD_VIEW_CANVASLAYERSMODEL_HPP__
#define HGUARD_AOSD_VIEW_CANVASLAYERSMODEL_HPP__
#pragma once

#include <vector>
#include <QAbstractListModel>

namespace aosl
{
	class Layer;
	class Canvas;
}

namespace aosd
{
namespace view
{

	/** Model representing the Layers and their state in a Canvas.
	**/
	class CanvasLayersModel
		: public QAbstractListModel
	{
		Q_OBJECT
	public:

		CanvasLayersModel();
		explicit CanvasLayersModel( const aosl::Canvas& canvas );

		int rowCount( const QModelIndex& parent = QModelIndex() ) const;
		QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const;

		void update( const aosl::Canvas& canvas );
		void clear();
		
	private:

		std::vector< const aosl::Layer* > m_layers;

	};

}
}


#endif
