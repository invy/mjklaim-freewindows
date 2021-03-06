// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__OBJECT_INTERACTIVE_INL
#define AOSLCPP_AOSL__OBJECT_INTERACTIVE_INL

// Begin prologue.
//
//
// End prologue.

#include "aosl/object.inl"

#include "aosl/properties_graphic_object.hpp"
#include "aosl/properties_graphic_object.inl"

#include "aosl/properties_interactive_object.hpp"
#include "aosl/properties_interactive_object.inl"

namespace aosl
{
  // Object_interactive
  // 

  inline
  const Object_interactive::GraphicType& Object_interactive::
  graphic () const
  {
    return this->graphic_.get ();
  }

  inline
  Object_interactive::GraphicType& Object_interactive::
  graphic ()
  {
    return this->graphic_.get ();
  }

  inline
  void Object_interactive::
  graphic (const GraphicType& x)
  {
    this->graphic_.set (x);
  }

  inline
  void Object_interactive::
  graphic (::std::auto_ptr< GraphicType > x)
  {
    this->graphic_.set (x);
  }

  inline
  ::std::auto_ptr< Object_interactive::GraphicType > Object_interactive::
  detach_graphic ()
  {
    return this->graphic_.detach ();
  }

  inline
  const Object_interactive::InteractionType& Object_interactive::
  interaction () const
  {
    return this->interaction_.get ();
  }

  inline
  Object_interactive::InteractionType& Object_interactive::
  interaction ()
  {
    return this->interaction_.get ();
  }

  inline
  void Object_interactive::
  interaction (const InteractionType& x)
  {
    this->interaction_.set (x);
  }

  inline
  void Object_interactive::
  interaction (::std::auto_ptr< InteractionType > x)
  {
    this->interaction_.set (x);
  }

  inline
  ::std::auto_ptr< Object_interactive::InteractionType > Object_interactive::
  detach_interaction ()
  {
    return this->interaction_.detach ();
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__OBJECT_INTERACTIVE_INL
