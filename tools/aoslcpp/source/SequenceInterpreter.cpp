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
		, m_path()
		, m_canvas( sequence.canvas() ) // copy the initial canvas
		, m_navigation( sequence.story().navigation() ? *sequence.story().navigation() : aosl::Navigation() ) // empty navigation if not provided by the sequence
	{
		
	}

	void SequenceInterpreter::go( const aosl::Event& event )
	{
		go( event.move() );
	}

	void SequenceInterpreter::go( const aosl::Move_ref& move_ref )
	{
		// get the move informations
		const auto move = find_move( m_sequence.story(), move_ref );
		UTILCPP_ASSERT_NOT_NULL( move );

		const auto stage_ref = move->to();

		// get the next stage informations
		const auto stage = find_stage( m_sequence.story(), stage_ref );
		UTILCPP_ASSERT_NOT_NULL( stage );

		// apply the changes
		std::for_each( move->change().begin(), move->change().end() , [&]( const aosl::Change& change ) { m_canvas.execute( change ); } );

		// update the navigation options
		if( stage->navigation() )
			m_navigation.update( *stage->navigation() );
		else
			m_navigation.reset();

		// record the step
		m_path.add_step( move_ref, stage_ref );
	}

	void SequenceInterpreter::go_back( std::size_t step_count )
	{
		UTILCPP_ASSERT( step_count > 0, "Invalid step count for going back : " << step_count );

		if( can_go_back() && step_count > 0 )
		{
			// find the move to reverse
			m_path.step_back();
			const auto move = find_move( m_sequence.story(), m_path.last_move() );

			UTILCPP_NOT_IMPLEMENTED_YET;

			// go back

			--step_count;
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