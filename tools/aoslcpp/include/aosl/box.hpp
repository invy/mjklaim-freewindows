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
 * @brief Generated from box.xsd.
 */

#ifndef AOSLCPP_AOSL__BOX_HPP
#define AOSLCPP_AOSL__BOX_HPP

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

#include "aosl/box_forward.hpp"

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

#include "aosl/vector_forward.hpp"

#include "aosl/rotation_forward.hpp"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "aosl/vector_forward.hpp"

#include "aosl/rotation_forward.hpp"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %artofsequence.org/aosl/1.0
 * schema namespace.
 */
namespace aosl
{
  /**
   * @brief Class corresponding to the %box schema type.
   *
   * Spatial representation of a box.
   *
   * @nosubgrouping
   */
  class Box: public ::xml_schema::Type
  {
    public:
    /**
     * @name position
     *
     * @brief Accessor and modifier functions for the %position
     * required element.
     *
     * Position of the box's origin in global space.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Vector PositionType;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< PositionType, char > PositionTraits;

    /**
     * @brief Return a read-only (constant) reference to the element.
     *
     * @return A constant reference to the element.
     */
    const PositionType&
    position () const;

    /**
     * @brief Return a read-write reference to the element.
     *
     * @return A reference to the element.
     */
    PositionType&
    position ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    position (const PositionType& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    position (::std::auto_ptr< PositionType > p);

    /**
     * @brief Detach the element value from the object model.
     *
     * @return A pointer to the element value.
     *
     * Note that this function leaves the required element in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< PositionType >
    detach_position ();

    //@}

    /**
     * @name size
     *
     * @brief Accessor and modifier functions for the %size
     * required element.
     *
     * Size of the box.
     * Each one of the axes value gives the length of the corresponding edges
     * of the box.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Vector SizeType;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< SizeType, char > SizeTraits;

    /**
     * @brief Return a read-only (constant) reference to the element.
     *
     * @return A constant reference to the element.
     */
    const SizeType&
    size () const;

    /**
     * @brief Return a read-write reference to the element.
     *
     * @return A reference to the element.
     */
    SizeType&
    size ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    size (const SizeType& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    size (::std::auto_ptr< SizeType > p);

    /**
     * @brief Detach the element value from the object model.
     *
     * @return A pointer to the element value.
     *
     * Note that this function leaves the required element in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< SizeType >
    detach_size ();

    //@}

    /**
     * @name center
     *
     * @brief Accessor and modifier functions for the %center
     * required element.
     *
     * Center of the rotation applied to this box, in box space.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Vector CenterType;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< CenterType, char > CenterTraits;

    /**
     * @brief Return a read-only (constant) reference to the element.
     *
     * @return A constant reference to the element.
     */
    const CenterType&
    center () const;

    /**
     * @brief Return a read-write reference to the element.
     *
     * @return A reference to the element.
     */
    CenterType&
    center ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    center (const CenterType& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    center (::std::auto_ptr< CenterType > p);

    /**
     * @brief Detach the element value from the object model.
     *
     * @return A pointer to the element value.
     *
     * Note that this function leaves the required element in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< CenterType >
    detach_center ();

    //@}

    /**
     * @name orientation
     *
     * @brief Accessor and modifier functions for the %orientation
     * required element.
     *
     * Orientation of the box.
     * The rotation is relative to the center of the box, in box space.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Rotation OrientationType;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< OrientationType, char > OrientationTraits;

    /**
     * @brief Return a read-only (constant) reference to the element.
     *
     * @return A constant reference to the element.
     */
    const OrientationType&
    orientation () const;

    /**
     * @brief Return a read-write reference to the element.
     *
     * @return A reference to the element.
     */
    OrientationType&
    orientation ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    orientation (const OrientationType& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    orientation (::std::auto_ptr< OrientationType > p);

    /**
     * @brief Detach the element value from the object model.
     *
     * @return A pointer to the element value.
     *
     * Note that this function leaves the required element in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< OrientationType >
    detach_orientation ();

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    Box (const PositionType&,
         const SizeType&,
         const CenterType&,
         const OrientationType&);

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes
     * (auto_ptr version).
     *
     * This constructor will try to use the passed values directly
     * instead of making copies.
     */
    Box (::std::auto_ptr< PositionType >&,
         ::std::auto_ptr< SizeType >&,
         ::std::auto_ptr< CenterType >&,
         ::std::auto_ptr< OrientationType >&);

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Box (const ::xercesc::DOMElement& e,
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
    Box (const Box& x,
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
    virtual Box*
    _clone (::xml_schema::Flags f = 0,
            ::xml_schema::Container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~Box ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::Flags);

    protected:
    ::xsd::cxx::tree::one< PositionType > position_;
    ::xsd::cxx::tree::one< SizeType > size_;
    ::xsd::cxx::tree::one< CenterType > center_;
    ::xsd::cxx::tree::one< OrientationType > orientation_;

    //@endcond
  };

  bool
  operator== (const Box&, const Box&);

  bool
  operator!= (const Box&, const Box&);
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "aosl/vector.hpp"
#include "aosl/vector.inl"

#include "aosl/rotation.hpp"
#include "aosl/rotation.inl"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

namespace aosl
{
  ::std::ostream&
  operator<< (::std::ostream&, const Box&);
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
  operator<< (::xercesc::DOMElement&, const Box&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "aosl/box.inl"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__BOX_HPP
