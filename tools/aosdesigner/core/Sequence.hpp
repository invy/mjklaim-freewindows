#ifndef HGUARD_AOSD_CORE_SEQUENCE_HPP__
#define HGUARD_AOSD_CORE_SEQUENCE_HPP__
#pragma once

#include <string>
#include <memory>

#include "core/SequenceInfos.hpp"

namespace aosl
{
	class Sequence;
}
namespace aoslcpp
{
	class SequenceInterpreter;
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

		typedef std::string UniqueId;

		/** Create a new sequence using the provided informations.
			@param project		Project in which this sequence exists.
			@param infos		Informations required to build the sequence.
		*/
		Sequence( Project& project, const SequenceInfos& infos );

		/** Create the sequence by loading informations from the AOSL file at the the provided path.
			The path have to be 
		*/
		Sequence( Project& project, const boost::filesystem::path sequence_file_path );

		~Sequence();


		bool save();
		
		/// Name of the Sequence.
		const std::string& name() const { return m_name; }

		/// Unique identifier of this Sequence.
		const UniqueId& id() const { return m_id; }

		const boost::filesystem::path& location() const { return m_location; }
		boost::filesystem::path full_location() const;
		
		/// Project in which this sequence is loaded.
		const Project& project() const { return m_project; }
		Project& project() { return m_project; }

		/** Create an interpreter for this Sequence.
		*/
		std::unique_ptr< aoslcpp::SequenceInterpreter > new_interpreter();

	private:

		/// Name of this Sequence
		std::string m_name;

		/// Unique identifier of this Sequence
		UniqueId m_id;

		/// Path relative to the project's folder of the file containing this sequence.
		boost::filesystem::path m_location;

		/// Raw Sequence data.
		std::unique_ptr< aosl::Sequence > m_sequence;

		/// Project in which this sequence is loaded.
		Project& m_project;

		
	};



}
}


#endif
