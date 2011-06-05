#ifndef __AOSD_CORE_PROJECT_HPP__
#define __AOSD_CORE_PROJECT_HPP__
#pragma once

#include <string>
#include <boost/filesystem/path.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include "core/Sequence.hpp"


namespace aosd 
{ 
namespace core 
{

    namespace bfs = boost::filesystem;

    /** Contains a set of Sequences and common informations applied to all those Sequences.

    */
    class Project
    {
    public:

        static const std::string FILENAME;

        /** Create an almost empty project, with only an empty sequence. */
        Project();

        /** Create a project from a provided project file location. */
        Project( const bfs::path& from_location );
        
        /** Save the project informations and content in the provided location. */
        void save( const bfs::path& filepath );

        /** Save the project informations and content in the default location. */
        void save() { save( m_location ); }

        /// Path of the file that contain all the project's informations.
        const bfs::path& location() const { return m_location; }

        /** Change the project's file location to the provided one. */
        void change_location( const bfs::path& new_filepath );

        const std::string& name() const { return m_name; }
        void change_name( const std::string& new_name );
        
    private:

        /// Sequences for this project.
        boost::ptr_vector< Sequence > m_sequences;

        /// Name of the project.
        std::string m_name;
        
        /// Path of the file that contain all the project's informations
        bfs::path m_location;

    };

    

}
}


#endif

