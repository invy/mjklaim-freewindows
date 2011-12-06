#ifndef HGUARD_AOSD_CORE_LIBRARY_HPP__
#define HGUARD_AOSD_CORE_LIBRARY_HPP__
#pragma once

#include <algorithm>
#include <map>
#include <vector>


#include "aosl/resource_id.hpp"
#include "core/resources/ResourcePtr.hpp"

namespace aosl
{
	class Library;
}

namespace aosd
{
namespace core
{
	/** Library of resources.
	**/
	class Library
	{
	public:

		Library();
		explicit Library( const aosl::Library& library_info );
		~Library();

		/** Update the content of the library. **/
		void update( const aosl::Library& library_info );
				
		/** Import resources from another library. **/
		void import( const Library& library );

		void add( aosl::Resource_id resource_id, ResourcePtr resource );

		void clear();

		ResourcePtr find( aosl::Resource_id resource_id );
		
	private:

		std::map< aosl::Resource_id,  ResourcePtr > m_resource_registry;

		std::vector< ResourcePtr > m_resources;

	};

}
}


#endif
