// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__EVENT_SELECTION_INL
#define AOSLCPP_AOSL__EVENT_SELECTION_INL

// Begin prologue.
//
//
// End prologue.

#include "aoslcpp/aosl/event_selection_base.inl"

#include "aoslcpp/aosl/object_ref.hpp"
#include "aoslcpp/aosl/object_ref.inl"

namespace aosl
{
  // Event_selection
  // 

  inline
  const Event_selection::ObjectType& Event_selection::
  object () const
  {
    return this->object_.get ();
  }

  inline
  Event_selection::ObjectType& Event_selection::
  object ()
  {
    return this->object_.get ();
  }

  inline
  void Event_selection::
  object (const ObjectType& x)
  {
    this->object_.set (x);
  }

  inline
  void Event_selection::
  object (::std::auto_ptr< ObjectType > x)
  {
    this->object_.set (x);
  }

  inline
  ::std::auto_ptr< Event_selection::ObjectType > Event_selection::
  detach_object ()
  {
    return this->object_.detach ();
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__EVENT_SELECTION_INL
