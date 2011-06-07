#include "view/ProjectView.hpp"

#include <iostream>

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
        
        if( ! connect( &context, SIGNAL(project_open(const core::Project&)), this, SLOT(on_project_open(const core::Project&)) ) )
        {
            std::cerr << "First connection failed\n";
        }

        if( ! connect( &context, SIGNAL(a_test(int)), this, SLOT(on_test(int)) ) )
        {
            std::cerr << "Second connection failed\n";
        }

    }

    void ProjectView::on_project_open( const core::Project& project )
    {
        setWindowTitle( tr("Project : ") + QString::fromStdString( project.name() ) );
    }

    void ProjectView::on_test( int k )
    {
        std::cout << "A TEST " << k << " \n";
    }

}
}