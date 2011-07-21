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
 * @brief Generated from coordinate_system.xsd.
 */

#ifndef AOSLCPP_AOSL__COORDINATE_SYSTEM_HPP
#define AOSLCPP_AOSL__COORDINATE_SYSTEM_HPP

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

#include "aoslcpp/aosl/coordinate_system_forward.hpp"

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

#include "aoslcpp/aosl/axis_x_forward.hpp"

#include "aoslcpp/aosl/axis_y_forward.hpp"

#include "aoslcpp/aosl/axis_z_forward.hpp"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "aoslcpp/aosl/axis_x_forward.hpp"

#include "aoslcpp/aosl/axis_y_forward.hpp"

#include "aoslcpp/aosl/axis_z_forward.hpp"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %http://artofsequence.org/aosl/1.x
 * schema namespace.
 */
namespace aosl
{
  /**
   * @brief Class corresponding to the %coordinate_system schema type.
   *
   * Coordinate system configuration for graphic space.
   *
   * @nosubgrouping
   */
  class Coordinate_system: public ::xml_schema::Type
  {
    public:
    /**
     * @name xaxis
     *
     * @brief Accessor and modifier functions for the %xaxis
     * required element.
     *
     * Configuration of the horizontal x-axis.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Axis_x XaxisType;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< XaxisType, char > XaxisTraits;

    /**
     * @brief Return a read-only (constant) reference to the element.
     *
     * @return A constant reference to the element.
     */
    const XaxisType&
    xaxis () const;

    /**
     * @brief Return a read-write reference to the element.
     *
     * @return A reference to the element.
     */
    XaxisType&
    xaxis ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    xaxis (const XaxisType& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    xaxis (::std::auto_ptr< XaxisType > p);

    /**
     * @brief Detach the element value from the object model.
     *
     * @return A pointer to the element value.
     *
     * Note that this function leaves the required element in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< XaxisType >
    detach_xaxis ();

    //@}

    /**
     * @name yaxis
     *
     * @brief Accessor and modifier functions for the %yaxis
     * required element.
     *
     * Configuration of the vertical y-axis.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Axis_y YaxisType;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< YaxisType, char > YaxisTraits;

    /**
     * @brief Return a read-only (constant) reference to the element.
     *
     * @return A constant reference to the element.
     */
    const YaxisType&
    yaxis () const;

    /**
     * @brief Return a read-write reference to the element.
     *
     * @return A reference to the element.
     */
    YaxisType&
    yaxis ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    yaxis (const YaxisType& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    yaxis (::std::auto_ptr< YaxisType > p);

    /**
     * @brief Detach the element value from the object model.
     *
     * @return A pointer to the element value.
     *
     * Note that this function leaves the required element in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< YaxisType >
    detach_yaxis ();

    //@}

    /**
     * @name zaxis
     *
     * @brief Accessor and modifier functions for the %zaxis
     * required element.
     *
     * Configuration of the depth z-axis.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Axis_z ZaxisType;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< ZaxisType, char > ZaxisTraits;

    /**
     * @brief Return a read-only (constant) reference to the element.
     *
     * @return A constant reference to the element.
     */
    const ZaxisType&
    zaxis () const;

    /**
     * @brief Return a read-write reference to the element.
     *
     * @return A reference to the element.
     */
    ZaxisType&
    zaxis ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    zaxis (const ZaxisType& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    zaxis (::std::auto_ptr< ZaxisType > p);

    /**
     * @brief Detach the element value from the object model.
     *
     * @return A pointer to the element value.
     *
     * Note that this function leaves the required element in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< ZaxisType >
    detach_zaxis ();

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Default constructor.
     *
     * Note that this constructor leaves required elements and
     * attributes uninitialized.
     */
    Coordinate_system ();

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    Coordinate_system (const XaxisType&,
                       const YaxisType&,
                       const ZaxisType&);

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes
     * (auto_ptr version).
     *
     * This constructor will try to use the passed values directly
     * instead of making copies.
     */
    Coordinate_system (::std::auto_ptr< XaxisType >&,
                       ::std::auto_ptr< YaxisType >&,
                       ::std::auto_ptr< ZaxisType >&);

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Coordinate_system (const ::xercesc::DOMElement& e,
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
    Coordinate_system (const Coordinate_system& x,
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
    virtual Coordinate_system*
    _clone (::xml_schema::Flags f = 0,
            ::xml_schema::Container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~Coordinate_system ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::Flags);

    protected:
    ::xsd::cxx::tree::one< XaxisType > xaxis_;
    ::xsd::cxx::tree::one< YaxisType > yaxis_;
    ::xsd::cxx::tree::one< ZaxisType > zaxis_;

    //@endcond
  };

  bool
  operator== (const Coordinate_system&, const Coordinate_system&);

  bool
  operator!= (const Coordinate_system&, const Coordinate_system&);
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "aoslcpp/aosl/axis_x.hpp"
#include "aoslcpp/aosl/axis_x.inl"

#include "aoslcpp/aosl/axis_y.hpp"
#include "aoslcpp/aosl/axis_y.inl"

#include "aoslcpp/aosl/axis_z.hpp"
#include "aoslcpp/aosl/axis_z.inl"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

namespace aosl
{
  ::std::ostream&
  operator<< (::std::ostream&, const Coordinate_system&);
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
  operator<< (::xercesc::DOMElement&, const Coordinate_system&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "aoslcpp/aosl/coordinate_system.inl"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__COORDINATE_SYSTEM_HPP
