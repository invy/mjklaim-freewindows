#ifndef HGUARD_AOSD_VIEW_TOOLBOXVIEW_HPP__
#define HGUARD_AOSD_VIEW_TOOLBOXVIEW_HPP__
#pragma once

#include <QDockWidget>
#include <QToolBox>

namespace aosd
{
namespace view
{
	/** Display tools for edition.
	**/
	class ToolboxView
		: public QDockWidget
	{
		Q_OBJECT
	public:
		
		ToolboxView()
		{
			setWindowTitle( tr("Toolbox") );
			setWidget( new QToolBox() );
		}


	private:

	};


}
}


#endif
