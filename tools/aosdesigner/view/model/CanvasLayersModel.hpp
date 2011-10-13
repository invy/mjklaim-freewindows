#ifndef HGUARD_AOSD_VIEW_CANVASLAYERSMODEL_HPP__
#define HGUARD_AOSD_VIEW_CANVASLAYERSMODEL_HPP__
#pragma once

#include <map>
#include <vector>
#include <QAbstractListModel>

#include "aoslcpp/algorithm/iterator.hpp"

namespace aosl
{
	class Canvas;
	class Object;
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
		
	private:

	};

}
}


#endif
