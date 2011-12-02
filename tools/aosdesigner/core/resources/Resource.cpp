#include "Resource.hpp"



namespace aosd
{
namespace core
{

	Resource::Resource( const URI& uri )
	{

	}

	Resource::~Resource()
	{

	}

	void Resource::load()
	{
		on_load();
	}

	void Resource::unload()
	{
		on_unload();
	}

}
}