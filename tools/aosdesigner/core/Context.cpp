#include "Context.hpp"

#include "Project.hpp"

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
		auto project = new Project();
		open_project( *project );
	}

	void Context::open_project()
	{
		Q_ASSERT( false ); // not implemented yet
		// TODO : ask the directory where the project should be
		// TODO : create the project when we got the directory

		open_project( *m_project );
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