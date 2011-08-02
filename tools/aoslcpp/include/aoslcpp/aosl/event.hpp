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
 * @brief Generated from event.xsd.
 */

#ifndef AOSLCPP_AOSL__EVENT_HPP
#define AOSLCPP_AOSL__EVENT_HPP

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

#include "aoslcpp/aosl/event_forward.hpp"

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

#include "aoslcpp/aosl/move_ref_forward.hpp"

#include "aoslcpp/aosl/event_type_forward.hpp"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "aoslcpp/aosl/move_ref_forward.hpp"

#include "aoslcpp/aosl/event_type_forward.hpp"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %artofsequence.org/aosl/1.0
 * schema namespace.
 */
namespace aosl
{
  /**
   * @brief Class corresponding to the %event schema type.
   *
   * An Event specify a response to inputs from the user or the
   * player/intepreter.
   *
   * @nosubgrouping
   */
  class Event: public ::xml_schema::Type
  {
    public:
    /**
     * @name move
     *
     * @brief Accessor and modifier functions for the %move
     * required attribute.
     *
     * Id of the move to go to if this Event is triggered,
     * or "auto_next" if there is only one next possibility
     * or "auto_previous" to get back in the path followed by the player.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::aosl::Move_ref MoveType;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< MoveType, char > MoveTraits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const MoveType&
    move () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    MoveType&
    move ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    move (const MoveType& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    move (::std::auto_ptr< MoveType > p);

    /**
     * @brief Detach the attribute value from the object model.
     *
     * @return A pointer to the attribute value.
     *
     * Note that this function leaves the required attribute in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< MoveType >
    detach_move ();

    //@}

    /**
     * @name type
     *
     * @brief Accessor and modifier functions for the %type
     * optional attribute with a default value.
     *
     * Type of event.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::aosl::Event_type TypeType;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< TypeType, char > TypeTraits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const TypeType&
    type () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    TypeType&
    type ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    type (const TypeType& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    type (::std::auto_ptr< TypeType > p);

    /**
     * @brief Detach the attribute value from the object model.
     *
     * @return A pointer to the attribute value.
     *
     * Note that this function leaves the required attribute in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< TypeType >
    detach_type ();

    /**
     * @brief Return the default value for the attribute.
     *
     * @return A read-only (constant) reference to the attribute's
     * default value.
     */
    static const TypeType&
    type_default_value ();

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    Event (const MoveType&);

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Event (const ::xercesc::DOMElement& e,
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
    Event (const Event& x,
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
    virtual Event*
    _clone (::xml_schema::Flags f = 0,
            ::xml_schema::Container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~Event ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::Flags);

    protected:
    ::xsd::cxx::tree::one< MoveType > move_;
    ::xsd::cxx::tree::one< TypeType > type_;
    static const TypeType type_default_value_;

    //@endcond
  };

  bool
  operator== (const Event&, const Event&);

  bool
  operator!= (const Event&, const Event&);
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "aoslcpp/aosl/move_ref.hpp"
#include "aoslcpp/aosl/move_ref.inl"

#include "aoslcpp/aosl/event_type.hpp"
#include "aoslcpp/aosl/event_type.inl"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

namespace aosl
{
  ::std::ostream&
  operator<< (::std::ostream&, const Event&);
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
  operator<< (::xercesc::DOMElement&, const Event&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "aoslcpp/aosl/event.inl"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__EVENT_HPP
