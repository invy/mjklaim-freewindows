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

#include "aosl/change_deactivate.hpp"

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
  // Change_deactivate
  //

  Change_deactivate::
  Change_deactivate (const ObjectType& object)
  : ::aosl::Change (object)
  {
  }

  Change_deactivate::
  Change_deactivate (const Change_deactivate& x,
                     ::xml_schema::Flags f,
                     ::xml_schema::Container* c)
  : ::aosl::Change (x, f, c)
  {
  }

  Change_deactivate::
  Change_deactivate (const ::xercesc::DOMElement& e,
                     ::xml_schema::Flags f,
                     ::xml_schema::Container* c)
  : ::aosl::Change (e, f, c)
  {
  }

  Change_deactivate* Change_deactivate::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Change_deactivate (*this, f, c);
  }

  Change_deactivate::
  ~Change_deactivate ()
  {
  }

  static
  const ::xsd::cxx::tree::type_factory_initializer< 0, char, Change_deactivate >
  _xsd_Change_deactivate_type_factory_init (
    "change_deactivate",
    "artofsequence.org/aosl/1.0");

  static
  const ::xsd::cxx::tree::comparison_initializer< 0, char, Change_deactivate >
  _xsd_Change_deactivate_comparison_init;
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
  operator<< (::std::ostream& o, const Change_deactivate& i)
  {
    o << static_cast< const ::aosl::Change& > (i);

    return o;
  }

  static
  const ::xsd::cxx::tree::std_ostream_initializer< 0, char, Change_deactivate >
  _xsd_Change_deactivate_std_ostream_init;
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
  operator<< (::xercesc::DOMElement& e, const Change_deactivate& i)
  {
    e << static_cast< const ::aosl::Change& > (i);
  }

  static
  const ::xsd::cxx::tree::type_serializer_initializer< 0, char, Change_deactivate >
  _xsd_Change_deactivate_type_serializer_init (
    "change_deactivate",
    "artofsequence.org/aosl/1.0");
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.
