#include "aoslcpp/SequenceInterpreter.hpp"

#include <algorithm>

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
		
	}

	void SequenceInterpreter::go_back()
	{

	}

	void SequenceInterpreter::go_next()
	{

	}


	bool SequenceInterpreter::can_go_next() const
	{
		return false;
	}

}