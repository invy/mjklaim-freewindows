// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

/**
 * @file
 * @brief Generated from axis_origin_y.xsd.
 */

#ifndef AOSLCPP_AOSL__AXIS_ORIGIN_Y_HPP
#define AOSLCPP_AOSL__AXIS_ORIGIN_Y_HPP

// Begin prologue.
//

#include <aoslcpp/common.hpp>

//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 3030000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#include "aoslcpp/aosl/axis_origin_y_forward.hpp"

#include <memory>    // std::auto_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

#include <xsd/cxx/tree/containers-wildcard.hxx>

#ifndef XSD_DONT_INCLUDE_INLINE
#define XSD_DONT_INCLUDE_INLINE

#undef XSD_DONT_INCLUDE_INLINE
#else

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %artofsequence.org/aosl/1.0
 * schema namespace.
 */
namespace aosl
{
  /**
   * @brief Enumeration class corresponding to the %axis_origin_y
   * schema type.
   *
   * Position of the vertical y-axis origin in graphic space.
   */
  class Axis_origin_y: public ::xml_schema::String
  {
    public:

    /**
     * @brief Underlying enum type.
     */
    enum Value
    {
      /**
       * The origin of the y-axis is the top border of the display.
       */
      top,
      /**
       * The origin of the y-axis is the bottom border of the display.
       */
      bottom,
      /**
       * The origin of the y-axis is on the vertical center of the display.
       */
      center
    };

    /**
     * @brief Default constructor.
     *
     * Note that this constructor may leave the instance in an
     * invalid state.
     */
    Axis_origin_y ();

    /**
     * @brief Create an instance from the underlying enum value.
     *
     * @param v A enum value.
     */
    Axis_origin_y (Value v);

    /**
     * @brief Create an instance from a C string.
     *
     * @param v A string value.
     */
    Axis_origin_y (const char* v);

    /**
     * @brief Create an instance from a string.
     *
     * @param v A string value.
     */
    Axis_origin_y (const ::std::string& v);

    /**
     * @brief Create an instance from the base value.
     *
     * @param v A base value.
     */
    Axis_origin_y (const ::xml_schema::String& v);

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Axis_origin_y (const ::xercesc::DOMElement& e,
                   ::xml_schema::Flags f = 0,
                   ::xml_schema::Container* c = 0);

    /**
     * @brief Create an instance from a DOM attribute.
     *
     * @param a A DOM attribute to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Axis_origin_y (const ::xercesc::DOMAttr& a,
                   ::xml_schema::Flags f = 0,
                   ::xml_schema::Container* c = 0);

    /**
     * @brief Create an instance from a string fragment.
     *
     * @param s A string fragment to extract the data from.
     * @param e A pointer to DOM element containing the string fragment.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Axis_origin_y (const ::std::string& s,
                   const ::xercesc::DOMElement* e,
                   ::xml_schema::Flags f = 0,
                   ::xml_schema::Container* c = 0);

    /**
     * @brief Copy constructor.
     *
     * @param x An instance to make a copy of.
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    Axis_origin_y (const Axis_origin_y& x,
                   ::xml_schema::Flags f = 0,
                   ::xml_schema::Container* c = 0);

    /**
     * @brief Copy the instance polymorphically.
     *
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     * @return A pointer to the dynamically allocated copy.
     *
     * This function ensures that the dynamic type of the instance is
     * used for copying and should be used for polymorphic object
     * models instead of the copy constructor.
     */
    virtual Axis_origin_y*
    _clone (::xml_schema::Flags f = 0,
            ::xml_schema::Container* c = 0) const;

    /**
     * @brief Assign the underlying enum value.
     *
     * @param v A enum value.
     * @return A refernce to the instance.
     */
    Axis_origin_y&
    operator= (Value v);

    /**
     * @brief Implicit conversion operator to the underlying
     * enum value.
     *
     * @return A enum value.
     */
    virtual
    operator Value () const
    {
      return _xsd_Axis_origin_y_convert ();
    }

    //@cond

    protected:
    Value
    _xsd_Axis_origin_y_convert () const;

    public:
    static const char* const _xsd_Axis_origin_y_literals_[3];
    static const Value _xsd_Axis_origin_y_indexes_[3];

    //@endcond
  };
}

#ifndef XSD_DONT_INCLUDE_INLINE

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

namespace aosl
{
  ::std::ostream&
  operator<< (::std::ostream&, Axis_origin_y::Value);

  ::std::ostream&
  operator<< (::std::ostream&, const Axis_origin_y&);
}

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace aosl
{
}

#include <iosfwd>

#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/framework/XMLFormatter.hpp>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

namespace aosl
{
  void
  operator<< (::xercesc::DOMElement&, const Axis_origin_y&);

  void
  operator<< (::xercesc::DOMAttr&, const Axis_origin_y&);

  void
  operator<< (::xml_schema::ListStream&,
              const Axis_origin_y&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "aoslcpp/aosl/axis_origin_y.inl"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__AXIS_ORIGIN_Y_HPP
