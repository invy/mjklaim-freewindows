#include "Context.hpp"

#include "Project.hpp"

namespace aosd
{
namespace core
{



    void Context::new_project()
    {
        auto project = new Project();
        open_project( *project );

    }

    void Context::open_project( const boost::filesystem::path& project_path )
    {
        Q_ASSERT( false ); // not implemented yet

        emit on_project_open( project_open() );
    }

    void Context::open_project( Project& project )
    {
        Q_CHECK_PTR( &project );

        if( m_project )
            close_project();

        m_project.reset( &project );

        emit on_project_open( project_open() );
    }

    void Context::close_project()
    {
        Q_ASSERT( false ); // not implemented yet

        emit on_project_close( project_open() );

        m_project.reset();
    }


}
}