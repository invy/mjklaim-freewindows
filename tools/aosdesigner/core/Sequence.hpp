#ifndef __AOSD_CORE_SEQUENCE_HPP__
#define __AOSD_CORE_SEQUENCE_HPP__
#pragma once

#include <string>
#include <memory>

#include "aoslcpp/aosl/sequence_forward.hpp"

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
		
		const std::string& name() const { return m_name; }
		


	private:

		std::string m_name;

		std::unique_ptr< aosl::Sequence > m_sequence;

	};



}
}


#endif
