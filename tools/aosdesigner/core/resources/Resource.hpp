#ifndef HGUARD_AOSD_CORE_RESOURCE_HPP__
#define HGUARD_AOSD_CORE_RESOURCE_HPP__
#pragma once

#include <boost/noncopyable.hpp>

#include "core/resources/URI.hpp"

namespace aosd
{
namespace core
{
	class Resource
		: public boost::noncopyable
	{
	public:

		explicit Resource( const URI& uri );
		virtual ~Resource();
		
		void load();
		void unload();


		const URI& uri() const { return m_uri; }

	protected:

		virtual void on_load() = 0;
		virtual void on_unload() = 0;

	private:

		const URI m_uri;
		
	};

	class Resource_Unknow
		: public Resource
	{
	public:
		explicit Resource_Unknow( const URI& uri ) : Resource( uri ){}
	private:
		void on_load(){}
		void on_unload(){}
	};

}
}


#endif
