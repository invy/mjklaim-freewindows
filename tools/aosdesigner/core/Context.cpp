#include "Context.hpp"

#include <boost/exception/diagnostic_information.hpp>

#include "core/Project.hpp"
#include "view/Dialogs.hpp"
#include "Paths.hpp"


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
		
		std::unique_ptr<Project> project( new Project( infos ) );
		project->save(); // generate the file

		return open_project( std::move(project) );
	}

	bool Context::open_project()
	{
		auto project_file_path = view::request_project_path();

		if( project_file_path.empty() 
		||  !( project_file_path.extension() == path::PROJECT_FILE_EXTENSION )
		)
		{
			return false; // THINK : do something else if it failed?
		}

		if( is_project_open() ) 
			close_project(); // TODO : don't continue if the close failed!
		
		try
		{
			open_project( std::unique_ptr<Project>( new Project( project_file_path ) ) );
		}
		catch( const boost::exception& e )
		{
			// TODO : ADD LOGGING HERE!!!
			std::cout<< "Error on opening a project : " << boost::diagnostic_information( e ) << std::endl;

			__asm int 3;
			return false;
		}
			
		return true;
	}

	bool Context::open_project( std::unique_ptr<Project>&& project )
	{
		Q_CHECK_PTR( &project );

		if( m_project )
			close_project();

		m_project.swap( project );

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