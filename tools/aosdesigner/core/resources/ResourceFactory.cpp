#include "ResourceFactory.hpp"

#include <functional>
#include <map>
#include "aosl/resource_type.hpp"

namespace aosd
{
namespace core
{
	

	namespace 
	{
		typedef std::function< ResourcePtr ( const URI& resource_uri ) > ResourceFactory;
		typedef std::map< aosl::Resource_type, ResourceFactory> ResourceFactoryTable;

		ResourceFactoryTable build_resource_factory_table()
		{
			ResourceFactoryTable table;


			return table;
		};

		const ResourceFactoryTable RESOURCE_FACTORY_TABLE = build_resource_factory_table();
		

	}

	ResourcePtr create_resource( const ResourceInfo& resource_info )
	{
		auto factory_it = RESOURCE_FACTORY_TABLE.find( resource_info.type() );
		if( factory_it != end(RESOURCE_FACTORY_TABLE) )
		{
			auto factory = factory_it->second;
			return factory( resource_info.uri() );
		}

		return ResourcePtr();
	}

}
}