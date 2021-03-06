// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__LIST_TARGET_INL
#define AOSLCPP_AOSL__LIST_TARGET_INL

// Begin prologue.
//
//
// End prologue.

#include "aosl/target.hpp"
#include "aosl/target.inl"

namespace aosl
{
  // List_target
  // 

  inline
  const List_target::TargetSequence& List_target::
  target () const
  {
    return this->target_;
  }

  inline
  List_target::TargetSequence& List_target::
  target ()
  {
    return this->target_;
  }

  inline
  void List_target::
  target (const TargetSequence& s)
  {
    this->target_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__LIST_TARGET_INL
