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
 * @brief Generated from vector.xsd.
 */

#ifndef AOSLCPP_AOSL__VECTOR_HPP
#define AOSLCPP_AOSL__VECTOR_HPP

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

#include "aoslcpp/aosl/vector_forward.hpp"

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

#include "aoslcpp/aosl/unit_space_forward.hpp"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "aoslcpp/aosl/unit_space_forward.hpp"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %artofsequence.org/aosl/1.0
 * schema namespace.
 */
namespace aosl
{
  /**
   * @brief Class corresponding to the %vector schema type.
   *
   * Vector of space units used for spatial representations.
   *
   * @nosubgrouping
   */
  class Vector: public ::xml_schema::Type
  {
    public:
    /**
     * @name x
     *
     * @brief Accessor and modifier functions for the %x
     * optional attribute with a default value.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::aosl::Unit_space XType;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< XType, char > XTraits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const XType&
    x () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    XType&
    x ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    x (const XType& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    x (::std::auto_ptr< XType > p);

    /**
     * @brief Detach the attribute value from the object model.
     *
     * @return A pointer to the attribute value.
     *
     * Note that this function leaves the required attribute in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< XType >
    detach_x ();

    /**
     * @brief Return the default value for the attribute.
     *
     * @return The attribute's default value.
     */
    static XType
    x_default_value ();

    //@}

    /**
     * @name y
     *
     * @brief Accessor and modifier functions for the %y
     * optional attribute with a default value.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::aosl::Unit_space YType;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< YType, char > YTraits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const YType&
    y () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    YType&
    y ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    y (const YType& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    y (::std::auto_ptr< YType > p);

    /**
     * @brief Detach the attribute value from the object model.
     *
     * @return A pointer to the attribute value.
     *
     * Note that this function leaves the required attribute in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< YType >
    detach_y ();

    /**
     * @brief Return the default value for the attribute.
     *
     * @return The attribute's default value.
     */
    static YType
    y_default_value ();

    //@}

    /**
     * @name z
     *
     * @brief Accessor and modifier functions for the %z
     * optional attribute with a default value.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::aosl::Unit_space ZType;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< ZType, char > ZTraits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const ZType&
    z () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    ZType&
    z ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    z (const ZType& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    z (::std::auto_ptr< ZType > p);

    /**
     * @brief Detach the attribute value from the object model.
     *
     * @return A pointer to the attribute value.
     *
     * Note that this function leaves the required attribute in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< ZType >
    detach_z ();

    /**
     * @brief Return the default value for the attribute.
     *
     * @return The attribute's default value.
     */
    static ZType
    z_default_value ();

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    Vector ();

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Vector (const ::xercesc::DOMElement& e,
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
    Vector (const Vector& x,
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
    virtual Vector*
    _clone (::xml_schema::Flags f = 0,
            ::xml_schema::Container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~Vector ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::Flags);

    protected:
    ::xsd::cxx::tree::one< XType > x_;
    ::xsd::cxx::tree::one< YType > y_;
    ::xsd::cxx::tree::one< ZType > z_;

    //@endcond
  };

  bool
  operator== (const Vector&, const Vector&);

  bool
  operator!= (const Vector&, const Vector&);
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "aoslcpp/aosl/unit_space.hpp"
#include "aoslcpp/aosl/unit_space.inl"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

namespace aosl
{
  ::std::ostream&
  operator<< (::std::ostream&, const Vector&);
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
  operator<< (::xercesc::DOMElement&, const Vector&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "aoslcpp/aosl/vector.inl"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__VECTOR_HPP
