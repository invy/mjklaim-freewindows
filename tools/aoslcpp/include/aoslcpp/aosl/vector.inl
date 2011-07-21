// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__VECTOR_INL
#define AOSLCPP_AOSL__VECTOR_INL

// Begin prologue.
//
//
// End prologue.

#include "aoslcpp/aosl/unit_space.hpp"
#include "aoslcpp/aosl/unit_space.inl"

namespace aosl
{
  // Vector
  // 

  inline
  const Vector::XType& Vector::
  x () const
  {
    return this->x_.get ();
  }

  inline
  Vector::XType& Vector::
  x ()
  {
    return this->x_.get ();
  }

  inline
  void Vector::
  x (const XType& x)
  {
    this->x_.set (x);
  }

  inline
  void Vector::
  x (::std::auto_ptr< XType > x)
  {
    this->x_.set (x);
  }

  inline
  ::std::auto_ptr< Vector::XType > Vector::
  detach_x ()
  {
    return this->x_.detach ();
  }

  inline
  Vector::XType Vector::
  x_default_value ()
  {
    return XType (.0);
  }

  inline
  const Vector::YType& Vector::
  y () const
  {
    return this->y_.get ();
  }

  inline
  Vector::YType& Vector::
  y ()
  {
    return this->y_.get ();
  }

  inline
  void Vector::
  y (const YType& x)
  {
    this->y_.set (x);
  }

  inline
  void Vector::
  y (::std::auto_ptr< YType > x)
  {
    this->y_.set (x);
  }

  inline
  ::std::auto_ptr< Vector::YType > Vector::
  detach_y ()
  {
    return this->y_.detach ();
  }

  inline
  Vector::YType Vector::
  y_default_value ()
  {
    return YType (.0);
  }

  inline
  const Vector::ZType& Vector::
  z () const
  {
    return this->z_.get ();
  }

  inline
  Vector::ZType& Vector::
  z ()
  {
    return this->z_.get ();
  }

  inline
  void Vector::
  z (const ZType& x)
  {
    this->z_.set (x);
  }

  inline
  void Vector::
  z (::std::auto_ptr< ZType > x)
  {
    this->z_.set (x);
  }

  inline
  ::std::auto_ptr< Vector::ZType > Vector::
  detach_z ()
  {
    return this->z_.detach ();
  }

  inline
  Vector::ZType Vector::
  z_default_value ()
  {
    return ZType (.0);
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__VECTOR_INL
