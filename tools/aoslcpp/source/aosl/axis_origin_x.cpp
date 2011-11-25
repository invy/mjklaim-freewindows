// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

// Begin prologue.
//

#define AOSLCPP_SOURCE 

//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "aosl/axis_origin_x.hpp"

#include <xsd/cxx/xml/dom/wildcard-source.hxx>

#include <xsd/cxx/xml/dom/parsing-source.hxx>

#include <xsd/cxx/tree/type-factory-map.hxx>

#include <xsd/cxx/tree/comparison-map.hxx>

namespace _xsd
{
  static
  const ::xsd::cxx::tree::type_factory_plate< 0, char >
  type_factory_plate_init;

  static
  const ::xsd::cxx::tree::comparison_plate< 0, char >
  comparison_plate_init;
}

namespace aosl
{
  // Axis_origin_x
  //

  Axis_origin_x::
  Axis_origin_x (const ::xercesc::DOMElement& e,
                 ::xml_schema::Flags f,
                 ::xml_schema::Container* c)
  : ::xml_schema::String (e, f, c)
  {
    _xsd_Axis_origin_x_convert ();
  }

  Axis_origin_x::
  Axis_origin_x (const ::xercesc::DOMAttr& a,
                 ::xml_schema::Flags f,
                 ::xml_schema::Container* c)
  : ::xml_schema::String (a, f, c)
  {
    _xsd_Axis_origin_x_convert ();
  }

  Axis_origin_x::
  Axis_origin_x (const ::std::string& s,
                 const ::xercesc::DOMElement* e,
                 ::xml_schema::Flags f,
                 ::xml_schema::Container* c)
  : ::xml_schema::String (s, e, f, c)
  {
    _xsd_Axis_origin_x_convert ();
  }

  Axis_origin_x* Axis_origin_x::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Axis_origin_x (*this, f, c);
  }

  Axis_origin_x::Value Axis_origin_x::
  _xsd_Axis_origin_x_convert () const
  {
    ::xsd::cxx::tree::enum_comparator< char > c (_xsd_Axis_origin_x_literals_);
    const Value* i (::std::lower_bound (
                      _xsd_Axis_origin_x_indexes_,
                      _xsd_Axis_origin_x_indexes_ + 3,
                      *this,
                      c));

    if (i == _xsd_Axis_origin_x_indexes_ + 3 || _xsd_Axis_origin_x_literals_[*i] != *this)
    {
      throw ::xsd::cxx::tree::unexpected_enumerator < char > (*this);
    }

    return *i;
  }

  const char* const Axis_origin_x::
  _xsd_Axis_origin_x_literals_[3] =
  {
    "left",
    "right",
    "center"
  };

  const Axis_origin_x::Value Axis_origin_x::
  _xsd_Axis_origin_x_indexes_[3] =
  {
    ::aosl::Axis_origin_x::center,
    ::aosl::Axis_origin_x::left,
    ::aosl::Axis_origin_x::right
  };
}

#include <ostream>

#include <xsd/cxx/tree/std-ostream-map.hxx>

namespace _xsd
{
  static
  const ::xsd::cxx::tree::std_ostream_plate< 0, char >
  std_ostream_plate_init;
}

namespace aosl
{
  ::std::ostream&
  operator<< (::std::ostream& o, Axis_origin_x::Value i)
  {
    return o << Axis_origin_x::_xsd_Axis_origin_x_literals_[i];
  }

  ::std::ostream&
  operator<< (::std::ostream& o, const Axis_origin_x& i)
  {
    return o << static_cast< const ::xml_schema::String& > (i);
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace aosl
{
}

#include <ostream>
#include <xsd/cxx/tree/error-handler.hxx>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

#include <xsd/cxx/tree/type-serializer-map.hxx>

namespace _xsd
{
  static
  const ::xsd::cxx::tree::type_serializer_plate< 0, char >
  type_serializer_plate_init;
}

namespace aosl
{
  void
  operator<< (::xercesc::DOMElement& e, const Axis_origin_x& i)
  {
    e << static_cast< const ::xml_schema::String& > (i);
  }

  void
  operator<< (::xercesc::DOMAttr& a, const Axis_origin_x& i)
  {
    a << static_cast< const ::xml_schema::String& > (i);
  }

  void
  operator<< (::xml_schema::ListStream& l,
              const Axis_origin_x& i)
  {
    l << static_cast< const ::xml_schema::String& > (i);
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.
