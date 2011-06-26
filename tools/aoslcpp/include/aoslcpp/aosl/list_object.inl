// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__LIST_OBJECT_INL
#define AOSLCPP_AOSL__LIST_OBJECT_INL

// Begin prologue.
//
//
// End prologue.

#include "aoslcpp/aosl/object.hpp"
#include "aoslcpp/aosl/object.inl"

namespace aosl
{
  // List_object
  // 

  inline
  const List_object::ObjectSequence& List_object::
  object () const
  {
    return this->object_;
  }

  inline
  List_object::ObjectSequence& List_object::
  object ()
  {
    return this->object_;
  }

  inline
  void List_object::
  object (const ObjectSequence& s)
  {
    this->object_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__LIST_OBJECT_INL
