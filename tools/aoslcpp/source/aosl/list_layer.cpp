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

#include "aosl/list_layer.hpp"

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
  // List_layer
  //

  List_layer::
  List_layer ()
  : ::xml_schema::Type (),
    layer_ (::xml_schema::Flags (), this)
  {
  }

  List_layer::
  List_layer (const List_layer& x,
              ::xml_schema::Flags f,
              ::xml_schema::Container* c)
  : ::xml_schema::Type (x, f, c),
    layer_ (x.layer_, f, this)
  {
  }

  List_layer::
  List_layer (const ::xercesc::DOMElement& e,
              ::xml_schema::Flags f,
              ::xml_schema::Container* c)
  : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
    layer_ (f, this)
  {
    if ((f & ::xml_schema::Flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false);
      this->parse (p, f);
    }
  }

  void List_layer::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::Flags f)
  {
    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // layer
      //
      if (n.name () == "layer" && n.namespace_ () == "artofsequence.org/aosl/1.0")
      {
        ::std::auto_ptr< LayerType > r (
          LayerTraits::create (i, f, this));

        this->layer_.push_back (r);
        continue;
      }

      break;
    }
  }

  List_layer* List_layer::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class List_layer (*this, f, c);
  }

  List_layer::
  ~List_layer ()
  {
  }

  bool
  operator== (const List_layer& x, const List_layer& y)
  {
    if (!(x.layer () == y.layer ()))
      return false;

    return true;
  }

  bool
  operator!= (const List_layer& x, const List_layer& y)
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
  operator<< (::std::ostream& o, const List_layer& i)
  {
    for (List_layer::LayerConstIterator
         b (i.layer ().begin ()), e (i.layer ().end ());
         b != e; ++b)
    {
      o << ::std::endl << "layer: " << *b;
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
  operator<< (::xercesc::DOMElement& e, const List_layer& i)
  {
    e << static_cast< const ::xml_schema::Type& > (i);

    // layer
    //
    for (List_layer::LayerConstIterator
         b (i.layer ().begin ()), n (i.layer ().end ());
         b != n; ++b)
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "layer",
          "artofsequence.org/aosl/1.0",
          e));

      s << *b;
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.
