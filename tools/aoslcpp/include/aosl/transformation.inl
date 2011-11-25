// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__TRANSFORMATION_INL
#define AOSLCPP_AOSL__TRANSFORMATION_INL

// Begin prologue.
//
//
// End prologue.

#include "aosl/vector.hpp"
#include "aosl/vector.inl"

#include "aosl/rotation.hpp"
#include "aosl/rotation.inl"

#include "aosl/referential.hpp"
#include "aosl/referential.inl"

namespace aosl
{
  // Transformation
  // 

  inline
  const Transformation::TranslationOptional& Transformation::
  translation () const
  {
    return this->translation_;
  }

  inline
  Transformation::TranslationOptional& Transformation::
  translation ()
  {
    return this->translation_;
  }

  inline
  void Transformation::
  translation (const TranslationType& x)
  {
    this->translation_.set (x);
  }

  inline
  void Transformation::
  translation (const TranslationOptional& x)
  {
    this->translation_ = x;
  }

  inline
  void Transformation::
  translation (::std::auto_ptr< TranslationType > x)
  {
    this->translation_.set (x);
  }

  inline
  const Transformation::ScaleOptional& Transformation::
  scale () const
  {
    return this->scale_;
  }

  inline
  Transformation::ScaleOptional& Transformation::
  scale ()
  {
    return this->scale_;
  }

  inline
  void Transformation::
  scale (const ScaleType& x)
  {
    this->scale_.set (x);
  }

  inline
  void Transformation::
  scale (const ScaleOptional& x)
  {
    this->scale_ = x;
  }

  inline
  void Transformation::
  scale (::std::auto_ptr< ScaleType > x)
  {
    this->scale_.set (x);
  }

  inline
  const Transformation::RotationOptional& Transformation::
  rotation () const
  {
    return this->rotation_;
  }

  inline
  Transformation::RotationOptional& Transformation::
  rotation ()
  {
    return this->rotation_;
  }

  inline
  void Transformation::
  rotation (const RotationType& x)
  {
    this->rotation_.set (x);
  }

  inline
  void Transformation::
  rotation (const RotationOptional& x)
  {
    this->rotation_ = x;
  }

  inline
  void Transformation::
  rotation (::std::auto_ptr< RotationType > x)
  {
    this->rotation_.set (x);
  }

  inline
  const Transformation::CenterOptional& Transformation::
  center () const
  {
    return this->center_;
  }

  inline
  Transformation::CenterOptional& Transformation::
  center ()
  {
    return this->center_;
  }

  inline
  void Transformation::
  center (const CenterType& x)
  {
    this->center_.set (x);
  }

  inline
  void Transformation::
  center (const CenterOptional& x)
  {
    this->center_ = x;
  }

  inline
  void Transformation::
  center (::std::auto_ptr< CenterType > x)
  {
    this->center_.set (x);
  }

  inline
  const Transformation::ReferentialType& Transformation::
  referential () const
  {
    return this->referential_.get ();
  }

  inline
  Transformation::ReferentialType& Transformation::
  referential ()
  {
    return this->referential_.get ();
  }

  inline
  void Transformation::
  referential (const ReferentialType& x)
  {
    this->referential_.set (x);
  }

  inline
  void Transformation::
  referential (::std::auto_ptr< ReferentialType > x)
  {
    this->referential_.set (x);
  }

  inline
  ::std::auto_ptr< Transformation::ReferentialType > Transformation::
  detach_referential ()
  {
    return this->referential_.detach ();
  }

  inline
  const Transformation::ReferentialType& Transformation::
  referential_default_value ()
  {
    return referential_default_value_;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__TRANSFORMATION_INL