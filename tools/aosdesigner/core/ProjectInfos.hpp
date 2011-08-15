#ifndef HGUARD_AOSD_CORE_PROJECTINFOS_HPP__
#define HGUARD_AOSD_CORE_PROJECTINFOS_HPP__
#pragma once

#include <string>
#include <boost/filesystem/path.hpp>


namespace aosd
{
namespace core
{
	/** Basic informations about a project.
	*/
	struct ProjectInfos
	{
		boost::filesystem::path location;
		std::string name;
		
	};

	inline bool is_valid( const ProjectInfos& infos )
	{
		return !( infos.location.empty() || infos.name.empty() );
	}

}
}


#endif
