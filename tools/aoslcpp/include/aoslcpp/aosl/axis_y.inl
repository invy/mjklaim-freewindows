// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__AXIS_Y_INL
#define AOSLCPP_AOSL__AXIS_Y_INL

// Begin prologue.
//
//
// End prologue.

#include "aoslcpp/aosl/axis_origin_y.hpp"
#include "aoslcpp/aosl/axis_origin_y.inl"

#include "aoslcpp/aosl/axis_positive_y.hpp"
#include "aoslcpp/aosl/axis_positive_y.inl"

namespace aosl
{
  // Axis_y
  // 

  inline
  const Axis_y::OriginType& Axis_y::
  origin () const
  {
    return this->origin_.get ();
  }

  inline
  Axis_y::OriginType& Axis_y::
  origin ()
  {
    return this->origin_.get ();
  }

  inline
  void Axis_y::
  origin (const OriginType& x)
  {
    this->origin_.set (x);
  }

  inline
  void Axis_y::
  origin (::std::auto_ptr< OriginType > x)
  {
    this->origin_.set (x);
  }

  inline
  ::std::auto_ptr< Axis_y::OriginType > Axis_y::
  detach_origin ()
  {
    return this->origin_.detach ();
  }

  inline
  const Axis_y::OriginType& Axis_y::
  origin_default_value ()
  {
    return origin_default_value_;
  }

  inline
  const Axis_y::PositiveType& Axis_y::
  positive () const
  {
    return this->positive_.get ();
  }

  inline
  Axis_y::PositiveType& Axis_y::
  positive ()
  {
    return this->positive_.get ();
  }

  inline
  void Axis_y::
  positive (const PositiveType& x)
  {
    this->positive_.set (x);
  }

  inline
  void Axis_y::
  positive (::std::auto_ptr< PositiveType > x)
  {
    this->positive_.set (x);
  }

  inline
  ::std::auto_ptr< Axis_y::PositiveType > Axis_y::
  detach_positive ()
  {
    return this->positive_.detach ();
  }

  inline
  const Axis_y::PositiveType& Axis_y::
  positive_default_value ()
  {
    return positive_default_value_;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__AXIS_Y_INL
