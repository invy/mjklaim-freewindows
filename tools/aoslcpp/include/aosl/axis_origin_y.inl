// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__AXIS_ORIGIN_Y_INL
#define AOSLCPP_AOSL__AXIS_ORIGIN_Y_INL

// Begin prologue.
//
//
// End prologue.

namespace aosl
{
  // Axis_origin_y
  // 

  inline
  Axis_origin_y::
  Axis_origin_y (Value v)
  : ::xml_schema::String (_xsd_Axis_origin_y_literals_[v])
  {
  }

  inline
  Axis_origin_y::
  Axis_origin_y (const char* v)
  : ::xml_schema::String (v)
  {
  }

  inline
  Axis_origin_y::
  Axis_origin_y (const ::std::string& v)
  : ::xml_schema::String (v)
  {
  }

  inline
  Axis_origin_y::
  Axis_origin_y (const ::xml_schema::String& v)
  : ::xml_schema::String (v)
  {
  }

  inline
  Axis_origin_y::
  Axis_origin_y (const Axis_origin_y& v,
                 ::xml_schema::Flags f,
                 ::xml_schema::Container* c)
  : ::xml_schema::String (v, f, c)
  {
  }

  inline
  Axis_origin_y& Axis_origin_y::
  operator= (Value v)
  {
    static_cast< ::xml_schema::String& > (*this) = 
    ::xml_schema::String (_xsd_Axis_origin_y_literals_[v]);

    return *this;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__AXIS_ORIGIN_Y_INL
