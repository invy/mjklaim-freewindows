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

#include "aoslcpp/aosl/script.hpp"

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
  // Script
  //

  const Script::ActivationType Script::activation_default_value_ (
    "reset");

  Script::
  Script (const LangType& lang)
  : ::xml_schema::Type (),
    lang_ (lang, ::xml_schema::Flags (), this),
    activation_ (activation_default_value (), ::xml_schema::Flags (), this),
    loop_ (loop_default_value (), ::xml_schema::Flags (), this),
    interval_ (interval_default_value (), ::xml_schema::Flags (), this),
    source_ (::xml_schema::Flags (), this)
  {
  }

  Script::
  Script (const Script& x,
          ::xml_schema::Flags f,
          ::xml_schema::Container* c)
  : ::xml_schema::Type (x, f, c),
    lang_ (x.lang_, f, this),
    activation_ (x.activation_, f, this),
    loop_ (x.loop_, f, this),
    interval_ (x.interval_, f, this),
    source_ (x.source_, f, this)
  {
  }

  Script::
  Script (const ::xercesc::DOMElement& e,
          ::xml_schema::Flags f,
          ::xml_schema::Container* c)
  : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
    lang_ (f, this),
    activation_ (f, this),
    loop_ (f, this),
    interval_ (f, this),
    source_ (f, this)
  {
    if ((f & ::xml_schema::Flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, false, true);
      this->parse (p, f);
    }
  }

  void Script::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::Flags f)
  {
    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      if (n.name () == "lang" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< LangType > r (
          LangTraits::create (i, f, this));

        this->lang_.set (r);
        continue;
      }

      if (n.name () == "activation" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< ActivationType > r (
          ActivationTraits::create (i, f, this));

        this->activation_.set (r);
        continue;
      }

      if (n.name () == "loop" && n.namespace_ ().empty ())
      {
        this->loop_.set (LoopTraits::create (i, f, this));
        continue;
      }

      if (n.name () == "interval" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< IntervalType > r (
          IntervalTraits::create (i, f, this));

        this->interval_.set (r);
        continue;
      }

      if (n.name () == "source" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< SourceType > r (
          SourceTraits::create (i, f, this));

        this->source_.set (r);
        continue;
      }
    }

    if (!lang_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< char > (
        "lang",
        "");
    }

    if (!activation_.present ())
    {
      this->activation_.set (activation_default_value ());
    }

    if (!loop_.present ())
    {
      this->loop_.set (loop_default_value ());
    }

    if (!interval_.present ())
    {
      this->interval_.set (interval_default_value ());
    }
  }

  Script* Script::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Script (*this, f, c);
  }

  Script::
  ~Script ()
  {
  }

  bool
  operator== (const Script& x, const Script& y)
  {
    if (!(x.lang () == y.lang ()))
      return false;

    if (!(x.activation () == y.activation ()))
      return false;

    if (!(x.loop () == y.loop ()))
      return false;

    if (!(x.interval () == y.interval ()))
      return false;

    if (!(x.source () == y.source ()))
      return false;

    return true;
  }

  bool
  operator!= (const Script& x, const Script& y)
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
  operator<< (::std::ostream& o, const Script& i)
  {
    o << ::std::endl << "lang: " << i.lang ();
    o << ::std::endl << "activation: " << i.activation ();
    o << ::std::endl << "loop: " << i.loop ();
    o << ::std::endl << "interval: " << i.interval ();
    if (i.source ())
    {
      o << ::std::endl << "source: " << *i.source ();
    }

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
  operator<< (::xercesc::DOMElement& e, const Script& i)
  {
    e << static_cast< const ::xml_schema::Type& > (i);

    // lang
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "lang",
          e));

      a << i.lang ();
    }

    // activation
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "activation",
          e));

      a << i.activation ();
    }

    // loop
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "loop",
          e));

      a << i.loop ();
    }

    // interval
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "interval",
          e));

      a << i.interval ();
    }

    // source
    //
    if (i.source ())
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "source",
          e));

      a << *i.source ();
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

