// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__SPATIAL_AREA_INL
#define AOSLCPP_AOSL__SPATIAL_AREA_INL

// Begin prologue.
//
//
// End prologue.

#include "aosl/vector.inl"

#include "aosl/coordinate_system.hpp"
#include "aosl/coordinate_system.inl"

namespace aosl
{
  // Spatial_area
  // 

  inline
  const Spatial_area::SystemOptional& Spatial_area::
  system () const
  {
    return this->system_;
  }

  inline
  Spatial_area::SystemOptional& Spatial_area::
  system ()
  {
    return this->system_;
  }

  inline
  void Spatial_area::
  system (const SystemType& x)
  {
    this->system_.set (x);
  }

  inline
  void Spatial_area::
  system (const SystemOptional& x)
  {
    this->system_ = x;
  }

  inline
  void Spatial_area::
  system (::std::auto_ptr< SystemType > x)
  {
    this->system_.set (x);
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__SPATIAL_AREA_INL
