#ifndef HGUARD_AOSD_CORE__CONTEXT_HPP__
#define HGUARD_AOSD_CORE__CONTEXT_HPP__
#pragma once

#include <memory>
#include <QObject>

#include "core/ProjectInfos.hpp"
#include "core/SequenceId.hpp"
#include "utilcpp/Singleton.hpp"



namespace aosd
{
namespace core
{
	class Project;

	/** Singleton that hold the current context of the application, 
		like the current project to work on and the open sequence.
	*/
	class Context
		: public QObject
		, public util::Singleton< Context >
	{
		Q_OBJECT
	public:

		Context();
		~Context();
		
		/** @return True if there is a project open currently. */
		bool is_project_open() const;

		/** Current project open for edition. */
		const Project& current_project() const;
		

	public slots:

		/** Create a new empty project by asking details to the user and set it as the current project.
			If there was already a project open, it will be closed first.
			@return false if the project creation process failed or have been canceled by the user, true otherwise.
		*/
		bool new_project();

		/** Create a new empty project using the provided informations and set it as the current project.
			If there was already a project open, it will be closed first.
			@return false if the project creation process failed, true otherwise.
		*/
		bool new_project( const ProjectInfos& infos );

		/** Close the currently open project. */
		void close_project();
		
		/** Open a project by asking it's location to the user. 
			@return false if the project loading process failed or have been canceled by the user, true otherwise.
		*/
		bool open_project();

		/** Save the project and everything it contains. */
		bool save_project();

		/** Create a new sequence in the current project. 
			@return false if the sequence creation failed or if there is no project currently open, true otherwise.
		**/
		bool new_sequence();
		
		/** Create a new story-walk for a sequence of the project.
			@param sequence_id Id of the sequence to create a story-walk for.
			@return false if the story-walk creation failed or if there is no project currently open, true otherwise.
		**/
		bool new_storywalk( const SequenceId& sequence_id );
		
	signals:

		/** Signal : a project have been open. */
		void project_open( const core::Project& project );


		/** Signal : the currently open project will be closed. */
		void project_closed( const core::Project& project );
		
	private:

		/// The currently open project or null if none.
		std::unique_ptr< Project > m_project;

		/** Open a project that have been loaded. 
			@return false if the project loading process failed or have been canceled by the user, true otherwise.
		*/
		bool open_project( std::unique_ptr<Project>&& project );

	};



}
}


#endif
