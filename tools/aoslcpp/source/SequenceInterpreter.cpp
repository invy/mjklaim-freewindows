#include "aoslcpp/SequenceInterpreter.hpp"

#include <algorithm>

#include "utilcpp/Assert.hpp"

#include "aosl/sequence.hpp"
#include "aosl/event.hpp"

namespace aoslcpp
{
		
	SequenceInterpreter::SequenceInterpreter( const aosl::Sequence& sequence )
		: m_sequence( sequence )
		, m_path( sequence.story().begin() )
		, m_canvas( sequence.canvas() )
		, m_navigation( sequence.story().navigation() ? *sequence.story().navigation() : aosl::Navigation() ) // empty navigation if not provided by the sequence
	{
		
	}

	void SequenceInterpreter::go( const aosl::Event& event )
	{
		go( event.move() );
	}

	void SequenceInterpreter::go( const aosl::Move_ref& move, bool reversed /*= false */ )
	{
		// get the move informations

		// get the next stage informations

		// apply the changes

		// update the navigation options

		// record change of stage

	}

	void SequenceInterpreter::go_back( std::size_t step_count )
	{
		UTILCPP_ASSERT( step_count > 0, "Invalid step count : " << step_count );

		if( can_go_back() )
		{
			// find the move to reverse

			// go back
		}
	}

	void SequenceInterpreter::go_next()
	{
		// find
	}


	bool SequenceInterpreter::can_go_next() const
	{
		return false;
	}

}