#ifndef HGUARD_AOSD_CORE_PROJECT_HPP__
#define HGUARD_AOSD_CORE_PROJECT_HPP__
#pragma once

#include <string>
#include <boost/filesystem/path.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include "core/Sequence.hpp"


namespace aosd 
{ 
namespace core 
{
	struct ProjectInfos;

	namespace bfs = boost::filesystem;

	/** Contains a set of Sequences and common informations applied to all those Sequences.

	*/
	class Project
	{
	public:

		static const std::string FILENAME;
		
		/** Create a project from basic informations. */
		Project( const ProjectInfos& infos );

		/** Load a project from a provided project file location. */
		Project( const bfs::path& project_file_path );
		
		/** Save the project informations and content in the provided location. */
		bool save( const bfs::path& filepath )
		{
			relocate(filepath);
			return save();
		}

		/** Save the project informations and content in the default location. */
		bool save();

		/// Path of the file that contain all the project's informations.
		const bfs::path& location() const { return m_location; }

		/** Change the project's file location to the provided one. */
		void relocate( const bfs::path& new_filepath );

		/** Name of the project. */
		const std::string& name() const { return m_name; }

		/** Change the name of the project. */
		void rename( const std::string& new_name );

		/** Codename of the project. This information will never change. */
		const std::string& codename() const { return m_codename; }

		/// Signature for functions allowed to modify a Sequences.
		typedef std::function< void ( Sequence& sequence )> SequenceModifierFunc;
		/// Signature for functions only allowed to read Sequences.
		typedef std::function< void ( const Sequence& sequence )> SequenceReaderFunc;

		/** Call the provided function for each Sequence in this project, allowing it to modify the Sequences. */
		void foreach_sequence( const SequenceModifierFunc& func );

		/** Call the provided function for each Sequence in this project but don't allow to modify them. */
		void foreach_sequence( const SequenceReaderFunc& func ) const;
		
	private:

		/// Sequences for this project.
		boost::ptr_vector< Sequence > m_sequences;

		/// Name of the project.
		std::string m_name;

		/// Codename of the project. That's the only project's information that will never change.
		std::string m_codename;
		
		/// Path of the file that contain all the project's informations
		bfs::path m_location;

	};

	

}
}


#endif

