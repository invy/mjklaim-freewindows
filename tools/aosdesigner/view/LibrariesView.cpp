#include "LibrariesView.hpp"

#include <QSplitter>
#include <QTreeView>

#include "core/Context.hpp"
#include "core/Project.hpp"
#include "core/Sequence.hpp"
#include "core/EditionSession.hpp"
#include "core/Sequence.hpp"
#include "view/model/LibraryModel.hpp"

namespace aosd
{
namespace view
{

	LibrariesView::LibrariesView()
		: m_splitter( new QSplitter )
		, m_project_library_view( new QTreeView )
		, m_sequence_library_view( new QTreeView )
		, m_project_library_model( new LibraryModel )
		, m_sequence_model_view_binder( *m_sequence_library_view )
	{
		setWindowTitle( tr("Libraries") );
		m_sequence_library_view->setWindowTitle( tr( "Sequence Library" ) );
		m_project_library_view->setWindowTitle( tr( "Project Library" ) );


		m_project_library_view->setModel( m_project_library_model.get() );

		m_splitter->setOrientation( Qt::Vertical );
		m_splitter->addWidget( m_sequence_library_view.get() );
		m_splitter->addWidget( m_project_library_view.get() );
		setWidget( m_splitter.get() );
	}

	void LibrariesView::connect_edition( const core::EditionSession& edition_session )
	{
		if( m_sequence_model_view_binder.current_id() != edition_session.sequence_id() )
		{
			m_sequence_model_view_binder.load( edition_session.sequence_id() );
		}
	}

	void LibrariesView::disconnect_edition( const core::EditionSession& edition_session )
	{
		m_sequence_model_view_binder.unload();
	}

	void LibrariesView::connect_project( const core::Project& project )
	{
		m_project_library_model->update( project.library() );

		project.foreach_sequence( [&](const core::Sequence& sequence )
		{
			add_sequence_library( sequence );
		});
	}

	void LibrariesView::disconnect_project( const core::Project& project )
	{
		m_project_library_model->clear();
	}

	void LibrariesView::begin_edition_session( const core::EditionSession& edition_session )
	{
		if( m_sequence_model_view_binder.find( edition_session.sequence_id() ) == nullptr )
		{
			auto sequence = core::Context::instance().current_project().find_sequence( edition_session.sequence_id() );

			UTILCPP_ASSERT_NOT_NULL( sequence );
			UTILCPP_ASSERT_NOT_NULL( sequence->library() );
			UTILCPP_ASSERT( sequence->id() == edition_session.sequence_id(), "Sequence found with an id doesn't contain the same Id???? "
				<<	" Find id : " << edition_session.sequence_id()
				<<  " Got id : " << sequence->id() 
				);

			add_sequence_library( *sequence );
		}
		

	}

	void LibrariesView::end_edition_session( const core::EditionSession& edition_session )
	{
		const auto& project = core::Context::instance().current_project();

		bool no_more_edition_for_this_sequence = true;

		project.foreach_edition( [&]( const core::EditionSession& other_session )
		{
			if(	&other_session != &edition_session
			&&	other_session.sequence_id() == edition_session.sequence_id() 
			)
			{
				no_more_edition_for_this_sequence = false;
			}
		});

		if( no_more_edition_for_this_sequence )
			m_sequence_model_view_binder.remove( edition_session.sequence_id() );
	}

	void LibrariesView::add_sequence_library( const core::Sequence& sequence )
	{
		auto model = std::unique_ptr<LibraryModel>( new LibraryModel() );
		model->update( *sequence.library() );

		m_sequence_model_view_binder.add( std::move(model), sequence.id() );
		m_sequence_model_view_binder.load( sequence.id() );
	}


}

}