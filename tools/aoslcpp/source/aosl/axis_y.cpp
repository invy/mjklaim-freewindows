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

#include "aoslcpp/aosl/axis_y.hpp"

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
  // Axis_y
  //

  const Axis_y::OriginType Axis_y::origin_default_value_ (
    "top");

  const Axis_y::PositiveType Axis_y::positive_default_value_ (
    "down");

  Axis_y::
  Axis_y ()
  : ::xml_schema::Type (),
    origin_ (origin_default_value (), ::xml_schema::Flags (), this),
    positive_ (positive_default_value (), ::xml_schema::Flags (), this)
  {
  }

  Axis_y::
  Axis_y (const Axis_y& x,
          ::xml_schema::Flags f,
          ::xml_schema::Container* c)
  : ::xml_schema::Type (x, f, c),
    origin_ (x.origin_, f, this),
    positive_ (x.positive_, f, this)
  {
  }

  Axis_y::
  Axis_y (const ::xercesc::DOMElement& e,
          ::xml_schema::Flags f,
          ::xml_schema::Container* c)
  : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
    origin_ (f, this),
    positive_ (f, this)
  {
    if ((f & ::xml_schema::Flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, false, true);
      this->parse (p, f);
    }
  }

  void Axis_y::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::Flags f)
  {
    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      if (n.name () == "origin" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< OriginType > r (
          OriginTraits::create (i, f, this));

        this->origin_.set (r);
        continue;
      }

      if (n.name () == "positive" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< PositiveType > r (
          PositiveTraits::create (i, f, this));

        this->positive_.set (r);
        continue;
      }
    }

    if (!origin_.present ())
    {
      this->origin_.set (origin_default_value ());
    }

    if (!positive_.present ())
    {
      this->positive_.set (positive_default_value ());
    }
  }

  Axis_y* Axis_y::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Axis_y (*this, f, c);
  }

  Axis_y::
  ~Axis_y ()
  {
  }

  bool
  operator== (const Axis_y& x, const Axis_y& y)
  {
    if (!(x.origin () == y.origin ()))
      return false;

    if (!(x.positive () == y.positive ()))
      return false;

    return true;
  }

  bool
  operator!= (const Axis_y& x, const Axis_y& y)
  {
    return !(x == y);
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
  operator<< (::std::ostream& o, const Axis_y& i)
  {
    o << ::std::endl << "origin: " << i.origin ();
    o << ::std::endl << "positive: " << i.positive ();
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
  operator<< (::xercesc::DOMElement& e, const Axis_y& i)
  {
    e << static_cast< const ::xml_schema::Type& > (i);

    // origin
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "origin",
          e));

      a << i.origin ();
    }

    // positive
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "positive",
          e));

      a << i.positive ();
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

