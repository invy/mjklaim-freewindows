#include "ResourceProvider.hpp"

#include "utilcpp/Assert.hpp"

#include "ResourceFactory.hpp"

namespace aosd
{
namespace core
{

	ResourcePtr ResourceProvider::get( const ResourceInfo& resource_infos )
	{
		auto resource = find( resource_infos );

		if( resource )
			return resource;

		resource = create_resource( resource_infos );

		if( resource )
		{
			add_resource( resource_infos, resource );
		}

		return resource;
	}

	ResourcePtr ResourceProvider::find( const ResourceInfo& resource_infos )
	{
		auto resource_it = m_resources_registry.find( resource_infos );
		if( resource_it != end(m_resources_registry) )
		{
			return resource_it->second;
		}
		return ResourcePtr();
	}

	void ResourceProvider::add_resource( const ResourceInfo& resource_infos, ResourcePtr resource )
	{
		m_resources_registry.insert( std::make_pair( resource_infos, resource ) );
	}


}
}