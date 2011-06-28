#include "Sequence.hpp"

#include "aoslcpp/aosl/sequence.hpp"

namespace aosd
{
namespace core
{
	Sequence::Sequence()
		: m_name( "Test Sequence" )
		, m_sequence( new aosl::Sequence )
	{
		
	}

	Sequence::~Sequence()
	{

	}


}
}