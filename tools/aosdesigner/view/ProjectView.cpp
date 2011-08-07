#include "view/ProjectView.hpp"

#include <QTabWidget>

#include "view/SequenceListView.hpp"

namespace aosd
{
namespace view
{

	ProjectView::ProjectView()
		: QDockWidget( tr("Project") )
		, m_tabs( new QTabWidget() )
	{
		setWidget( m_tabs.get() );

		m_tabs->addTab( new SequenceListView(), tr("Sequences") );

	}

	ProjectView::~ProjectView()
	{

	}

}
}