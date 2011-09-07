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

#include "aosl/extension.hpp"

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
  // Extension
  //

  Extension::
  Extension ()
  : ::xml_schema::Type (),
    dom_document_ (::xsd::cxx::xml::dom::create_document< char > ()),
    any_ (this->dom_document ()),
    any_attribute_ (this->dom_document ())
  {
  }

  Extension::
  Extension (const Extension& x,
             ::xml_schema::Flags f,
             ::xml_schema::Container* c)
  : ::xml_schema::Type (x, f, c),
    dom_document_ (::xsd::cxx::xml::dom::create_document< char > ()),
    any_ (x.any_, this->dom_document ()),
    any_attribute_ (x.any_attribute_, this->dom_document ())
  {
  }

  Extension::
  Extension (const ::xercesc::DOMElement& e,
             ::xml_schema::Flags f,
             ::xml_schema::Container* c)
  : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
    dom_document_ (::xsd::cxx::xml::dom::create_document< char > ()),
    any_ (this->dom_document ()),
    any_attribute_ (this->dom_document ())
  {
    if ((f & ::xml_schema::Flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, true);
      this->parse (p, f);
    }
  }

  void Extension::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::Flags)
  {
    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // any
      //
      if (true)
      {
        ::xercesc::DOMElement* r (
          static_cast< ::xercesc::DOMElement* > (
            this->dom_document ().importNode (
              const_cast< ::xercesc::DOMElement* > (&i), true)));
        this->any_ .push_back (r);
        continue;
      }

      break;
    }

    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // any_attribute
      //
      if ((n.namespace_ () != ::xsd::cxx::xml::bits::xmlns_namespace< char > () &&
           n.namespace_ () != ::xsd::cxx::xml::bits::xsi_namespace< char > ()))
      {
        ::xercesc::DOMAttr* r (
          static_cast< ::xercesc::DOMAttr* > (
            this->dom_document ().importNode (
              const_cast< ::xercesc::DOMAttr* > (&i), true)));
        this->any_attribute_ .insert (r);
        continue;
      }
    }
  }

  Extension* Extension::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Extension (*this, f, c);
  }

  Extension::
  ~Extension ()
  {
  }

  bool
  operator== (const Extension& x, const Extension& y)
  {
    if (!(x.any () == y.any ()))
      return false;

    if (!(x.any_attribute () == y.any_attribute ()))
      return false;

    return true;
  }

  bool
  operator!= (const Extension& x, const Extension& y)
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
  operator<< (::std::ostream& o, const Extension&)
  {
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
  operator<< (::xercesc::DOMElement& e, const Extension& i)
  {
    e << static_cast< const ::xml_schema::Type& > (i);

    // any_attribute
    //
    for (Extension::AnyAttributeConstIterator
         b (i.any_attribute ().begin ()), n (i.any_attribute ().end ());
         b != n; ++b)
    {
      ::xercesc::DOMAttr* a (
        static_cast< ::xercesc::DOMAttr* > (
          e.getOwnerDocument ()->importNode (
            const_cast< ::xercesc::DOMAttr* > (&(*b)), true)));

      if (a->getLocalName () == 0)
        e.setAttributeNode (a);
      else
        e.setAttributeNodeNS (a);
    }

    // any
    //
    for (Extension::AnyConstIterator
         b (i.any ().begin ()), n (i.any ().end ());
         b != n; ++b)
    {
      e.appendChild (
        e.getOwnerDocument ()->importNode (
          const_cast< ::xercesc::DOMElement* > (&(*b)), true));
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

