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

	void Context::new_project()
	{
		auto project_path = view::request_new_project_path();
		
		if( !project_path.empty() )
		{
			auto project = new Project();
			open_project( *project );
		}
		
	}

	void Context::open_project()
	{
		if( is_project_open() ) 
			close_project(); // TODO : don't continue if the close failed!

		auto project_path = view::request_project_path();

		if( !project_path.empty() )
		{
			
			// TODO : create the project when we got the directory

		}

		// THINK : do something else if it failed?
		
	}

	void Context::open_project( Project& project )
	{
		Q_CHECK_PTR( &project );

		if( m_project )
			close_project();

		m_project.reset( &project );

		emit project_open( current_project() );
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