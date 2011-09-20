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
		virtual ~EditionToolView();

		void activate() { change_state( true ); }
		void deactivate()  { change_state( false ); }

		virtual void connect_edition( const core::EditionSession& edition_session ) = 0;
		virtual void disconnect_edition( const core::EditionSession& edition_session ) = 0;

	
	private slots:

		void react_project_open( const core::Project& );
		void react_project_closed( const core::Project& );

		void react_edition_begin();
		void react_edition_end();

		void react_edition_selected( const core::EditionSession& edition_session );
		void react_edition_deselected( const core::EditionSession& edition_session );
		
	private:
		
		void change_state( bool is_active );

	};

}
}


#endif
