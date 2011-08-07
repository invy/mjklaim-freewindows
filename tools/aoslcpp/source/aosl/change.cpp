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

#include "aoslcpp/aosl/change.hpp"

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
  // Change
  //

  const Change::TypeType Change::type_default_value_ (
    "unknown");

  Change::
  Change (const ObjectType& object)
  : ::xml_schema::Type (),
    effects_ (::xml_schema::Flags (), this),
    script_ (::xml_schema::Flags (), this),
    extension_ (::xml_schema::Flags (), this),
    type_ (type_default_value (), ::xml_schema::Flags (), this),
    object_ (object, ::xml_schema::Flags (), this)
  {
  }

  Change::
  Change (const Change& x,
          ::xml_schema::Flags f,
          ::xml_schema::Container* c)
  : ::xml_schema::Type (x, f, c),
    effects_ (x.effects_, f, this),
    script_ (x.script_, f, this),
    extension_ (x.extension_, f, this),
    type_ (x.type_, f, this),
    object_ (x.object_, f, this)
  {
  }

  Change::
  Change (const ::xercesc::DOMElement& e,
          ::xml_schema::Flags f,
          ::xml_schema::Container* c)
  : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
    effects_ (f, this),
    script_ (f, this),
    extension_ (f, this),
    type_ (f, this),
    object_ (f, this)
  {
    if ((f & ::xml_schema::Flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, true);
      this->parse (p, f);
    }
  }

  void Change::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::Flags f)
  {
    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // effects
      //
      if (n.name () == "effects" && n.namespace_ () == "artofsequence.org/aosl/1.0")
      {
        ::std::auto_ptr< EffectsType > r (
          EffectsTraits::create (i, f, this));

        if (!this->effects_)
        {
          this->effects_.set (r);
          continue;
        }
      }

      // script
      //
      if (n.name () == "script" && n.namespace_ () == "artofsequence.org/aosl/1.0")
      {
        ::std::auto_ptr< ScriptType > r (
          ScriptTraits::create (i, f, this));

        if (!this->script_)
        {
          this->script_.set (r);
          continue;
        }
      }

      // extension
      //
      if (n.name () == "extension" && n.namespace_ () == "artofsequence.org/aosl/1.0")
      {
        ::std::auto_ptr< ExtensionType > r (
          ExtensionTraits::create (i, f, this));

        if (!this->extension_)
        {
          this->extension_.set (r);
          continue;
        }
      }

      break;
    }

    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      if (n.name () == "type" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< TypeType > r (
          TypeTraits::create (i, f, this));

        this->type_.set (r);
        continue;
      }

      if (n.name () == "object" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< ObjectType > r (
          ObjectTraits::create (i, f, this));

        this->object_.set (r);
        continue;
      }
    }

    if (!type_.present ())
    {
      this->type_.set (type_default_value ());
    }

    if (!object_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< char > (
        "object",
        "");
    }
  }

  Change* Change::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Change (*this, f, c);
  }

  Change::
  ~Change ()
  {
  }

  static
  const ::xsd::cxx::tree::type_factory_initializer< 0, char, Change >
  _xsd_Change_type_factory_init (
    "change",
    "artofsequence.org/aosl/1.0");

  static
  const ::xsd::cxx::tree::comparison_initializer< 0, char, Change >
  _xsd_Change_comparison_init;

  bool
  operator== (const Change& x, const Change& y)
  {
    if (!(x.effects () == y.effects ()))
      return false;

    if (!(x.script () == y.script ()))
      return false;

    if (!(x.extension () == y.extension ()))
      return false;

    if (!(x.type () == y.type ()))
      return false;

    if (!(x.object () == y.object ()))
      return false;

    return true;
  }

  bool
  operator!= (const Change& x, const Change& y)
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
  operator<< (::std::ostream& o, const Change& i)
  {
    if (i.effects ())
    {
      o << ::std::endl << "effects: " << *i.effects ();
    }

    if (i.script ())
    {
      o << ::std::endl << "script: " << *i.script ();
    }

    if (i.extension ())
    {
      o << ::std::endl << "extension: " << *i.extension ();
    }

    o << ::std::endl << "type: " << i.type ();
    o << ::std::endl << "object: " << i.object ();
    return o;
  }

  static
  const ::xsd::cxx::tree::std_ostream_initializer< 0, char, Change >
  _xsd_Change_std_ostream_init;
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
  operator<< (::xercesc::DOMElement& e, const Change& i)
  {
    e << static_cast< const ::xml_schema::Type& > (i);

    // effects
    //
    if (i.effects ())
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "effects",
          "artofsequence.org/aosl/1.0",
          e));

      s << *i.effects ();
    }

    // script
    //
    if (i.script ())
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "script",
          "artofsequence.org/aosl/1.0",
          e));

      s << *i.script ();
    }

    // extension
    //
    if (i.extension ())
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "extension",
          "artofsequence.org/aosl/1.0",
          e));

      s << *i.extension ();
    }

    // type
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "type",
          e));

      a << i.type ();
    }

    // object
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "object",
          e));

      a << i.object ();
    }
  }

  static
  const ::xsd::cxx::tree::type_serializer_initializer< 0, char, Change >
  _xsd_Change_type_serializer_init (
    "change",
    "artofsequence.org/aosl/1.0");
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

