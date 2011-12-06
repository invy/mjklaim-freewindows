#include "Library.hpp"

#include "core/Context.hpp"
#include "core/resources/Resource.hpp"
#include "aosl/library.hpp"

#include "utilcpp/Assert.hpp"

namespace aosd
{
namespace core
{



	Library::Library()
	{

	}

	Library::Library( const aosl::Library& library_info )
	{
		update( library_info );
	}

	Library::~Library()
	{

	}

	void Library::update( const aosl::Library& library_info )
	{
		clear();

		const auto& resource_list = library_info.resources().resource();

		std::for_each( begin(resource_list), end(resource_list), [&]( const aosl::Resource& resource )
		{
			auto resource_object = Context::instance().resource_provider().get( resource );
			UTILCPP_ASSERT_NOT_NULL( resource_object ); // TODO : replace by exception?
			add( resource.id() , resource_object );
		});

	}

	void Library::import( const Library& library )
	{
		std::for_each( begin(library.m_resource_registry), end(library.m_resource_registry), [&]( std::pair< aosl::Resource_id, ResourcePtr > resource_it )
		{
			add( resource_it.first, resource_it.second );
		});
	}

	void Library::clear()
	{
		m_resource_registry.clear();
		m_resources.clear();
	}

	void Library::add( aosl::Resource_id resource_id, ResourcePtr resource )
	{
		if( resource && !resource_id.empty() )
		{
			auto success = m_resource_registry.insert( std::make_pair( resource_id, resource ) );
		}
		else
		{
			throw std::exception( "Tried to add invalid resource!" );
		}
	}

	ResourcePtr Library::find( aosl::Resource_id resource_id )
	{
		auto resource_it = m_resource_registry.find( resource_id );
		if( resource_it != end(m_resource_registry) )
		{
			UTILCPP_ASSERT_NOT_NULL( resource_it->second );
			return resource_it->second;
		}

		return ResourcePtr();
	}

}
}