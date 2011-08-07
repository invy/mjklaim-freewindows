#ifndef HGUARD_AOSD_VIEW_ACTIONSPROVIDER_HPP__
#define HGUARD_AOSD_VIEW_ACTIONSPROVIDER_HPP__
#pragma once

#include <algorithm>

#include <QObject>
#include <QAction>

#include "utilcpp/Assert.hpp"

namespace aosd
{
namespace view
{
	/** Interface for actions providers.
	*/
	class ActionsProvider : public QObject
	{
		Q_OBJECT
	public:

		virtual ~ActionsProvider(){}

		/// A list of actions.
		typedef std::vector<QAction*> ActionList;

		/// All actions registered in this action provider.
		ActionList all_actions() const { return m_actions; }
		
		/** Apply the given functor to all actions registered in this provider. */
		template< class F >
		void for_each_action( F f ) const { std::for_each( m_actions.begin(), m_actions.end(), f ); }
	
	protected:

		/** Register an action in this provider. */
		void add( QAction& action )
		{
			UTILCPP_ASSERT( std::find(m_actions.begin(), m_actions.end(), &action) == m_actions.end(), "Tried to add an action twice in this action provider!" );
			m_actions.push_back( &action );
		}
	
	private:

		ActionList m_actions;
		
	};

}
}


#endif