#ifndef HGUARD_AOSD_CORE_PROJECT_HPP__
#define HGUARD_AOSD_CORE_PROJECT_HPP__
#pragma once

#include <string>
#include <boost/filesystem/path.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <QObject>
#include "core/SequenceId.hpp"

namespace aosd 
{ 
namespace core 
{
	class Sequence;
	class StoryWalker;
	struct ProjectInfos;
	struct SequenceInfos;

	namespace bfs = boost::filesystem;

	/** Contains a set of Sequences and common informations applied to all those Sequences.

	*/
	class Project
		: public QObject
	{
		Q_OBJECT
	public:

		static const std::string FILENAME;
		
		/** Create a project from basic informations. */
		Project( const ProjectInfos& infos );

		/** Load a project from a provided project file location. */
		Project( const bfs::path& project_file_path );

		~Project();

		/// Path of the file that contain all the project's informations.
		const bfs::path& location() const { return m_location; }
		
		/// Path of the directory where this project's file is located.
		const bfs::path& directory_path() const { return m_directory_path; }


		/** Name of the project. */
		const std::string& name() const { return m_name; }

		
		/// Signature for functions allowed to modify a Sequences.
		typedef std::function< void ( Sequence& sequence )> SequenceModifierFunc;
		/// Signature for functions only allowed to read Sequences.
		typedef std::function< void ( const Sequence& sequence )> SequenceReaderFunc;

		/** Call the provided function for each Sequence in this project, allowing it to modify the Sequences. */
		void foreach_sequence( SequenceModifierFunc func );

		/** Call the provided function for each Sequence in this project but don't allow to modify them. */
		void foreach_sequence( SequenceReaderFunc func ) const;

	public slots:

		/** Change the project's file location to the provided one. */
		void relocate( const bfs::path& new_filepath );

		/** Change the name of the project. */
		void rename( const std::string& new_name );

		/** Create a new "empty" sequence with provided informations. */
		bool new_sequence( const SequenceInfos& infos );
		
		/** Request informations to the user and use them to create a new sequence. */
		bool new_sequence();

		/** Create a story walk for the referenced sequence. **/
		bool new_storywalker( const SequenceId& sequence_id );

		/** Save the project informations and content in the provided location. */
		bool save( const bfs::path& filepath )
		{
			relocate(filepath);
			return save();
		}

		/** Save the project informations and content in the default location. */
		bool save();

	signals:

		/** Signal : a new sequence have been created. **/
		void sequence_created( const core::Sequence& sequence );

		/** Signal : a sequence have been requested to be destroyed. **/
		void sequence_deleted( const core::Sequence& sequence );

		/** Signal : a story walk have began. **/
		void storywalk_begin( const core::StoryWalker& walker );

		/** Signal : a story walk will be ended. **/
		void storywalk_end( const core::StoryWalker& walker );
		
	private:

		/// Sequences for this project.
		boost::ptr_vector< Sequence > m_sequences;

		/// Sequence paths taken for edition.
		boost::ptr_vector< StoryWalker > m_walks;

		/// Name of the project.
		std::string m_name;
				
		/// Path of the file that contain all the project's informations about this project.
		bfs::path m_location;

		/// Path of the project's directory.
		bfs::path m_directory_path;


		/// Add a Sequence to this project.
		void add_sequence( std::unique_ptr<Sequence>&& sequence );

		/// Add a StoryWalk to this project.
		void add_storywalker( std::unique_ptr<StoryWalker>&& sequence );

		/** Search for a Sequence having the provided id.
			@return The Sequence we looked after or null if not found. 
		**/
		Sequence* find_sequence( const SequenceId& sequence_id );

	};

	

}
}


#endif

