#include "Context.hpp"


#include "Project.hpp"
#include "view/Dialogs.hpp"

namespace aosd
{
namespace core
{


	Context::Context()
		: m_project( nullptr )
	{

	}


	Context::~Context()
	{

	}

	bool Context::new_project()
	{
		ProjectInfos infos = view::request_new_project_infos();
		
		if( is_valid( infos ) )
		{
			return new_project( infos );
		}

		return false;
	}

	bool Context::new_project( const ProjectInfos& infos )
	{
		Q_ASSERT( is_valid(infos) );
		
		auto project = new Project( infos );
		project->save(); // generate the file

		return open_project( *project );
	}

	bool Context::open_project()
	{
		if( is_project_open() ) 
			close_project(); // TODO : don't continue if the close failed!

		auto project_path = view::request_project_path();

		if( project_path.empty() )
			return false;// THINK : do something else if it failed?
		try
		{
			auto project = new Project( project_path );
			open_project( *project );
		}
		catch(...) // NOT A GOOD IDEA...BUT OH WELL...
		{
			// TODO : ADD LOGGING HERE!!!
			return false;
		}
			
		return true;
	}

	bool Context::open_project( Project& project )
	{
		Q_CHECK_PTR( &project );

		if( m_project )
			close_project();

		m_project.reset( &project );

		emit project_open( current_project() );
		return true;
	}

	void Context::close_project()
	{
		if( is_project_open() )
		{
			// TODO : add here closing code

			emit project_closed( current_project() );
			m_project.reset();
		}
		
	}

	bool Context::is_project_open() const
	{
		return m_project;
	}

	const Project& Context::current_project() const
	{
		return *m_project;
	}


}
}