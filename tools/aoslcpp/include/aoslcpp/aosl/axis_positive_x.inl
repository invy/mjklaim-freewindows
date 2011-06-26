// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__AXIS_POSITIVE_X_INL
#define AOSLCPP_AOSL__AXIS_POSITIVE_X_INL

// Begin prologue.
//
//
// End prologue.

namespace aosl
{
  // Axis_positive_x
  // 

  inline
  Axis_positive_x::
  Axis_positive_x ()
  : ::xml_schema::String ()
  {
  }

  inline
  Axis_positive_x::
  Axis_positive_x (Value v)
  : ::xml_schema::String (_xsd_Axis_positive_x_literals_[v])
  {
  }

  inline
  Axis_positive_x::
  Axis_positive_x (const char* v)
  : ::xml_schema::String (v)
  {
  }

  inline
  Axis_positive_x::
  Axis_positive_x (const ::std::string& v)
  : ::xml_schema::String (v)
  {
  }

  inline
  Axis_positive_x::
  Axis_positive_x (const ::xml_schema::String& v)
  : ::xml_schema::String (v)
  {
  }

  inline
  Axis_positive_x::
  Axis_positive_x (const Axis_positive_x& v,
                   ::xml_schema::Flags f,
                   ::xml_schema::Container* c)
  : ::xml_schema::String (v, f, c)
  {
  }

  inline
  Axis_positive_x& Axis_positive_x::
  operator= (Value v)
  {
    static_cast< ::xml_schema::String& > (*this) = 
    ::xml_schema::String (_xsd_Axis_positive_x_literals_[v]);

    return *this;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__AXIS_POSITIVE_X_INL
