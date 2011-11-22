#ifndef HGUARD_AOSD_CORE_LIBRARY_HPP__
#define HGUARD_AOSD_CORE_LIBRARY_HPP__
#pragma once

#include <vector>
#include <algorithm>


namespace aosl
{
	class Library;
}

namespace aosd
{
namespace core
{
	class Resource;

	class Library
	{
	public:

		Library();
		~Library();

		/** Update the content of the library. **/
		void update( const aosl::Library& library_info );
				
		/** Import resources from another library. **/
		void import( const Library& library );

		/** Read-only walk through all resources in this Library. **/
		template< class Func >
		void for_each_resource( Func func )
		{
			std::for_each( m_resources.begin(), m_resources.end(), [&]( const Resource& resource ){ func(resource); } );
		}
		
	private:

		std::vector< Resource > m_resources;

	};

}
}


#endif
