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

#include "aosl/list_resource.hpp"

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
  // List_resource
  //

  List_resource::
  List_resource ()
  : ::xml_schema::Type (),
    resource_ (::xml_schema::Flags (), this)
  {
  }

  List_resource::
  List_resource (const List_resource& x,
                 ::xml_schema::Flags f,
                 ::xml_schema::Container* c)
  : ::xml_schema::Type (x, f, c),
    resource_ (x.resource_, f, this)
  {
  }

  List_resource::
  List_resource (const ::xercesc::DOMElement& e,
                 ::xml_schema::Flags f,
                 ::xml_schema::Container* c)
  : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
    resource_ (f, this)
  {
    if ((f & ::xml_schema::Flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false);
      this->parse (p, f);
    }
  }

  void List_resource::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::Flags f)
  {
    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // resource
      //
      if (n.name () == "resource" && n.namespace_ () == "artofsequence.org/aosl/1.0")
      {
        ::std::auto_ptr< ResourceType > r (
          ResourceTraits::create (i, f, this));

        this->resource_.push_back (r);
        continue;
      }

      break;
    }
  }

  List_resource* List_resource::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class List_resource (*this, f, c);
  }

  List_resource::
  ~List_resource ()
  {
  }

  bool
  operator== (const List_resource& x, const List_resource& y)
  {
    if (!(x.resource () == y.resource ()))
      return false;

    return true;
  }

  bool
  operator!= (const List_resource& x, const List_resource& y)
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
  operator<< (::std::ostream& o, const List_resource& i)
  {
    for (List_resource::ResourceConstIterator
         b (i.resource ().begin ()), e (i.resource ().end ());
         b != e; ++b)
    {
      o << ::std::endl << "resource: " << *b;
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
  operator<< (::xercesc::DOMElement& e, const List_resource& i)
  {
    e << static_cast< const ::xml_schema::Type& > (i);

    // resource
    //
    for (List_resource::ResourceConstIterator
         b (i.resource ().begin ()), n (i.resource ().end ());
         b != n; ++b)
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "resource",
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

