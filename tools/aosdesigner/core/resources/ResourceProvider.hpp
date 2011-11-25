#ifndef HGUARD_AOSD_CORE_RESOURCEPROVIDER_H__
#define HGUARD_AOSD_CORE_RESOURCEPROVIDER_H__
#pragma once

#include <map>
#include "ResourcePtr.hpp"
#include "ResourceInfo.hpp"
#include "aosl/resource.hpp"

namespace aosd
{
namespace core
{
	
	class ResourceProvider
	{
	public:
		
		ResourcePtr get( const aosl::Resource& resource_infos ) { get( resource_infos. ) }
		ResourcePtr get( const ResourceInfo& resource_infos ) { return get( resource_infos.uri(), resource_infos.type() ); }
		ResourcePtr get( const URI& uri, const aosl::Resource_type& resource_type = "auto" );
		
	private:

		std::map< ResourceInfo, ResourcePtr > m_resources_registry;

	};



}
}


#endif
