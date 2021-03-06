// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__SCRIPT_INL
#define AOSLCPP_AOSL__SCRIPT_INL

// Begin prologue.
//
//
// End prologue.

#include "aosl/name.hpp"
#include "aosl/name.inl"

#include "aosl/activation.hpp"
#include "aosl/activation.inl"

#include "aosl/unit_time.hpp"
#include "aosl/unit_time.inl"

namespace aosl
{
  // Script
  // 

  inline
  const Script::LangType& Script::
  lang () const
  {
    return this->lang_.get ();
  }

  inline
  Script::LangType& Script::
  lang ()
  {
    return this->lang_.get ();
  }

  inline
  void Script::
  lang (const LangType& x)
  {
    this->lang_.set (x);
  }

  inline
  void Script::
  lang (::std::auto_ptr< LangType > x)
  {
    this->lang_.set (x);
  }

  inline
  ::std::auto_ptr< Script::LangType > Script::
  detach_lang ()
  {
    return this->lang_.detach ();
  }

  inline
  const Script::ActivationType& Script::
  activation () const
  {
    return this->activation_.get ();
  }

  inline
  Script::ActivationType& Script::
  activation ()
  {
    return this->activation_.get ();
  }

  inline
  void Script::
  activation (const ActivationType& x)
  {
    this->activation_.set (x);
  }

  inline
  void Script::
  activation (::std::auto_ptr< ActivationType > x)
  {
    this->activation_.set (x);
  }

  inline
  ::std::auto_ptr< Script::ActivationType > Script::
  detach_activation ()
  {
    return this->activation_.detach ();
  }

  inline
  const Script::ActivationType& Script::
  activation_default_value ()
  {
    return activation_default_value_;
  }

  inline
  const Script::LoopType& Script::
  loop () const
  {
    return this->loop_.get ();
  }

  inline
  Script::LoopType& Script::
  loop ()
  {
    return this->loop_.get ();
  }

  inline
  void Script::
  loop (const LoopType& x)
  {
    this->loop_.set (x);
  }

  inline
  Script::LoopType Script::
  loop_default_value ()
  {
    return LoopType (false);
  }

  inline
  const Script::IntervalType& Script::
  interval () const
  {
    return this->interval_.get ();
  }

  inline
  Script::IntervalType& Script::
  interval ()
  {
    return this->interval_.get ();
  }

  inline
  void Script::
  interval (const IntervalType& x)
  {
    this->interval_.set (x);
  }

  inline
  void Script::
  interval (::std::auto_ptr< IntervalType > x)
  {
    this->interval_.set (x);
  }

  inline
  ::std::auto_ptr< Script::IntervalType > Script::
  detach_interval ()
  {
    return this->interval_.detach ();
  }

  inline
  Script::IntervalType Script::
  interval_default_value ()
  {
    return IntervalType (0.0);
  }

  inline
  const Script::SourceOptional& Script::
  source () const
  {
    return this->source_;
  }

  inline
  Script::SourceOptional& Script::
  source ()
  {
    return this->source_;
  }

  inline
  void Script::
  source (const SourceType& x)
  {
    this->source_.set (x);
  }

  inline
  void Script::
  source (const SourceOptional& x)
  {
    this->source_ = x;
  }

  inline
  void Script::
  source (::std::auto_ptr< SourceType > x)
  {
    this->source_.set (x);
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__SCRIPT_INL
