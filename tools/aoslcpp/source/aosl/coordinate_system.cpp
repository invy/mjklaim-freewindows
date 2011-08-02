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

#include "aoslcpp/aosl/coordinate_system.hpp"

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
  // Coordinate_system
  //

  Coordinate_system::
  Coordinate_system (const XaxisType& xaxis,
                     const YaxisType& yaxis,
                     const ZaxisType& zaxis)
  : ::xml_schema::Type (),
    xaxis_ (xaxis, ::xml_schema::Flags (), this),
    yaxis_ (yaxis, ::xml_schema::Flags (), this),
    zaxis_ (zaxis, ::xml_schema::Flags (), this)
  {
  }

  Coordinate_system::
  Coordinate_system (::std::auto_ptr< XaxisType >& xaxis,
                     ::std::auto_ptr< YaxisType >& yaxis,
                     ::std::auto_ptr< ZaxisType >& zaxis)
  : ::xml_schema::Type (),
    xaxis_ (xaxis, ::xml_schema::Flags (), this),
    yaxis_ (yaxis, ::xml_schema::Flags (), this),
    zaxis_ (zaxis, ::xml_schema::Flags (), this)
  {
  }

  Coordinate_system::
  Coordinate_system (const Coordinate_system& x,
                     ::xml_schema::Flags f,
                     ::xml_schema::Container* c)
  : ::xml_schema::Type (x, f, c),
    xaxis_ (x.xaxis_, f, this),
    yaxis_ (x.yaxis_, f, this),
    zaxis_ (x.zaxis_, f, this)
  {
  }

  Coordinate_system::
  Coordinate_system (const ::xercesc::DOMElement& e,
                     ::xml_schema::Flags f,
                     ::xml_schema::Container* c)
  : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
    xaxis_ (f, this),
    yaxis_ (f, this),
    zaxis_ (f, this)
  {
    if ((f & ::xml_schema::Flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false);
      this->parse (p, f);
    }
  }

  void Coordinate_system::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::Flags f)
  {
    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // xaxis
      //
      if (n.name () == "xaxis" && n.namespace_ () == "artofsequence.org/aosl/1.0")
      {
        ::std::auto_ptr< XaxisType > r (
          XaxisTraits::create (i, f, this));

        if (!xaxis_.present ())
        {
          this->xaxis_.set (r);
          continue;
        }
      }

      // yaxis
      //
      if (n.name () == "yaxis" && n.namespace_ () == "artofsequence.org/aosl/1.0")
      {
        ::std::auto_ptr< YaxisType > r (
          YaxisTraits::create (i, f, this));

        if (!yaxis_.present ())
        {
          this->yaxis_.set (r);
          continue;
        }
      }

      // zaxis
      //
      if (n.name () == "zaxis" && n.namespace_ () == "artofsequence.org/aosl/1.0")
      {
        ::std::auto_ptr< ZaxisType > r (
          ZaxisTraits::create (i, f, this));

        if (!zaxis_.present ())
        {
          this->zaxis_.set (r);
          continue;
        }
      }

      break;
    }

    if (!xaxis_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "xaxis",
        "artofsequence.org/aosl/1.0");
    }

    if (!yaxis_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "yaxis",
        "artofsequence.org/aosl/1.0");
    }

    if (!zaxis_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "zaxis",
        "artofsequence.org/aosl/1.0");
    }
  }

  Coordinate_system* Coordinate_system::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Coordinate_system (*this, f, c);
  }

  Coordinate_system::
  ~Coordinate_system ()
  {
  }

  bool
  operator== (const Coordinate_system& x, const Coordinate_system& y)
  {
    if (!(x.xaxis () == y.xaxis ()))
      return false;

    if (!(x.yaxis () == y.yaxis ()))
      return false;

    if (!(x.zaxis () == y.zaxis ()))
      return false;

    return true;
  }

  bool
  operator!= (const Coordinate_system& x, const Coordinate_system& y)
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
  operator<< (::std::ostream& o, const Coordinate_system& i)
  {
    o << ::std::endl << "xaxis: " << i.xaxis ();
    o << ::std::endl << "yaxis: " << i.yaxis ();
    o << ::std::endl << "zaxis: " << i.zaxis ();
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
  operator<< (::xercesc::DOMElement& e, const Coordinate_system& i)
  {
    e << static_cast< const ::xml_schema::Type& > (i);

    // xaxis
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "xaxis",
          "artofsequence.org/aosl/1.0",
          e));

      s << i.xaxis ();
    }

    // yaxis
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "yaxis",
          "artofsequence.org/aosl/1.0",
          e));

      s << i.yaxis ();
    }

    // zaxis
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "zaxis",
          "artofsequence.org/aosl/1.0",
          e));

      s << i.zaxis ();
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

