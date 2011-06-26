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

#include "aoslcpp/aosl/object_sprite.hpp"

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
  // Object_sprite
  //

  Object_sprite::
  Object_sprite ()
  : ::aosl::Object (),
    graphic_ (::xml_schema::Flags (), this)
  {
  }

  Object_sprite::
  Object_sprite (const IdType& id,
                 const GraphicType& graphic)
  : ::aosl::Object (id),
    graphic_ (graphic, ::xml_schema::Flags (), this)
  {
  }

  Object_sprite::
  Object_sprite (const IdType& id,
                 ::std::auto_ptr< GraphicType >& graphic)
  : ::aosl::Object (id),
    graphic_ (graphic, ::xml_schema::Flags (), this)
  {
  }

  Object_sprite::
  Object_sprite (const Object_sprite& x,
                 ::xml_schema::Flags f,
                 ::xml_schema::Container* c)
  : ::aosl::Object (x, f, c),
    graphic_ (x.graphic_, f, this)
  {
  }

  Object_sprite::
  Object_sprite (const ::xercesc::DOMElement& e,
                 ::xml_schema::Flags f,
                 ::xml_schema::Container* c)
  : ::aosl::Object (e, f | ::xml_schema::Flags::base, c),
    graphic_ (f, this)
  {
    if ((f & ::xml_schema::Flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, true);
      this->parse (p, f);
    }
  }

  void Object_sprite::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::Flags f)
  {
    this->::aosl::Object::parse (p, f);

    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // graphic
      //
      if (n.name () == "graphic" && n.namespace_ () == "http://artofsequence.org/aosl/1.x")
      {
        ::std::auto_ptr< GraphicType > r (
          GraphicTraits::create (i, f, this));

        if (!graphic_.present ())
        {
          this->graphic_.set (r);
          continue;
        }
      }

      break;
    }

    if (!graphic_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "graphic",
        "http://artofsequence.org/aosl/1.x");
    }
  }

  Object_sprite* Object_sprite::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Object_sprite (*this, f, c);
  }

  Object_sprite::
  ~Object_sprite ()
  {
  }

  static
  const ::xsd::cxx::tree::type_factory_initializer< 0, char, Object_sprite >
  _xsd_Object_sprite_type_factory_init (
    "object_sprite",
    "http://artofsequence.org/aosl/1.x");

  static
  const ::xsd::cxx::tree::comparison_initializer< 0, char, Object_sprite >
  _xsd_Object_sprite_comparison_init;

  bool
  operator== (const Object_sprite& x, const Object_sprite& y)
  {
    if (!(static_cast< const ::aosl::Object& > (x) ==
          static_cast< const ::aosl::Object& > (y)))
      return false;

    if (!(x.graphic () == y.graphic ()))
      return false;

    return true;
  }

  bool
  operator!= (const Object_sprite& x, const Object_sprite& y)
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
  operator<< (::std::ostream& o, const Object_sprite& i)
  {
    o << static_cast< const ::aosl::Object& > (i);

    o << ::std::endl << "graphic: " << i.graphic ();
    return o;
  }

  static
  const ::xsd::cxx::tree::std_ostream_initializer< 0, char, Object_sprite >
  _xsd_Object_sprite_std_ostream_init;
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
  operator<< (::xercesc::DOMElement& e, const Object_sprite& i)
  {
    e << static_cast< const ::aosl::Object& > (i);

    // graphic
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "graphic",
          "http://artofsequence.org/aosl/1.x",
          e));

      s << i.graphic ();
    }
  }

  static
  const ::xsd::cxx::tree::type_serializer_initializer< 0, char, Object_sprite >
  _xsd_Object_sprite_type_serializer_init (
    "object_sprite",
    "http://artofsequence.org/aosl/1.x");
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

