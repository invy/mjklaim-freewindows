#include "view/ProjectView.hpp"


#include "core/Context.hpp"
#include "core/Project.hpp"

namespace aosd
{
namespace view
{

    ProjectView::ProjectView()
        : QDockWidget( tr("Project") )
    {
        auto& context = core::Context::instance();
        connect( &context, SIGNAL(project_open(const core::Project&)), this, SLOT(on_project_open(const core::Project&)) );
        
    }

    void ProjectView::on_project_open( const core::Project& project )
    {
    }

}
}