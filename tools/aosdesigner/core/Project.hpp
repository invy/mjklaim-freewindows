#ifndef HGUARD_AOSD_CORE_PROJECT_HPP__
#define HGUARD_AOSD_CORE_PROJECT_HPP__
#pragma once

#include <string>
#include <boost/filesystem/path.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <QObject>
#include "core/SequenceId.hpp"
#include "core/EditionSessionId.hpp"

namespace aosd 
{ 
namespace core 
{
	class Sequence;
	class EditionSession;
	struct ProjectInfos;
	struct SequenceInfos;
	struct EditionSessionInfos;

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

		/** Call the provided function for each Sequence in this project but don't allow to modify them. */
		void foreach_sequence( std::function< void ( const Sequence& sequence )> func ) const;

		/** Call the provided function for each edition session in this project but don't allow to modify them. */
		void foreach_edition( std::function< void ( const EditionSession& edition )> func ) const;

		const Sequence* find_sequence( const SequenceId& sequence_id ) const {  return const_cast<Project*>(this)->find_sequence(sequence_id); }

		/** Current selected edition session or null if none or if there is no project open. */
		const EditionSession* selected_edition_session() const { return m_selected_session; }

		
	public slots:

		/** Change the project's file location to the provided one. */
		void relocate( const bfs::path& new_filepath );

		/** Change the name of the project. */
		void rename( const std::string& new_name );

		/** Create a new "empty" sequence with provided informations. */
		bool new_sequence( const SequenceInfos& infos );
		
		/** Request informations to the user and use them to create a new sequence. */
		bool new_sequence();

		/** Create an edition session for the referenced sequence. **/
		bool new_edition( const EditionSessionInfos& session_infos );

		/** Request informations to the user and use them to create a new edition session. */
		bool new_edition();

		/** Select the referred edition session. */
		void select_edition_session( const EditionSessionId& session_id );

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

		/** Signal : an edition session have began. **/
		void edition_begin( const core::EditionSession& walker );

		/** Signal : an edition session will be ended. **/
		void edition_end( const core::EditionSession& walker );

		/** Signal : an edition session have been selected. **/
		void edition_selected( const core::EditionSession& edition_session );
		
		/** Signal : an edition session have been deselected. **/
		void edition_deselected( const core::EditionSession& edition_session );

		
	private:

		/// Sequences for this project.
		boost::ptr_vector< Sequence > m_sequences;

		/// Sequence edition sessions.
		boost::ptr_vector< EditionSession > m_edit_sessions;

		/// Name of the project.
		std::string m_name;
				
		/// Path of the file that contain all the project's informations about this project.
		bfs::path m_location;

		/// Path of the project's directory.
		bfs::path m_directory_path;

		/// Currently selected edition session.
		EditionSession* m_selected_session;


		/// Add a Sequence to this project.
		void add_sequence( std::unique_ptr<Sequence>&& sequence );

		/// Add an edition session to this project.
		void add_edition( std::unique_ptr<EditionSession>&& sequence );

		/** Search for a Sequence having the provided id.
			@return The Sequence we looked after or null if not found. 
		**/
		Sequence* find_sequence( const SequenceId& sequence_id );

		/** Search for an edition session having the provided id.
		**/
		EditionSession* find_edition( const EditionSessionId& session_id );

	};

	

}
}


#endif

