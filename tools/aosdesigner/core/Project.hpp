#ifndef __AOSD_CORE_PROJECT_HPP__
#define __AOSD_CORE_PROJECT_HPP__
#pragma once

#include <boost/ptr_container/ptr_vector.hpp>

#include "core/Sequence.hpp"


namespace aosd 
{ 
namespace core 
{
    /** Contains a set of Sequences and common informations of those sequences.

    */
    class Project
    {
    public:

        Project();
        
        
    private:

        /// Sequences for this project
        boost::ptr_vector< Sequence > m_sequences;



    };


}
}


#endif
