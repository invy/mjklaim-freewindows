#ifndef HGUARD_AOSD_CORE_STORYWALKER_HPP__
#define HGUARD_AOSD_CORE_STORYWALKER_HPP__
#pragma once

#include <memory>

#include <QObject>

namespace aoslcpp
{
	class SequenceInterpreter;
}

namespace aosd
{
namespace core
{
	class Sequence;

	/** Allow going through a Sequence story and provide informations about the state of this story.
	*/
	class StoryWalker
		: public QObject
	{
		Q_OBJECT
	public:

		explicit StoryWalker( const Sequence& sequence );
	
		void restart();

	signals:

		void restarted();

	private slots:


	private:

		/// The Sequence we are walking through.
		const Sequence& m_sequence;

		std::unique_ptr< aoslcpp::SequenceInterpreter > m_interpreter;

	};


}
}


#endif