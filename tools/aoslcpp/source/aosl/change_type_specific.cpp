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

#include "aosl/change_type_specific.hpp"

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
  // Change_type_specific
  //

  Change_type_specific::
  Change_type_specific ()
  : ::xml_schema::String ()
  {
  }

  Change_type_specific::
  Change_type_specific (const char* _xsd_String_base)
  : ::xml_schema::String (_xsd_String_base)
  {
  }

  Change_type_specific::
  Change_type_specific (const ::std::string& _xsd_String_base)
  : ::xml_schema::String (_xsd_String_base)
  {
  }

  Change_type_specific::
  Change_type_specific (const ::xml_schema::String& _xsd_String_base)
  : ::xml_schema::String (_xsd_String_base)
  {
  }

  Change_type_specific::
  Change_type_specific (const Change_type_specific& x,
                        ::xml_schema::Flags f,
                        ::xml_schema::Container* c)
  : ::xml_schema::String (x, f, c)
  {
  }

  Change_type_specific::
  Change_type_specific (const ::xercesc::DOMElement& e,
                        ::xml_schema::Flags f,
                        ::xml_schema::Container* c)
  : ::xml_schema::String (e, f, c)
  {
  }

  Change_type_specific::
  Change_type_specific (const ::xercesc::DOMAttr& a,
                        ::xml_schema::Flags f,
                        ::xml_schema::Container* c)
  : ::xml_schema::String (a, f, c)
  {
  }

  Change_type_specific::
  Change_type_specific (const ::std::string& s,
                        const ::xercesc::DOMElement* e,
                        ::xml_schema::Flags f,
                        ::xml_schema::Container* c)
  : ::xml_schema::String (s, e, f, c)
  {
  }

  Change_type_specific* Change_type_specific::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Change_type_specific (*this, f, c);
  }

  Change_type_specific::
  ~Change_type_specific ()
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
  operator<< (::std::ostream& o, const Change_type_specific& i)
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
  operator<< (::xercesc::DOMElement& e, const Change_type_specific& i)
  {
    e << static_cast< const ::xml_schema::String& > (i);
  }

  void
  operator<< (::xercesc::DOMAttr& a, const Change_type_specific& i)
  {
    a << static_cast< const ::xml_schema::String& > (i);
  }

  void
  operator<< (::xml_schema::ListStream& l,
              const Change_type_specific& i)
  {
    l << static_cast< const ::xml_schema::String& > (i);
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

