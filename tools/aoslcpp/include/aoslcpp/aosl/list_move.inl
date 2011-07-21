// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__LIST_MOVE_INL
#define AOSLCPP_AOSL__LIST_MOVE_INL

// Begin prologue.
//
//
// End prologue.

#include "aoslcpp/aosl/move.hpp"
#include "aoslcpp/aosl/move.inl"

namespace aosl
{
  // List_move
  // 

  inline
  const List_move::MoveSequence& List_move::
  move () const
  {
    return this->move_;
  }

  inline
  List_move::MoveSequence& List_move::
  move ()
  {
    return this->move_;
  }

  inline
  void List_move::
  move (const MoveSequence& s)
  {
    this->move_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__LIST_MOVE_INL
