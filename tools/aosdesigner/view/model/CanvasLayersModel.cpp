#include "CanvasLayersModel.hpp"


#include "utilcpp/Assert.hpp"

#include "aosl/layer.hpp"
#include "aosl/canvas.hpp"

namespace aosd
{
namespace view
{
	CanvasLayersModel::CanvasLayersModel()
	{
	}
	
	CanvasLayersModel::CanvasLayersModel( const aosl::Canvas& canvas )
	{
		update( canvas );
	}

	int CanvasLayersModel::rowCount( const QModelIndex& parent /*= QModelIndex() */ ) const
	{
		return m_layers.size();
	}

	QVariant CanvasLayersModel::data( const QModelIndex& index, int role /*= Qt::DisplayRole */ ) const
	{
		if( !index.isValid() || index.column() > 0 || m_layers.empty() )
			return QVariant();
		
		auto layer = m_layers[ index.row() ];
		return QString::fromStdString( layer->id() );
	}

	void CanvasLayersModel::clear()
	{
		m_layers.clear();
	}

	void CanvasLayersModel::update( const aosl::Canvas& canvas )
	{
		if( canvas.layers() )
		{
			const auto& layer_list = canvas.layers()->layer();

			std::for_each( layer_list.begin(), layer_list.end(), [&]( const aosl::Layer& layer )
			{
				m_layers.push_back( &layer );
			});
		}
	}


}
}