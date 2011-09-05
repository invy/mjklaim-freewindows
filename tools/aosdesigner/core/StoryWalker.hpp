#ifndef HGUARD_AOSD_CORE_STORYWALKER_HPP__
#define HGUARD_AOSD_CORE_STORYWALKER_HPP__
#pragma once

#include <QObject>

#include "aoslcpp/SequenceInterpreter.hpp"

namespace aosd
{
namespace core
{
	class Project;
	class Sequence;

	/** Allow going through a Sequence story and provide informations about the state of this story.
	*/
	class StoryWalker
		: public QObject
	{
		Q_OBJECT
	public:

		StoryWalker( const Project& project, const Sequence& sequence, const aoslcpp::SequenceInterpreter& interpreter );
	
		void restart( const aoslcpp::SequenceInterpreter& interpreter );
		
	public slots:

		void save();

		//void go_next();

	signals:

		void restarted();

	private slots:


	private:

		aoslcpp::SequenceInterpreter m_interpreter;


		const Project& m_project;
		const Sequence& m_sequence;

	};


}
}


#endif