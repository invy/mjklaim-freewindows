#ifndef HGUARD_AOSD_CORE_SEQUENCE_HPP__
#define HGUARD_AOSD_CORE_SEQUENCE_HPP__
#pragma once

#include <string>
#include <memory>
#include <boost/optional.hpp>

#include "core/SequenceId.hpp"
#include "core/SequenceInfos.hpp"

#include "aoslcpp/SequenceInterpreter.hpp"

namespace aosl
{
	class Sequence;
}

namespace aosd
{
namespace core
{
	class Project;


	/** A full Sequence as defined in AOSL.
	*/
	class Sequence
	{
	public:

		/** Create a new sequence using the provided informations.
			@param project		Project in which this sequence exists.
			@param infos		Informations required to build the sequence.
		*/
		Sequence( const Project& project, const SequenceInfos& infos );

		/** Create the sequence by loading informations from the AOSL file at the the provided path.
			The path have to be 
		*/
		Sequence( const Project& project, const boost::filesystem::path sequence_file_path );

		~Sequence();
		
		bool save();
		
		/// Name of the Sequence.
		const std::string& name() const { return m_name; }

		/// Unique identifier of this Sequence.
		SequenceId id() const { return m_id; }

		boost::filesystem::path location() const { return m_location; }
		boost::filesystem::path full_location() const;
		
		/// Project in which this sequence is loaded.
		const Project& project() const { return m_project; }
		
		/** Create an interpreter for this Sequence. */
		std::unique_ptr<aoslcpp::SequenceInterpreter> make_interpreter() const;

	private:

		/// Name of this Sequence
		std::string m_name;

		/// Unique identifier of this Sequence
		SequenceId m_id;

		/// Path relative to the project's folder of the file containing this sequence.
		boost::filesystem::path m_location;

		/// Raw Sequence data.
		std::unique_ptr< aosl::Sequence > m_sequence;

		/// Project in which this sequence is loaded.
		const Project& m_project;

		
	};



}
}


#endif
