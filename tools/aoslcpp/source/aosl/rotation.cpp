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

#include "aoslcpp/aosl/rotation.hpp"

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
  // Rotation
  //

  Rotation::
  Rotation ()
  : ::xml_schema::Type (),
    yaw_ (yaw_default_value (), ::xml_schema::Flags (), this),
    pitch_ (pitch_default_value (), ::xml_schema::Flags (), this),
    roll_ (roll_default_value (), ::xml_schema::Flags (), this)
  {
  }

  Rotation::
  Rotation (const Rotation& x,
            ::xml_schema::Flags f,
            ::xml_schema::Container* c)
  : ::xml_schema::Type (x, f, c),
    yaw_ (x.yaw_, f, this),
    pitch_ (x.pitch_, f, this),
    roll_ (x.roll_, f, this)
  {
  }

  Rotation::
  Rotation (const ::xercesc::DOMElement& e,
            ::xml_schema::Flags f,
            ::xml_schema::Container* c)
  : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
    yaw_ (f, this),
    pitch_ (f, this),
    roll_ (f, this)
  {
    if ((f & ::xml_schema::Flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, false, true);
      this->parse (p, f);
    }
  }

  void Rotation::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::Flags f)
  {
    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      if (n.name () == "yaw" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< YawType > r (
          YawTraits::create (i, f, this));

        this->yaw_.set (r);
        continue;
      }

      if (n.name () == "pitch" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< PitchType > r (
          PitchTraits::create (i, f, this));

        this->pitch_.set (r);
        continue;
      }

      if (n.name () == "roll" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< RollType > r (
          RollTraits::create (i, f, this));

        this->roll_.set (r);
        continue;
      }
    }

    if (!yaw_.present ())
    {
      this->yaw_.set (yaw_default_value ());
    }

    if (!pitch_.present ())
    {
      this->pitch_.set (pitch_default_value ());
    }

    if (!roll_.present ())
    {
      this->roll_.set (roll_default_value ());
    }
  }

  Rotation* Rotation::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Rotation (*this, f, c);
  }

  Rotation::
  ~Rotation ()
  {
  }

  bool
  operator== (const Rotation& x, const Rotation& y)
  {
    if (!(x.yaw () == y.yaw ()))
      return false;

    if (!(x.pitch () == y.pitch ()))
      return false;

    if (!(x.roll () == y.roll ()))
      return false;

    return true;
  }

  bool
  operator!= (const Rotation& x, const Rotation& y)
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
  operator<< (::std::ostream& o, const Rotation& i)
  {
    o << ::std::endl << "yaw: " << i.yaw ();
    o << ::std::endl << "pitch: " << i.pitch ();
    o << ::std::endl << "roll: " << i.roll ();
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
  operator<< (::xercesc::DOMElement& e, const Rotation& i)
  {
    e << static_cast< const ::xml_schema::Type& > (i);

    // yaw
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "yaw",
          e));

      a << i.yaw ();
    }

    // pitch
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "pitch",
          e));

      a << i.pitch ();
    }

    // roll
    //
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "roll",
          e));

      a << i.roll ();
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

