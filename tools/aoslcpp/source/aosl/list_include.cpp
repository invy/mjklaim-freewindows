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

#include "aoslcpp/aosl/list_include.hpp"

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
  // List_include
  //

  List_include::
  List_include ()
  : ::xml_schema::Type (),
    include_ (::xml_schema::Flags (), this)
  {
  }

  List_include::
  List_include (const List_include& x,
                ::xml_schema::Flags f,
                ::xml_schema::Container* c)
  : ::xml_schema::Type (x, f, c),
    include_ (x.include_, f, this)
  {
  }

  List_include::
  List_include (const ::xercesc::DOMElement& e,
                ::xml_schema::Flags f,
                ::xml_schema::Container* c)
  : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
    include_ (f, this)
  {
    if ((f & ::xml_schema::Flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false);
      this->parse (p, f);
    }
  }

  void List_include::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::Flags f)
  {
    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // include
      //
      if (n.name () == "include" && n.namespace_ () == "http://artofsequence.org/aosl/1.x")
      {
        ::std::auto_ptr< IncludeType > r (
          IncludeTraits::create (i, f, this));

        this->include_.push_back (r);
        continue;
      }

      break;
    }
  }

  List_include* List_include::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class List_include (*this, f, c);
  }

  List_include::
  ~List_include ()
  {
  }

  bool
  operator== (const List_include& x, const List_include& y)
  {
    if (!(x.include () == y.include ()))
      return false;

    return true;
  }

  bool
  operator!= (const List_include& x, const List_include& y)
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
  operator<< (::std::ostream& o, const List_include& i)
  {
    for (List_include::IncludeConstIterator
         b (i.include ().begin ()), e (i.include ().end ());
         b != e; ++b)
    {
      o << ::std::endl << "include: " << *b;
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
  operator<< (::xercesc::DOMElement& e, const List_include& i)
  {
    e << static_cast< const ::xml_schema::Type& > (i);

    // include
    //
    for (List_include::IncludeConstIterator
         b (i.include ().begin ()), n (i.include ().end ());
         b != n; ++b)
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "include",
          "http://artofsequence.org/aosl/1.x",
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

