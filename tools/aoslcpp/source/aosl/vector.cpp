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

#include "aoslcpp/aosl/vector.hpp"

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
  // Vector
  //

  Vector::
  Vector ()
  : ::xml_schema::Type (),
    x_ (x_default_value (), ::xml_schema::Flags (), this),
    y_ (y_default_value (), ::xml_schema::Flags (), this),
    z_ (z_default_value (), ::xml_schema::Flags (), this)
  {
  }

  Vector::
  Vector (const Vector& x,
          ::xml_schema::Flags f,
          ::xml_schema::Container* c)
  : ::xml_schema::Type (x, f, c),
    x_ (x.x_, f, this),
    y_ (x.y_, f, this),
    z_ (x.z_, f, this)
  {
  }

  Vector::
  Vector (const ::xercesc::DOMElement& e,
          ::xml_schema::Flags f,
          ::xml_schema::Container* c)
  : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
    x_ (f, this),
    y_ (f, this),
    z_ (f, this)
  {
    if ((f & ::xml_schema::Flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, false, true);
      this->parse (p, f);
    }
  }

  void Vector::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::Flags f)
  {
    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      if (n.name () == "x" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< XType > r (
          XTraits::create (i, f, this));

        this->x_.set (r);
        continue;
      }

      if (n.name () == "y" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< YType > r (
          YTraits::create (i, f, this));

        this->y_.set (r);
        continue;
      }

      if (n.name () == "z" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< ZType > r (
          ZTraits::create (i, f, this));

        this->z_.set (r);
        continue;
      }
    }

    if (!x_.present ())
    {
      this->x_.set (x_default_value ());
    }

    if (!y_.present ())
    {
      this->y_.set (y_default_value ());
    }

    if (!z_.present ())
    {
      this->z_.set (z_default_value ());
    }
  }

  Vector* Vector::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Vector (*this, f, c);
  }

  Vector::
  ~Vector ()
  {
  }

  bool
  operator== (const Vector& x, const Vector& y)
  {
    if (!(x.x () == y.x ()))
      return false;

    if (!(x.y () == y.y ()))
      return false;

    if (!(x.z () == y.z ()))
      return false;

    return true;
  }

  bool
  operator!= (const Vector& x, const Vector& y)
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
  operator<< (::std::ostream& o, const Vector& i)
  {
    o << ::std::endl << "x: " << i.x ();
    o << ::std::endl << "y: " << i.y ();
    o << ::std::endl << "z: " << i.z ();
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
  operator<< (::xercesc::DOMElement& e, const Vector& i)
  {
    e << static_cast< const ::xml_schema::Type& > (i);

    // x
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "x",
          e));

      a << i.x ();
    }

    // y
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "y",
          e));

      a << i.y ();
    }

    // z
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "z",
          e));

      a << i.z ();
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

