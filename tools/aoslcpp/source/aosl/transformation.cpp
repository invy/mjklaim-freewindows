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

#include "aosl/transformation.hpp"

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
  // Transformation
  //

  const Transformation::ReferentialType Transformation::referential_default_value_ (
    "relative");

  Transformation::
  Transformation ()
  : ::xml_schema::Type (),
    translation_ (::xml_schema::Flags (), this),
    scale_ (::xml_schema::Flags (), this),
    rotation_ (::xml_schema::Flags (), this),
    center_ (::xml_schema::Flags (), this),
    referential_ (referential_default_value (), ::xml_schema::Flags (), this)
  {
  }

  Transformation::
  Transformation (const Transformation& x,
                  ::xml_schema::Flags f,
                  ::xml_schema::Container* c)
  : ::xml_schema::Type (x, f, c),
    translation_ (x.translation_, f, this),
    scale_ (x.scale_, f, this),
    rotation_ (x.rotation_, f, this),
    center_ (x.center_, f, this),
    referential_ (x.referential_, f, this)
  {
  }

  Transformation::
  Transformation (const ::xercesc::DOMElement& e,
                  ::xml_schema::Flags f,
                  ::xml_schema::Container* c)
  : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
    translation_ (f, this),
    scale_ (f, this),
    rotation_ (f, this),
    center_ (f, this),
    referential_ (f, this)
  {
    if ((f & ::xml_schema::Flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, true);
      this->parse (p, f);
    }
  }

  void Transformation::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::Flags f)
  {
    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // translation
      //
      if (n.name () == "translation" && n.namespace_ () == "artofsequence.org/aosl/1.0")
      {
        ::std::auto_ptr< TranslationType > r (
          TranslationTraits::create (i, f, this));

        if (!this->translation_)
        {
          this->translation_.set (r);
          continue;
        }
      }

      // scale
      //
      if (n.name () == "scale" && n.namespace_ () == "artofsequence.org/aosl/1.0")
      {
        ::std::auto_ptr< ScaleType > r (
          ScaleTraits::create (i, f, this));

        if (!this->scale_)
        {
          this->scale_.set (r);
          continue;
        }
      }

      // rotation
      //
      if (n.name () == "rotation" && n.namespace_ () == "artofsequence.org/aosl/1.0")
      {
        ::std::auto_ptr< RotationType > r (
          RotationTraits::create (i, f, this));

        if (!this->rotation_)
        {
          this->rotation_.set (r);
          continue;
        }
      }

      // center
      //
      if (n.name () == "center" && n.namespace_ () == "artofsequence.org/aosl/1.0")
      {
        ::std::auto_ptr< CenterType > r (
          CenterTraits::create (i, f, this));

        if (!this->center_)
        {
          this->center_.set (r);
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

      if (n.name () == "referential" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< ReferentialType > r (
          ReferentialTraits::create (i, f, this));

        this->referential_.set (r);
        continue;
      }
    }

    if (!referential_.present ())
    {
      this->referential_.set (referential_default_value ());
    }
  }

  Transformation* Transformation::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Transformation (*this, f, c);
  }

  Transformation::
  ~Transformation ()
  {
  }

  bool
  operator== (const Transformation& x, const Transformation& y)
  {
    if (!(x.translation () == y.translation ()))
      return false;

    if (!(x.scale () == y.scale ()))
      return false;

    if (!(x.rotation () == y.rotation ()))
      return false;

    if (!(x.center () == y.center ()))
      return false;

    if (!(x.referential () == y.referential ()))
      return false;

    return true;
  }

  bool
  operator!= (const Transformation& x, const Transformation& y)
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
  operator<< (::std::ostream& o, const Transformation& i)
  {
    if (i.translation ())
    {
      o << ::std::endl << "translation: " << *i.translation ();
    }

    if (i.scale ())
    {
      o << ::std::endl << "scale: " << *i.scale ();
    }

    if (i.rotation ())
    {
      o << ::std::endl << "rotation: " << *i.rotation ();
    }

    if (i.center ())
    {
      o << ::std::endl << "center: " << *i.center ();
    }

    o << ::std::endl << "referential: " << i.referential ();
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
  operator<< (::xercesc::DOMElement& e, const Transformation& i)
  {
    e << static_cast< const ::xml_schema::Type& > (i);

    // translation
    //
    if (i.translation ())
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "translation",
          "artofsequence.org/aosl/1.0",
          e));

      s << *i.translation ();
    }

    // scale
    //
    if (i.scale ())
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "scale",
          "artofsequence.org/aosl/1.0",
          e));

      s << *i.scale ();
    }

    // rotation
    //
    if (i.rotation ())
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "rotation",
          "artofsequence.org/aosl/1.0",
          e));

      s << *i.rotation ();
    }

    // center
    //
    if (i.center ())
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "center",
          "artofsequence.org/aosl/1.0",
          e));

      s << *i.center ();
    }

    // referential
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "referential",
          e));

      a << i.referential ();
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

