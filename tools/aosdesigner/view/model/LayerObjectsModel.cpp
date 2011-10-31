#include "LayerObjectsModel.hpp"

#include "utilcpp/Assert.hpp"

#include "aosl/layer.hpp"
#include "aosl/object.hpp"
#include "aosl/canvas.hpp"
#include "aoslcpp/algorithm/find.hpp"

namespace aosd
{
namespace view
{
	

	LayerObjectsModel::LayerObjectsModel()
	{

	}

	LayerObjectsModel::LayerObjectsModel( const aosl::Canvas& canvas, const aosl::Layer& layer )
	{
		update( canvas, layer );
	}

	int LayerObjectsModel::rowCount( const QModelIndex& parent /*= QModelIndex() */ ) const
	{
		return m_layer_objects.size();
	}

	QVariant LayerObjectsModel::data( const QModelIndex& index, int role /*= Qt::DisplayRole */ ) const
	{
		if( !index.isValid() || index.column() > 0 || m_layer_objects.empty() )
			return QVariant();

		auto object = m_layer_objects[ index.row() ];
		UTILCPP_ASSERT_NOT_NULL( object );
		return QString::fromStdString( object->id() );
	}

	void LayerObjectsModel::update( const aosl::Canvas& canvas, const aosl::Layer& layer )
	{
		clear();
		
		const auto& object_list = layer.object();

		std::for_each( object_list.begin(), object_list.end(), [&]( const aosl::Object_ref_element& object_ref )
		{
			auto object = aoslcpp::find_object( canvas, object_ref.id() );
			if( object )
			{
				m_layer_objects.push_back( object );
			}
			else
			{
				UTILCPP_LOG_ERROR << "Couldn't find object '" << object_ref.id() << "' in the canvas. It was referenced by the layer '" << layer.id() << "'!";
			}
			
		});
		
	}

	void LayerObjectsModel::clear()
	{
		m_layer_objects.clear();
	}

}
	

}