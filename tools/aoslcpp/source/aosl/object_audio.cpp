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

#include "aoslcpp/aosl/object_audio.hpp"

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
  // Object_audio
  //

  Object_audio::
  Object_audio ()
  : ::aosl::Object (),
    stream_ (::xml_schema::Flags (), this)
  {
  }

  Object_audio::
  Object_audio (const IdType& id,
                const StreamType& stream)
  : ::aosl::Object (id),
    stream_ (stream, ::xml_schema::Flags (), this)
  {
  }

  Object_audio::
  Object_audio (const IdType& id,
                ::std::auto_ptr< StreamType >& stream)
  : ::aosl::Object (id),
    stream_ (stream, ::xml_schema::Flags (), this)
  {
  }

  Object_audio::
  Object_audio (const Object_audio& x,
                ::xml_schema::Flags f,
                ::xml_schema::Container* c)
  : ::aosl::Object (x, f, c),
    stream_ (x.stream_, f, this)
  {
  }

  Object_audio::
  Object_audio (const ::xercesc::DOMElement& e,
                ::xml_schema::Flags f,
                ::xml_schema::Container* c)
  : ::aosl::Object (e, f | ::xml_schema::Flags::base, c),
    stream_ (f, this)
  {
    if ((f & ::xml_schema::Flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, true);
      this->parse (p, f);
    }
  }

  void Object_audio::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::Flags f)
  {
    this->::aosl::Object::parse (p, f);

    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

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

    if (!stream_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "stream",
        "http://artofsequence.org/aosl/1.x");
    }
  }

  Object_audio* Object_audio::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Object_audio (*this, f, c);
  }

  Object_audio::
  ~Object_audio ()
  {
  }

  static
  const ::xsd::cxx::tree::type_factory_initializer< 0, char, Object_audio >
  _xsd_Object_audio_type_factory_init (
    "object_audio",
    "http://artofsequence.org/aosl/1.x");

  static
  const ::xsd::cxx::tree::comparison_initializer< 0, char, Object_audio >
  _xsd_Object_audio_comparison_init;

  bool
  operator== (const Object_audio& x, const Object_audio& y)
  {
    if (!(static_cast< const ::aosl::Object& > (x) ==
          static_cast< const ::aosl::Object& > (y)))
      return false;

    if (!(x.stream () == y.stream ()))
      return false;

    return true;
  }

  bool
  operator!= (const Object_audio& x, const Object_audio& y)
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
  operator<< (::std::ostream& o, const Object_audio& i)
  {
    o << static_cast< const ::aosl::Object& > (i);

    o << ::std::endl << "stream: " << i.stream ();
    return o;
  }

  static
  const ::xsd::cxx::tree::std_ostream_initializer< 0, char, Object_audio >
  _xsd_Object_audio_std_ostream_init;
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
  operator<< (::xercesc::DOMElement& e, const Object_audio& i)
  {
    e << static_cast< const ::aosl::Object& > (i);

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
  const ::xsd::cxx::tree::type_serializer_initializer< 0, char, Object_audio >
  _xsd_Object_audio_type_serializer_init (
    "object_audio",
    "http://artofsequence.org/aosl/1.x");
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

