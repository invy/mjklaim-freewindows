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

#include "aosl/controller.hpp"

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
  // Controller
  //

  Controller::
  Controller (const ::xercesc::DOMElement& e,
              ::xml_schema::Flags f,
              ::xml_schema::Container* c)
  : ::xml_schema::String (e, f, c)
  {
    _xsd_Controller_convert ();
  }

  Controller::
  Controller (const ::xercesc::DOMAttr& a,
              ::xml_schema::Flags f,
              ::xml_schema::Container* c)
  : ::xml_schema::String (a, f, c)
  {
    _xsd_Controller_convert ();
  }

  Controller::
  Controller (const ::std::string& s,
              const ::xercesc::DOMElement* e,
              ::xml_schema::Flags f,
              ::xml_schema::Container* c)
  : ::xml_schema::String (s, e, f, c)
  {
    _xsd_Controller_convert ();
  }

  Controller* Controller::
  _clone (::xml_schema::Flags f,
          ::xml_schema::Container* c) const
  {
    return new class Controller (*this, f, c);
  }

  Controller::Value Controller::
  _xsd_Controller_convert () const
  {
    ::xsd::cxx::tree::enum_comparator< char > c (_xsd_Controller_literals_);
    const Value* i (::std::lower_bound (
                      _xsd_Controller_indexes_,
                      _xsd_Controller_indexes_ + 2,
                      *this,
                      c));

    if (i == _xsd_Controller_indexes_ + 2 || _xsd_Controller_literals_[*i] != *this)
    {
      throw ::xsd::cxx::tree::unexpected_enumerator < char > (*this);
    }

    return *i;
  }

  const char* const Controller::
  _xsd_Controller_literals_[2] =
  {
    "user",
    "none"
  };

  const Controller::Value Controller::
  _xsd_Controller_indexes_[2] =
  {
    ::aosl::Controller::none,
    ::aosl::Controller::user
  };
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
  operator<< (::std::ostream& o, Controller::Value i)
  {
    return o << Controller::_xsd_Controller_literals_[i];
  }

  ::std::ostream&
  operator<< (::std::ostream& o, const Controller& i)
  {
    return o << static_cast< const ::xml_schema::String& > (i);
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
  operator<< (::xercesc::DOMElement& e, const Controller& i)
  {
    e << static_cast< const ::xml_schema::String& > (i);
  }

  void
  operator<< (::xercesc::DOMAttr& a, const Controller& i)
  {
    a << static_cast< const ::xml_schema::String& > (i);
  }

  void
  operator<< (::xml_schema::ListStream& l,
              const Controller& i)
  {
    l << static_cast< const ::xml_schema::String& > (i);
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

