#include "view/ProjectView.hpp"

#include "view/SequenceListView.hpp"

namespace aosd
{
namespace view
{

    ProjectView::ProjectView()
        : QDockWidget( tr("Project") )
        , m_sequence_list( new SequenceListView() )
    {
        setWidget( m_sequence_list.get() );

    }

}
}