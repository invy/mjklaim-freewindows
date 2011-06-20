#ifndef AOSD_UTIL_SINGLETON_HPP
#define AOSD_UTIL_SINGLETON_HPP
#pragma once

#include <boost/noncopyable.hpp>

#include <QtGlobal>

namespace aosd
{
namespace util
{
        
    template<typename T>
    class Singleton 
        : boost::noncopyable
    {
        static T* ms_singleton;

    protected:

        Singleton()
        {
            Q_ASSERT( ms_singleton == nullptr );
            ms_singleton = static_cast<T*>(this);
        }

        ~Singleton()
        {
            Q_ASSERT( ms_singleton != nullptr );
            ms_singleton = nullptr;
        }

    public:

        static inline void create()
        {
            Q_ASSERT( ms_singleton == nullptr );
            new T();
        }

        static inline T& instance()
        {
            Q_ASSERT( ms_singleton );
            return *ms_singleton;
        }

        static inline void destroy()
        {
            Q_ASSERT( ms_singleton );
            delete ms_singleton;
            ms_singleton = nullptr;
        }

        static inline bool isValid()
        {
            return ( ms_singleton != nullptr );
        }

    };

    template <typename T> T* Singleton <T>::ms_singleton = nullptr;

}
}
#endif