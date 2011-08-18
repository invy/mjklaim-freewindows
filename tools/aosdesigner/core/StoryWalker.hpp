#ifndef HGUARD_AOSD_CORE_STORYWALKER_HPP__
#define HGUARD_AOSD_CORE_STORYWALKER_HPP__
#pragma once


#include <QObject>

#include "aoslcpp/SequenceInterpreter.hpp"

namespace aosd
{
namespace core
{

	/** Allow going through a Sequence story and provide informations about the state of this story.
	*/
	class StoryWalker
		: public QObject
	{
		Q_OBJECT
	public:

		explicit StoryWalker( const aoslcpp::SequenceInterpreter& interpreter );
	
		void restart( const aoslcpp::SequenceInterpreter& interpreter );

	public slots:

		//void go_next();

	signals:

		void restarted();

	private slots:


	private:

		aoslcpp::SequenceInterpreter m_interpreter;

	};


}
}


#endif