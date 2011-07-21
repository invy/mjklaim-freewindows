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

#include "aoslcpp/aosl/object_video.hpp"

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
  // Object_video
  //

  Object_video::
  Object_video ()
  : ::aosl::Object (),
    graphic_ (::xml_schema::Flags (), this),
    stream_ (::xml_schema::Flags (), this)
  {
  }

  Object_video::
  Object_video (const IdType& id,
                const GraphicType& graphic,
                const StreamType& stream)
  : ::aosl::Object (id),
    graphic_ (graphic, ::xml_schema::Flags (), this),
    stream_ (stream, ::xml_schema::Flags (), this)
  {
  }

  Object_video::
  Object_video (const IdType& id,
                ::std::auto_ptr< GraphicType >& graphic,
                ::std::auto_ptr< StreamType >& stream)
  : ::aosl::Object (id),
    graphic_ (graphic, ::xml_schema::Flags (), this),
    stream_ (stream, ::xml_schema::Flags (), this)
  {
  }

  Object_video::
  Object_video (const Object_video& x,
                ::xml_schema::Flags f,
                ::xml_schema::Container* c)
  : ::aosl::Object (x, f, c),
    graphic_ (x.graphic_, f, this),
    stream_ (x.stream_, f, this)
  {
  }

  Object_video::
  Object_video (const ::xercesc::DOMElement& e,
                ::xml_schema::Flags f,
                ::xml_schema::Container* c)
  : ::aosl::Object (e, f | ::xml_schema::Flags::base, c),
    graphic_ (f, this),
    stream_ (f, this)
  {
    if ((f & ::xml_schema::Flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, true);
      this->parse (p, f);
    }
  }

  void Object_video::
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

      // stream
      //
      if (n.name () == "stream" && n.namespace_ () == "http://artofsequence.org/aosl/1.x")
      {
        ::std::auto_ptr< StreamType > r (
          StreamTraits::create (i, f, this));

        if (!stream_.present ())
        {
          this->stream_.set (r);
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

    if (!stream_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "stream",
        "http://artofsequence.org/aosl/1.x");
    }
  }

  Object_video* Object_video::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Object_video (*this, f, c);
  }

  Object_video::
  ~Object_video ()
  {
  }

  static
  const ::xsd::cxx::tree::type_factory_initializer< 0, char, Object_video >
  _xsd_Object_video_type_factory_init (
    "object_video",
    "http://artofsequence.org/aosl/1.x");

  static
  const ::xsd::cxx::tree::comparison_initializer< 0, char, Object_video >
  _xsd_Object_video_comparison_init;

  bool
  operator== (const Object_video& x, const Object_video& y)
  {
    if (!(static_cast< const ::aosl::Object& > (x) ==
          static_cast< const ::aosl::Object& > (y)))
      return false;

    if (!(x.graphic () == y.graphic ()))
      return false;

    if (!(x.stream () == y.stream ()))
      return false;

    return true;
  }

  bool
  operator!= (const Object_video& x, const Object_video& y)
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
  operator<< (::std::ostream& o, const Object_video& i)
  {
    o << static_cast< const ::aosl::Object& > (i);

    o << ::std::endl << "graphic: " << i.graphic ();
    o << ::std::endl << "stream: " << i.stream ();
    return o;
  }

  static
  const ::xsd::cxx::tree::std_ostream_initializer< 0, char, Object_video >
  _xsd_Object_video_std_ostream_init;
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
  operator<< (::xercesc::DOMElement& e, const Object_video& i)
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

    // stream
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "stream",
          "http://artofsequence.org/aosl/1.x",
          e));

      s << i.stream ();
    }
  }

  static
  const ::xsd::cxx::tree::type_serializer_initializer< 0, char, Object_video >
  _xsd_Object_video_type_serializer_init (
    "object_video",
    "http://artofsequence.org/aosl/1.x");
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

