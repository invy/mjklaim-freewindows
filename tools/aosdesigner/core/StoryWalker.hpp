#ifndef HGUARD_AOSD_CORE_STORYWALKER_HPP__
#define HGUARD_AOSD_CORE_STORYWALKER_HPP__
#pragma once


#include <boost/filesystem/path.hpp>
#include <QObject>

#include "core/StoryWalkerId.hpp"
#include "aoslcpp/SequenceInterpreter.hpp"


namespace aosd
{
namespace core
{
	class Project;
	class Sequence;
	

	namespace bfs = boost::filesystem;

	/** Allow going through a Sequence story and provide informations about the state of this story.
	*/
	class StoryWalker
		: public QObject
	{
		Q_OBJECT
	public:

		/** Constructor : create a new story-walker.
			@param project		Project in which this story-walk occurs.
			@param sequence		Sequence that is being walked in.
			@param interpreter	Interpreter containing the walk informations.
		**/
		StoryWalker( const Project& project, const Sequence& sequence );

		/**	Constructor : load a story-walk from a file.
			@param file_path	Path of the file containing the story-walk informations.
		**/
		StoryWalker( const Project& project, const bfs::path& file_path );
	
		const StoryWalkerId& id() const { return m_id; }

		bool is_valid() const { return m_sequence && m_interpreter; }
		
	public slots:

		void save();

	signals:

		
	private slots:


	private:

		std::unique_ptr<aoslcpp::SequenceInterpreter> m_interpreter;


		const Project& m_project;
		const Sequence* m_sequence;

		StoryWalkerId m_id;

	};


}
}


#endif