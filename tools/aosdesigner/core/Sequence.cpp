#include "Sequence.hpp"

#include "util/Assert.hpp"

#include "aoslcpp/aosl/sequence.hpp"

namespace aosd
{
namespace core
{
	
	Sequence::Sequence( Project& project, const SequenceInfos& infos )
		: m_project( project )
		, m_name( infos.name )
	{
		// TODO : create the m_sequence
	}

	Sequence::Sequence( Project& project, const boost::filesystem::path sequence_file_path )
		: m_project( project )
	{
		// TODO : load the m_sequence from the file
	}

	Sequence::~Sequence()
	{

	}

	bool Sequence::save()
	{
		AOSD_NOT_IMPLEMENTED_YET;
		return true;
	}


}
}