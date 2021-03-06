// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__LIST_RESOURCE_INL
#define AOSLCPP_AOSL__LIST_RESOURCE_INL

// Begin prologue.
//
//
// End prologue.

#include "aosl/resource.hpp"
#include "aosl/resource.inl"

namespace aosl
{
  // List_resource
  // 

  inline
  const List_resource::ResourceSequence& List_resource::
  resource () const
  {
    return this->resource_;
  }

  inline
  List_resource::ResourceSequence& List_resource::
  resource ()
  {
    return this->resource_;
  }

  inline
  void List_resource::
  resource (const ResourceSequence& s)
  {
    this->resource_ = s;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__LIST_RESOURCE_INL
