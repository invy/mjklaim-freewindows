// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__EVENT_TYPE_INL
#define AOSLCPP_AOSL__EVENT_TYPE_INL

// Begin prologue.
//
//
// End prologue.

namespace aosl
{
  // Event_type
  // 

  inline
  Event_type::
  Event_type (Value v)
  : ::xml_schema::String (_xsd_Event_type_literals_[v])
  {
  }

  inline
  Event_type::
  Event_type (const char* v)
  : ::xml_schema::String (v)
  {
  }

  inline
  Event_type::
  Event_type (const ::std::string& v)
  : ::xml_schema::String (v)
  {
  }

  inline
  Event_type::
  Event_type (const ::xml_schema::String& v)
  : ::xml_schema::String (v)
  {
  }

  inline
  Event_type::
  Event_type (const Event_type& v,
              ::xml_schema::Flags f,
              ::xml_schema::Container* c)
  : ::xml_schema::String (v, f, c)
  {
  }

  inline
  Event_type& Event_type::
  operator= (Value v)
  {
    static_cast< ::xml_schema::String& > (*this) = 
    ::xml_schema::String (_xsd_Event_type_literals_[v]);

    return *this;
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__EVENT_TYPE_INL
