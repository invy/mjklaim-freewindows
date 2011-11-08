#ifndef HGUARD_AOSD_VIEW_MODELREGISTRY_HPP__
#define HGUARD_AOSD_VIEW_MODELREGISTRY_HPP__
#pragma once

#include <map>
#include "core/EditionSessionId.hpp"

class QAbstractItemModel;
class QAbstractItemView;

namespace aosd
{
namespace view
{

	/** Keep a set of view models associated to a session id and allow association with a view.
		Allow views to keep a set of models for all open edition sessions and switch between models 
		when the user switch between edition sessions.
	*/
	class ModelViewBinder
	{
	public:

		explicit ModelViewBinder( QAbstractItemView& viewer );
		~ModelViewBinder();

		void add( std::unique_ptr< QAbstractItemModel > model, const core::EditionSessionId& session_id );
		void remove( const core::EditionSessionId& session_id );
		void clear();

		/**	Will load the model associated with the provided session id.
			@return True if the model is found and associated, false otherwise.
		**/
		bool load( const core::EditionSessionId& session_id );

		/** Remove the current model from the view.
		**/
		void unload();

		QAbstractItemModel* current_model() const { return m_model; }

	private:

		std::map< core::EditionSessionId, std::unique_ptr< QAbstractItemModel > > m_registry;
		QAbstractItemView& m_view;
		QAbstractItemModel* m_model;

		QAbstractItemModel* find( const core::EditionSessionId& session_id );
		void bind_to_view( QAbstractItemModel* model );
		
	};


}
}


#endif
