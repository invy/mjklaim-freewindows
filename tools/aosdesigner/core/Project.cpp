#include "core/Project.hpp"

#include <algorithm>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/info_parser.hpp>

namespace aosd
{
namespace core
{

    const std::string Project::FILENAME = "project.info";

    Project::Project()
    {
        m_sequences.push_back( new Sequence() );
        m_name = "No name yet";
        m_location = "./";

    }

    Project::Project( const bfs::path& from_location )
    {
        // TODO : move that in a separate function!
        // TODO : THIS IS NOT SAFE!!!!!
        using namespace boost::property_tree;

        const auto project_file_path = from_location / FILENAME;

        ptree infos;
        read_info( project_file_path.string(), infos );     

        m_name = infos.get<std::string>( "project.name" );
    }


    void Project::change_location( const bfs::path& new_filepath )
    {
        // TODO : add some checks!
        m_location = new_filepath;
    }

    void Project::change_name( const std::string& new_name )
    {
        // TODO : add some checks!
        m_name = new_name;
    }

    void Project::save( const bfs::path& filepath )
    {
        using namespace boost::property_tree;

        // fill it with properties that needs to be saved
        ptree infos;

        infos.put( "project.name", name() );

        // TODO : add other informations here

        const auto project_file_path = filepath / FILENAME;

        write_info( project_file_path.string(), infos );
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