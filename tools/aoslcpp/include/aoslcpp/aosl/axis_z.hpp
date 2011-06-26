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
 * @brief Generated from axis_z.xsd.
 */

#ifndef AOSLCPP_AOSL__AXIS_Z_HPP
#define AOSLCPP_AOSL__AXIS_Z_HPP

// Begin prologue.
//

#include <aoslcpp/common.h>

//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 3030000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#include "aoslcpp/aosl/axis_z_forward.hpp"

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

#include "aoslcpp/aosl/axis_origin_z_forward.hpp"

#include "aoslcpp/aosl/axis_positive_z_forward.hpp"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "aoslcpp/aosl/axis_origin_z_forward.hpp"

#include "aoslcpp/aosl/axis_positive_z_forward.hpp"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %http://artofsequence.org/aosl/1.x
 * schema namespace.
 */
namespace aosl
{
  /**
   * @brief Class corresponding to the %axis_z schema type.
   *
   * Configuration of the depth z-axis.
   *
   * @nosubgrouping
   */
  class AOSLCPP_API Axis_z: public ::xml_schema::Type
  {
    public:
    /**
     * @name origin
     *
     * @brief Accessor and modifier functions for the %origin
     * optional attribute with a default value.
     *
     * Position of the origin of the z-axis in the display.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::aosl::Axis_origin_z OriginType;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< OriginType, char > OriginTraits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const OriginType&
    origin () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    OriginType&
    origin ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    origin (const OriginType& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    origin (::std::auto_ptr< OriginType > p);

    /**
     * @brief Detach the attribute value from the object model.
     *
     * @return A pointer to the attribute value.
     *
     * Note that this function leaves the required attribute in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< OriginType >
    detach_origin ();

    /**
     * @brief Return the default value for the attribute.
     *
     * @return A read-only (constant) reference to the attribute's
     * default value.
     */
    static const OriginType&
    origin_default_value ();

    //@}

    /**
     * @name positive
     *
     * @brief Accessor and modifier functions for the %positive
     * optional attribute with a default value.
     *
     * Side of the display where the z values are positive, relative to the
     * z-axis origin.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::aosl::Axis_positive_z PositiveType;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< PositiveType, char > PositiveTraits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const PositiveType&
    positive () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    PositiveType&
    positive ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    positive (const PositiveType& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    positive (::std::auto_ptr< PositiveType > p);

    /**
     * @brief Detach the attribute value from the object model.
     *
     * @return A pointer to the attribute value.
     *
     * Note that this function leaves the required attribute in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< PositiveType >
    detach_positive ();

    /**
     * @brief Return the default value for the attribute.
     *
     * @return A read-only (constant) reference to the attribute's
     * default value.
     */
    static const PositiveType&
    positive_default_value ();

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    Axis_z ();

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Axis_z (const ::xercesc::DOMElement& e,
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
    Axis_z (const Axis_z& x,
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
    virtual Axis_z*
    _clone (::xml_schema::Flags f = 0,
            ::xml_schema::Container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~Axis_z ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::Flags);

    protected:
    ::xsd::cxx::tree::one< OriginType > origin_;
    static const OriginType origin_default_value_;
    ::xsd::cxx::tree::one< PositiveType > positive_;
    static const PositiveType positive_default_value_;

    //@endcond
  };

  AOSLCPP_API
  bool
  operator== (const Axis_z&, const Axis_z&);

  AOSLCPP_API
  bool
  operator!= (const Axis_z&, const Axis_z&);
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "aoslcpp/aosl/axis_origin_z.hpp"
#include "aoslcpp/aosl/axis_origin_z.inl"

#include "aoslcpp/aosl/axis_positive_z.hpp"
#include "aoslcpp/aosl/axis_positive_z.inl"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

namespace aosl
{
  AOSLCPP_API
  ::std::ostream&
  operator<< (::std::ostream&, const Axis_z&);
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
  AOSLCPP_API
  void
  operator<< (::xercesc::DOMElement&, const Axis_z&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "aoslcpp/aosl/axis_z.inl"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__AXIS_Z_HPP
