#ifndef HGUARD_AOSD_VIEW_LIBRARIESVIEW_HPP__
#define HGUARD_AOSD_VIEW_LIBRARIESVIEW_HPP__
#pragma once

#include <QListView>
#include "view/EditionToolView.hpp"

namespace aosd
{
namespace view
{
	/** Display lists of resources for each libraries used in the current sequence.
		Allow editing, adding and removing resources from libraries.
	**/
	class LibrariesView
		: public EditionToolView
	{

		Q_OBJECT
	public:
		
		LibrariesView();

	private:

		void begin_edition_session( const core::EditionSession& edition_session ){}
		void end_edition_session( const core::EditionSession& edition_session ){}
		void connect_edition( const core::EditionSession& edition_session );
		void disconnect_edition( const core::EditionSession& edition_session );


	};


}
}

#endif
