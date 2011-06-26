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

#include "aoslcpp/aosl/properties_graphic_object.hpp"

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
  // Properties_graphic_object
  //

  Properties_graphic_object::
  Properties_graphic_object ()
  : ::xml_schema::Type (),
    output_ (::xml_schema::Flags (), this),
    input_ (::xml_schema::Flags (), this)
  {
  }

  Properties_graphic_object::
  Properties_graphic_object (const Properties_graphic_object& x,
                             ::xml_schema::Flags f,
                             ::xml_schema::Container* c)
  : ::xml_schema::Type (x, f, c),
    output_ (x.output_, f, this),
    input_ (x.input_, f, this)
  {
  }

  Properties_graphic_object::
  Properties_graphic_object (const ::xercesc::DOMElement& e,
                             ::xml_schema::Flags f,
                             ::xml_schema::Container* c)
  : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
    output_ (f, this),
    input_ (f, this)
  {
    if ((f & ::xml_schema::Flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false);
      this->parse (p, f);
    }
  }

  void Properties_graphic_object::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::Flags f)
  {
    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // output
      //
      if (n.name () == "output" && n.namespace_ () == "http://artofsequence.org/aosl/1.x")
      {
        ::std::auto_ptr< OutputType > r (
          OutputTraits::create (i, f, this));

        if (!this->output_)
        {
          this->output_.set (r);
          continue;
        }
      }

      // input
      //
      if (n.name () == "input" && n.namespace_ () == "http://artofsequence.org/aosl/1.x")
      {
        ::std::auto_ptr< InputType > r (
          InputTraits::create (i, f, this));

        if (!this->input_)
        {
          this->input_.set (r);
          continue;
        }
      }

      break;
    }
  }

  Properties_graphic_object* Properties_graphic_object::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Properties_graphic_object (*this, f, c);
  }

  Properties_graphic_object::
  ~Properties_graphic_object ()
  {
  }

  bool
  operator== (const Properties_graphic_object& x, const Properties_graphic_object& y)
  {
    if (!(x.output () == y.output ()))
      return false;

    if (!(x.input () == y.input ()))
      return false;

    return true;
  }

  bool
  operator!= (const Properties_graphic_object& x, const Properties_graphic_object& y)
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
  operator<< (::std::ostream& o, const Properties_graphic_object& i)
  {
    if (i.output ())
    {
      o << ::std::endl << "output: " << *i.output ();
    }

    if (i.input ())
    {
      o << ::std::endl << "input: " << *i.input ();
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
  operator<< (::xercesc::DOMElement& e, const Properties_graphic_object& i)
  {
    e << static_cast< const ::xml_schema::Type& > (i);

    // output
    //
    if (i.output ())
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "output",
          "http://artofsequence.org/aosl/1.x",
          e));

      s << *i.output ();
    }

    // input
    //
    if (i.input ())
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "input",
          "http://artofsequence.org/aosl/1.x",
          e));

      s << *i.input ();
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

