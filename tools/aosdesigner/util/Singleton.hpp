#ifndef AOSD_UTIL_SINGLETON_HPP
#define AOSD_UTIL_SINGLETON_HPP
#pragma once

#include <boost/noncopyable.hpp>

#include "util/Assert.hpp"

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
            AOSD_ASSERT_NULL( ms_singleton );
            ms_singleton = static_cast<T*>(this);
        }

        ~Singleton()
        {
            AOSD_ASSERT_NOT_NULL( ms_singleton );
            ms_singleton = nullptr;
        }

    public:

        static inline void create()
        {
            AOSD_ASSERT_NULL( ms_singleton );
            new T();
        }

        static inline T& instance()
        {
            AOSD_ASSERT_NOT_NULL( ms_singleton );
            return *ms_singleton;
        }

        static inline void destroy()
        {
            AOSD_ASSERT_NOT_NULL( ms_singleton );
            delete ms_singleton;
            ms_singleton = nullptr;
        }

        static inline bool isValid()
        {
            return ms_singleton;
        }

    };

    template <typename T> T* Singleton <T>::ms_singleton = nullptr;

}
}
#endif