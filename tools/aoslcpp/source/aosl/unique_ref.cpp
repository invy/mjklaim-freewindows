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

#include "aoslcpp/aosl/unique_ref.hpp"

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
  // Unique_ref
  //

  Unique_ref::
  Unique_ref (const ::xml_schema::Idref& _xsd_Idref_base)
  : ::xml_schema::Idref (_xsd_Idref_base)
  {
  }

  Unique_ref::
  Unique_ref (const Unique_ref& x,
              ::xml_schema::Flags f,
              ::xml_schema::Container* c)
  : ::xml_schema::Idref (x, f, c)
  {
  }

  Unique_ref::
  Unique_ref (const ::xercesc::DOMElement& e,
              ::xml_schema::Flags f,
              ::xml_schema::Container* c)
  : ::xml_schema::Idref (e, f, c)
  {
  }

  Unique_ref::
  Unique_ref (const ::xercesc::DOMAttr& a,
              ::xml_schema::Flags f,
              ::xml_schema::Container* c)
  : ::xml_schema::Idref (a, f, c)
  {
  }

  Unique_ref::
  Unique_ref (const ::std::string& s,
              const ::xercesc::DOMElement* e,
              ::xml_schema::Flags f,
              ::xml_schema::Container* c)
  : ::xml_schema::Idref (s, e, f, c)
  {
  }

  Unique_ref* Unique_ref::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Unique_ref (*this, f, c);
  }

  Unique_ref::
  ~Unique_ref ()
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
  operator<< (::std::ostream& o, const Unique_ref& i)
  {
    o << static_cast< const ::xml_schema::Idref& > (i);

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
  operator<< (::xercesc::DOMElement& e, const Unique_ref& i)
  {
    e << static_cast< const ::xml_schema::Idref& > (i);
  }

  void
  operator<< (::xercesc::DOMAttr& a, const Unique_ref& i)
  {
    a << static_cast< const ::xml_schema::Idref& > (i);
  }

  void
  operator<< (::xml_schema::ListStream& l,
              const Unique_ref& i)
  {
    l << static_cast< const ::xml_schema::Idref& > (i);
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

