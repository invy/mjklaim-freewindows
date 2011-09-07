#ifndef HGUARD_UTILCPP_SINGLETON_HPP
#define HGUARD_UTILCPP_SINGLETON_HPP
#pragma once

#include <boost/noncopyable.hpp>

#include "utilcpp/Assert.hpp"

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
            UTILCPP_ASSERT_NULL( ms_singleton );
            ms_singleton = static_cast<T*>(this);
        }

        ~Singleton()
        {
            UTILCPP_ASSERT_NOT_NULL( ms_singleton );
            ms_singleton = nullptr;
        }

    public:

        static inline void create()
        {
            UTILCPP_ASSERT_NULL( ms_singleton );
            new T();
        }

        static inline T& instance()
        {
            UTILCPP_ASSERT_NOT_NULL( ms_singleton );
            return *ms_singleton;
        }

        static inline void destroy()
        {
            UTILCPP_ASSERT_NOT_NULL( ms_singleton );
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
#endif