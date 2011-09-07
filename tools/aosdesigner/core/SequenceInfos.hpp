#ifndef HGUARD_AOSD_CORE_SEQUENCEINFOS_HPP__
#define HGUARD_AOSD_CORE_SEQUENCEINFOS_HPP__
#pragma once

#include <string>
#include <boost/filesystem/path.hpp>

namespace aosd
{
namespace core
{
	
	struct SequenceInfos
	{
		SequenceInfos() : canvas_width( 0.0 ), canvas_height( 0.0 ), is_storywalker_requested(false) {}

		boost::filesystem::path location;
		std::string name;
		double canvas_width;
		double canvas_height;
		bool is_storywalker_requested;

	};

	inline bool is_valid( const SequenceInfos& infos )
	{
		return !(	infos.location.empty()
				||	infos.name.empty()
				||	infos.canvas_height <= 0.0
				||  infos.canvas_width <= 0.0
			);
	}

}
}


#endif
