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

#include "aosl/library_include.hpp"

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
  // Library_include
  //

  Library_include::
  Library_include (const ::xml_schema::Uri& _xsd_Uri_base)
  : ::aosl::Source_uri (_xsd_Uri_base)
  {
  }

  Library_include::
  Library_include (const Library_include& x,
                   ::xml_schema::Flags f,
                   ::xml_schema::Container* c)
  : ::aosl::Source_uri (x, f, c)
  {
  }

  Library_include::
  Library_include (const ::xercesc::DOMElement& e,
                   ::xml_schema::Flags f,
                   ::xml_schema::Container* c)
  : ::aosl::Source_uri (e, f, c)
  {
  }

  Library_include::
  Library_include (const ::xercesc::DOMAttr& a,
                   ::xml_schema::Flags f,
                   ::xml_schema::Container* c)
  : ::aosl::Source_uri (a, f, c)
  {
  }

  Library_include::
  Library_include (const ::std::string& s,
                   const ::xercesc::DOMElement* e,
                   ::xml_schema::Flags f,
                   ::xml_schema::Container* c)
  : ::aosl::Source_uri (s, e, f, c)
  {
  }

  Library_include* Library_include::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Library_include (*this, f, c);
  }

  Library_include::
  ~Library_include ()
  {
  }
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
  operator<< (::std::ostream& o, const Library_include& i)
  {
    o << static_cast< const ::aosl::Source_uri& > (i);

    return o;
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
  operator<< (::xercesc::DOMElement& e, const Library_include& i)
  {
    e << static_cast< const ::aosl::Source_uri& > (i);
  }

  void
  operator<< (::xercesc::DOMAttr& a, const Library_include& i)
  {
    a << static_cast< const ::aosl::Source_uri& > (i);
  }

  void
  operator<< (::xml_schema::ListStream& l,
              const Library_include& i)
  {
    l << static_cast< const ::aosl::Source_uri& > (i);
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

