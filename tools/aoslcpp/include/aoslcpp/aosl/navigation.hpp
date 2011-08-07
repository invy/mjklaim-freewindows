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
 * @brief Generated from navigation.xsd.
 */

#ifndef AOSLCPP_AOSL__NAVIGATION_HPP
#define AOSLCPP_AOSL__NAVIGATION_HPP

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

#include "aoslcpp/aosl/navigation_forward.hpp"

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

#include "aoslcpp/aosl/event_forward.hpp"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "aoslcpp/aosl/event_forward.hpp"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %artofsequence.org/aosl/1.0
 * schema namespace.
 */
namespace aosl
{
  /**
   * @brief Class corresponding to the %navigation schema type.
   *
   * Navigation informations are used by the player/interpreter to know how
   * to bind user actions to Moves.
   * It hold a set of Events that define responses to events from user
   * input or player/interpreter informations.
   * It can be used for defining the global navigation or more precisely in
   * the context of a specific Stage.
   *
   * @nosubgrouping
   */
  class Navigation: public ::xml_schema::Type
  {
    public:
    /**
     * @name event
     *
     * @brief Accessor and modifier functions for the %event
     * sequence element.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Event EventType;

    /**
     * @brief Element sequence container type.
     */
    typedef ::xsd::cxx::tree::sequence< EventType > EventSequence;

    /**
     * @brief Element iterator type.
     */
    typedef EventSequence::iterator EventIterator;

    /**
     * @brief Element constant iterator type.
     */
    typedef EventSequence::const_iterator EventConstIterator;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< EventType, char > EventTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * sequence.
     *
     * @return A constant reference to the sequence container.
     */
    const EventSequence&
    event () const;

    /**
     * @brief Return a read-write reference to the element sequence.
     *
     * @return A reference to the sequence container.
     */
    EventSequence&
    event ();

    /**
     * @brief Copy elements from a given sequence.
     *
     * @param s A sequence to copy elements from.
     *
     * For each element in @a s this function makes a copy and adds it 
     * to the sequence. Note that this operation completely changes the 
     * sequence and all old elements will be lost.
     */
    void
    event (const EventSequence& s);

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    Navigation ();

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Navigation (const ::xercesc::DOMElement& e,
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
    Navigation (const Navigation& x,
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
    virtual Navigation*
    _clone (::xml_schema::Flags f = 0,
            ::xml_schema::Container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~Navigation ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::Flags);

    protected:
    EventSequence event_;

    //@endcond
  };

  bool
  operator== (const Navigation&, const Navigation&);

  bool
  operator!= (const Navigation&, const Navigation&);
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "aoslcpp/aosl/event.hpp"
#include "aoslcpp/aosl/event.inl"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

namespace aosl
{
  ::std::ostream&
  operator<< (::std::ostream&, const Navigation&);
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
  operator<< (::xercesc::DOMElement&, const Navigation&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "aoslcpp/aosl/navigation.inl"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__NAVIGATION_HPP
