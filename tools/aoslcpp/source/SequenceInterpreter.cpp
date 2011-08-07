#include "aoslcpp/SequenceInterpreter.hpp"

#include "aosl/sequence.hpp"

namespace aoslcpp
{
		
	SequenceInterpreter::SequenceInterpreter( const aosl::Sequence& sequence )
		: m_sequence( sequence )
		, m_path( sequence.story().begin() )
		, m_canvas( sequence.canvas() )
	{


	}

}