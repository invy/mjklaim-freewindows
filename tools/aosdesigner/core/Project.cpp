#include "core/Project.hpp"

#include <algorithm>

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/algorithm/string.hpp>

#include "core/ProjectInfos.hpp"
#include "Paths.hpp"

namespace aosd
{
namespace core
{

	Project::Project( const ProjectInfos& infos )
		: m_location( infos.location )
		, m_name( infos.name )
		, m_codename( infos.codename )
	{
		assert( is_valid(infos) );
		
		// THINK : create a default Sequence?


	}

	Project::Project( const bfs::path& project_file_path )
		: m_location( project_file_path.parent_path() )
		, m_codename( boost::replace_all_copy( project_file_path.filename().string(), path::PROJECT_FILE_EXTENSION, "" ) )
	{
		// TODO : move that in a separate function!
		// TODO : THIS IS NOT SAFE!!!!!
		using namespace boost::property_tree;
		
		bfs::ifstream filestream( project_file_path );

		ptree infos;
		read_xml( filestream, infos );

		m_name = infos.get<std::string>( "project.name" );

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
			namespace bfs = boost::filesystem;
			if( !bfs::is_directory( m_location ) )
			{
				bfs::create_directories( m_location );
			}

			const auto project_infos_path = m_location / path::PROJECT_FILE( codename() );

			bfs::ofstream filestream( project_infos_path );

			write_xml( filestream, infos );
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