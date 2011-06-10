#ifndef __AOSD_CORE_SEQUENCE_HPP__
#define __AOSD_CORE_SEQUENCE_HPP__
#pragma once

#include <string>

namespace aosd
{
namespace core
{

    /** A full Sequence as defined in AOSL.
    */
    class Sequence
    {
    public:

        Sequence();
        
        const std::string& name() const { return m_name; }
        


    private:

        std::string m_name;

    };



}
}


#endif
