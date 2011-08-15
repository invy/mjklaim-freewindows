#include "aoslcpp/SequenceInterpreter.hpp"

#include <algorithm>

#include "utilcpp/Assert.hpp"

#include "aoslcpp/algorithm/find.hpp"
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

	void SequenceInterpreter::go( const aosl::Move_ref& move_ref, bool reversed /*= false */ )
	{
		// get the move informations
		const auto move = find_move( m_sequence.story(), move_ref );
		UTILCPP_ASSERT_NOT_NULL( move );

		// get the next stage informations
		const auto stage = find_stage( m_sequence.story(), move->to() );
		UTILCPP_ASSERT_NOT_NULL( stage );

		// apply the changes

		// update the navigation options
		if( stage->navigation() )
			m_navigation.update( *stage->navigation() );
		else
			m_navigation.reset();

		// record change of stage
		m_path.add_step( aosl::Stage_ref( stage->id() ) );
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
		if( can_go_next() )
		{
			// find the unique move to go next
		}
		
	}


	bool SequenceInterpreter::can_go_next() const
	{
		return false;
	}

}