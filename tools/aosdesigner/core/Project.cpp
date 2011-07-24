#include "core/Project.hpp"

#include <algorithm>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/info_parser.hpp>

#include "core/ProjectInfos.hpp"
#include "Paths.hpp"

namespace aosd
{
namespace core
{

	Project::Project( const ProjectInfos& infos )
		: m_location( infos.location )
		, m_name( infos.name )
	{
		assert( is_valid(infos) );
		
		// THINK : create a default Sequence?


	}

	Project::Project( const bfs::path& from_location )
	{
		// TODO : move that in a separate function!
		// TODO : THIS IS NOT SAFE!!!!!
		using namespace boost::property_tree;
		
		ptree infos;
		read_info( from_location.string(), infos );     

		m_name = infos.get<std::string>( "project.name" );
		m_location = from_location;

	}


	void Project::relocate( const bfs::path& new_filepath )
	{
		// TODO : add some checks!
		m_location = new_filepath;
	}

	void Project::rename( const std::string& new_name )
	{
		// TODO : add some checks!
		m_name = new_name;
	}

	bool Project::save()
	{
		using namespace boost::property_tree;

		// fill it with properties that needs to be saved
		ptree infos;

		infos.put( "project.name", name() );

		// TODO : add other informations here

		try
		{
			write_info( m_location.string(), infos );
		}
		catch( const boost::exception& e )
		{
			// TODO : add logging here
			__asm int 3;
			return false;
		}

		return true;
	}

	void Project::foreach_sequence( const SequenceModifierFunc& func )
	{
		std::for_each( m_sequences.begin(), m_sequences.end(), func );
	}

	void Project::foreach_sequence( const SequenceReaderFunc& func ) const
	{
		std::for_each( m_sequences.begin(), m_sequences.end(), func );
	}


}
}