#include "Context.hpp"

#include <boost/exception/diagnostic_information.hpp>

#include "utilcpp/Assert.hpp"

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
			return new_project( infos );
		else 
			return false;
	}

	bool Context::new_project( const ProjectInfos& infos )
	{
		UTILCPP_ASSERT( is_valid(infos), "Tried to create a new project with invalid informations!" );
		
		std::unique_ptr<Project> project( new Project( infos ) );
		project->new_sequence();	// create a first sequence
		project->save();			// generate the file

		const bool project_open = open_project( std::move(project) );
		if( !project_open )
			return false;

		UTILCPP_ASSERT_NOT_NULL( m_project );

		
		return true;
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
		
		return open_project( std::unique_ptr<Project>( new Project( project_file_path ) ) );
	}

	bool Context::open_project( std::unique_ptr<Project>&& project )
	{
		UTILCPP_ASSERT_NOT_NULL( project );

		if( is_project_open() )
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

	bool Context::new_sequence()
	{
		if( is_project_open() )
		{
			return m_project->new_sequence();
		}

		// THINK : replace that with an exception?
		UTILCPP_LOG_ERROR << "Cannot create a new sequence while no project is open!";

		return false;
	}


	bool Context::new_storywalk( const SequenceId& sequence_id )
	{
		if( is_project_open() )
		{
			return m_project->new_storywalker( sequence_id );
		}

		// THINK : replace that with an exception?
		UTILCPP_LOG_ERROR << "Cannot create a story-walk while no project is open!";

		return false;
	}

	bool Context::save_project()
	{
		if( is_project_open() )
		{
			return m_project->save();
		}

		// THINK : replace that with an exception?
		UTILCPP_LOG_ERROR << "Cannot save the project: no project is open!";

		return false;
	}

	bool Context::restore_project()
	{
		if( is_project_open() )
		{
			auto project_location = m_project->location();
			close_project();
			return open_project( std::unique_ptr<Project>( new Project( project_location ) ) );
		}

		// THINK : replace that with an exception?
		UTILCPP_LOG_ERROR << "Cannot restore the project: no project is open!";

		return false;
	}


}
}