#include "LayersView.hpp"

#include <QSplitter>
#include <QTreeView>

#include "core/EditionSession.hpp"
#include "view/model/CanvasLayersModel.hpp"
#include "view/model/LayerObjectsModel.hpp"

namespace aosd
{
namespace view
{
	 
	LayersView::LayersView()
		: m_splitter( new QSplitter() )
		, m_layer_list_view( new QTreeView() )
		, m_layer_objects_view( new QTreeView() )
		, m_layer_model_binder( *m_layer_list_view )
		, m_layer_objects_model( new LayerObjectsModel() )
	{
		setWindowTitle(tr("Layers"));

		m_layer_objects_view->setModel( m_layer_objects_model.get() );
		connect( m_layer_objects_view.get(), SIGNAL( clicked( const QModelIndex& ) ), this, SLOT( react_layer_clicked( const QModelIndex& ) ) );

		m_splitter->setOrientation( Qt::Vertical );
		m_splitter->addWidget( m_layer_list_view.get() );
		m_splitter->addWidget( m_layer_objects_view.get() );

		setWidget( m_splitter.get() );
	}

	LayersView::~LayersView()
	{
	}

	void LayersView::connect_edition( const core::EditionSession& edition_session )
	{
		// first load the layer list
		bool has_model = m_layer_model_binder.load( edition_session.id() );
		if( !has_model )
		{
			begin_edition_session( edition_session );
			m_layer_model_binder.load( edition_session.id() );
		}

	}

	void LayersView::disconnect_edition( const core::EditionSession& edition_session )
	{
		m_layer_model_binder.unload();
		m_layer_objects_model->clear();
	}

	void LayersView::begin_edition_session( const core::EditionSession& edition_session )
	{
		m_layer_model_binder.add( std::unique_ptr<QAbstractItemModel>( new CanvasLayersModel( edition_session.canvas() ) ), edition_session.id() );
	}

	void LayersView::end_edition_session( const core::EditionSession& edition_session )
	{
		m_layer_model_binder.remove( edition_session.id() );
	}

	void LayersView::react_layer_clicked( const QModelIndex& layer_index )
	{

	}


}

}