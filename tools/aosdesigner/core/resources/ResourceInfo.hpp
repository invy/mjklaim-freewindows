#ifndef HGUARD_AOSD_CORE_RESOURCEINFO_HPP__
#define HGUARD_AOSD_CORE_RESOURCEINFO_HPP__
#pragma once

#include "URI.hpp"
#include "aosl/resource.hpp"

namespace aosd
{
namespace core
{
	class ResourceInfo
	{
	public:

		ResourceInfo( const URI& resource_uri, const Resource_type& resource_type ) : m_uri( resource_uri ), m_type( resource_type ) {}
		ResourceInfo( const aosl::Resource& resource_data ) : m_uri( resource_data.data() ), m_type( resource_data.type() ) {}
		ResourceInfo() {}

		URI uri() const { return m_uri; }
		aosl::Resource_type type() const { return m_type; }

	private:
		URI			m_uri;
		aosl::Resource_type m_type;
	};

}
}


#endif
