#ifndef HGUARD_AOSD_CORE_SEQUENCE_HPP__
#define HGUARD_AOSD_CORE_SEQUENCE_HPP__
#pragma once

#include <string>
#include <memory>

namespace aosl
{
	class Sequence;
}


namespace aosd
{
namespace core
{

	/** A full Sequence as defined in AOSL.
	*/
	class Sequence
	{
	public:

		Sequence();
		~Sequence();
		
		/// Name of the Sequence.
		const std::string& name() const { return m_name; }
		


	private:

		/// Name of this Sequence
		std::string m_name;

		/// Raw Sequence data.
		std::unique_ptr< aosl::Sequence > m_sequence;

	};



}
}


#endif
