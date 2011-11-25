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

#include "aosl/properties_interactive_object.hpp"

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
  // Properties_interactive_object
  //

  Properties_interactive_object::
  Properties_interactive_object ()
  : ::xml_schema::Type (),
    script_ (::xml_schema::Flags (), this)
  {
  }

  Properties_interactive_object::
  Properties_interactive_object (const Properties_interactive_object& x,
                                 ::xml_schema::Flags f,
                                 ::xml_schema::Container* c)
  : ::xml_schema::Type (x, f, c),
    script_ (x.script_, f, this)
  {
  }

  Properties_interactive_object::
  Properties_interactive_object (const ::xercesc::DOMElement& e,
                                 ::xml_schema::Flags f,
                                 ::xml_schema::Container* c)
  : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
    script_ (f, this)
  {
    if ((f & ::xml_schema::Flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false);
      this->parse (p, f);
    }
  }

  void Properties_interactive_object::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::Flags f)
  {
    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

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

      break;
    }
  }

  Properties_interactive_object* Properties_interactive_object::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Properties_interactive_object (*this, f, c);
  }

  Properties_interactive_object::
  ~Properties_interactive_object ()
  {
  }

  bool
  operator== (const Properties_interactive_object& x, const Properties_interactive_object& y)
  {
    if (!(x.script () == y.script ()))
      return false;

    return true;
  }

  bool
  operator!= (const Properties_interactive_object& x, const Properties_interactive_object& y)
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
  operator<< (::std::ostream& o, const Properties_interactive_object& i)
  {
    if (i.script ())
    {
      o << ::std::endl << "script: " << *i.script ();
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
  operator<< (::xercesc::DOMElement& e, const Properties_interactive_object& i)
  {
    e << static_cast< const ::xml_schema::Type& > (i);

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
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.
