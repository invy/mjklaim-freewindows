// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__LIST_LAYER_INL
#define AOSLCPP_AOSL__LIST_LAYER_INL

// Begin prologue.
//
//
// End prologue.

#include "aosl/layer.hpp"
#include "aosl/layer.inl"

namespace aosl
{
  // List_layer
  // 

  inline
  const List_layer::LayerSequence& List_layer::
  layer () const
  {
    return this->layer_;
  }

  inline
  List_layer::LayerSequence& List_layer::
  layer ()
  {
    return this->layer_;
  }

  inline
  void List_layer::
  layer (const LayerSequence& s)
  {
    this->layer_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__LIST_LAYER_INL
