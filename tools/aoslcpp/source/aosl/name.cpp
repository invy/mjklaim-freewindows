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

#include "aoslcpp/aosl/name.hpp"

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
  // Name
  //

  Name::
  Name ()
  : ::xml_schema::String ()
  {
  }

  Name::
  Name (const char* _xsd_String_base)
  : ::xml_schema::String (_xsd_String_base)
  {
  }

  Name::
  Name (const ::std::string& _xsd_String_base)
  : ::xml_schema::String (_xsd_String_base)
  {
  }

  Name::
  Name (const ::xml_schema::String& _xsd_String_base)
  : ::xml_schema::String (_xsd_String_base)
  {
  }

  Name::
  Name (const Name& x,
        ::xml_schema::Flags f,
        ::xml_schema::Container* c)
  : ::xml_schema::String (x, f, c)
  {
  }

  Name::
  Name (const ::xercesc::DOMElement& e,
        ::xml_schema::Flags f,
        ::xml_schema::Container* c)
  : ::xml_schema::String (e, f, c)
  {
  }

  Name::
  Name (const ::xercesc::DOMAttr& a,
        ::xml_schema::Flags f,
        ::xml_schema::Container* c)
  : ::xml_schema::String (a, f, c)
  {
  }

  Name::
  Name (const ::std::string& s,
        const ::xercesc::DOMElement* e,
        ::xml_schema::Flags f,
        ::xml_schema::Container* c)
  : ::xml_schema::String (s, e, f, c)
  {
  }

  Name* Name::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Name (*this, f, c);
  }

  Name::
  ~Name ()
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
  operator<< (::std::ostream& o, const Name& i)
  {
    o << static_cast< const ::xml_schema::String& > (i);

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
  operator<< (::xercesc::DOMElement& e, const Name& i)
  {
    e << static_cast< const ::xml_schema::String& > (i);
  }

  void
  operator<< (::xercesc::DOMAttr& a, const Name& i)
  {
    a << static_cast< const ::xml_schema::String& > (i);
  }

  void
  operator<< (::xml_schema::ListStream& l,
              const Name& i)
  {
    l << static_cast< const ::xml_schema::String& > (i);
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

