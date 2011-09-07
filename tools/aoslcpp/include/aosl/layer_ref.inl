// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__LAYER_REF_INL
#define AOSLCPP_AOSL__LAYER_REF_INL

// Begin prologue.
//
//
// End prologue.

namespace aosl
{
  // Layer_ref
  //

  inline
  Layer_ref::
  Layer_ref (const char* s)
  : ::xml_schema::String (s)
  {
  }

  inline
  Layer_ref::
  Layer_ref (const ::std::string& s)
  : ::xml_schema::String (s)
  {
  }

  inline
  Layer_ref::
  Layer_ref (const Layer_ref& o,
             ::xml_schema::Flags f,
             ::xml_schema::Container* c)
  : ::xml_schema::String (o, f, c)
  {
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__LAYER_REF_INL
