#ifndef HGUARD_AOSLCPP_SEQUENCEINTERPRETER_HPP__
#define HGUARD_AOSLCPP_SEQUENCEINTERPRETER_HPP__
#pragma once

#include "aosl/stage_ref.hpp"

#include "aoslcpp/StoryPath.hpp"
#include "aoslcpp/CanvasState.hpp"
#include "aoslcpp/NavigationState.hpp"

namespace aosl
{
	class Sequence;
}

namespace aoslcpp
{
	/** Walks through a sequence's to interpret it's story.
	**/
	class SequenceInterpreter
	{
	public:
		
		explicit SequenceInterpreter( const aosl::Sequence& sequence );

		/** Navigate through the sequence's story by triggering an event from navigation choices.
		*/
		void go( const aosl::Event& event );

		/** Apply the given move.
		*/
		void go( const aosl::Move_ref& move );

		/** Go back in the path followed. */
		void go_back( std::size_t step_count = 1 );

		/** Go to the next automatically guessed move. */
		void go_next();

		/// The path followed by this interpreter.
		const StoryPath& path() const { return m_path; }

		/// The current state of the canvas objects.
		const CanvasState& canvas() const { return m_canvas; }

		/// The current navigation actions available at this stage.
		const NavigationState& navigation() const { return m_navigation; }

		/** @return true if there is a unique next move from the current stage, false otherwise. */
		bool can_go_next() const;

		/** @return true if there is a previous stage, false if we're at the first stage. */
		bool can_go_back() const { return m_path.can_step_back(); }

	private:

		const aosl::Sequence& m_sequence;

		
		/// The path followed by this interpreter.
		StoryPath m_path;

		/// The current state of the canvas objects.
		CanvasState m_canvas;

		/// The current navigation actions available at this stage.
		NavigationState m_navigation;

		aosl::Stage_ref execute_move( const aosl::Move_ref& move, bool reverse );
	};


}


#endif
