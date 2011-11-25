// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__EXTENSION_INL
#define AOSLCPP_AOSL__EXTENSION_INL

// Begin prologue.
//
//
// End prologue.

namespace aosl
{
  // Extension
  // 

  inline
  const Extension::AnySequence& Extension::
  any () const
  {
    return this->any_;
  }

  inline
  Extension::AnySequence& Extension::
  any ()
  {
    return this->any_;
  }

  inline
  void Extension::
  any (const AnySequence& s)
  {
    this->any_ = s;
  }

  inline
  const Extension::AnyAttributeSet& Extension::
  any_attribute () const
  {
    return this->any_attribute_;
  }

  inline
  Extension::AnyAttributeSet& Extension::
  any_attribute ()
  {
    return this->any_attribute_;
  }

  inline
  void Extension::
  any_attribute (const AnyAttributeSet& s)
  {
    this->any_attribute_ = s;
  }

  inline
  const ::xercesc::DOMDocument& Extension::
  dom_document () const
  {
    return *dom_document_;
  }

  inline
  ::xercesc::DOMDocument& Extension::
  dom_document ()
  {
    return *dom_document_;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__EXTENSION_INL