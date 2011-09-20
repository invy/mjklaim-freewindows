#ifndef HGUARD_AOSD_VIEW_CHANGESVIEW_HPP__
#define HGUARD_AOSD_VIEW_CHANGESVIEW_HPP__
#pragma once

#include <QListView>
#include "view/EditionToolView.hpp"

namespace aosd
{
namespace view
{
	/** Display lists of changes between the current story stage and the previous one.
	**/
	class ChangesView
		: public EditionToolView
	{
		Q_OBJECT
	public:

		ChangesView();
		
	private:

		void connect_edition( const core::EditionSession& edition_session );
		void disconnect_edition( const core::EditionSession& edition_session );


	};


}
}


#endif
