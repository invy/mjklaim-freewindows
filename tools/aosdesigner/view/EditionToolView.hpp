#ifndef HGUARD_AOSD_VIEW_EDITIONTOOLVIEW_HPP__
#define HGUARD_AOSD_VIEW_EDITIONTOOLVIEW_HPP__
#pragma once

#include <QDockWidget>

namespace aosd
{

namespace core
{
	class Project;
	class EditionSession;
}

namespace view
{
	class EditionToolView
		: public QDockWidget
	{
		Q_OBJECT
	protected:
		
		EditionToolView();
		~EditionToolView();
	
	private slots:

		virtual void react_project_open( const core::Project& );
		virtual void react_project_closed( const core::Project& );

		virtual void react_edition_selected( const core::EditionSession& edition_session );
		virtual void react_edition_deselected( const core::EditionSession& edition_session );

	protected:

		virtual void activate();
		virtual void deactivate();

		virtual void connect_edition( const core::EditionSession& edition_session ) = 0;
		virtual void disconnect_edition( const core::EditionSession& edition_session ) = 0;



	};

}
}


#endif
