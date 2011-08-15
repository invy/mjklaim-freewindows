// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__LIST_CHANGE_INL
#define AOSLCPP_AOSL__LIST_CHANGE_INL

// Begin prologue.
//
//
// End prologue.

#include "aoslcpp/aosl/change.hpp"
#include "aoslcpp/aosl/change.inl"

namespace aosl
{
  // List_change
  // 

  inline
  const List_change::ChangeSequence& List_change::
  change () const
  {
    return this->change_;
  }

  inline
  List_change::ChangeSequence& List_change::
  change ()
  {
    return this->change_;
  }

  inline
  void List_change::
  change (const ChangeSequence& s)
  {
    this->change_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__LIST_CHANGE_INL
