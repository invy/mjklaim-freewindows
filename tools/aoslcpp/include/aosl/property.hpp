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
 * @brief Generated from property.xsd.
 */

#ifndef AOSLCPP_AOSL__PROPERTY_HPP
#define AOSLCPP_AOSL__PROPERTY_HPP

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

#include "aosl/property_forward.hpp"

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

#include "aosl/property_forward.hpp"

#include "aosl/name_forward.hpp"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "aosl/property_forward.hpp"

#include "aosl/name_forward.hpp"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %artofsequence.org/aosl/1.0
 * schema namespace.
 */
namespace aosl
{
  /**
   * @brief Class corresponding to the %property schema type.
   *
   * Properties are key/value informations that can be organized in tree
   * structures.
   * They are used to embedd hierarchical custom data in objects.
   * Properties can contain a value and other properties.
   *
   * @nosubgrouping
   */
  class Property: public ::xml_schema::Type
  {
    public:
    /**
     * @name property
     *
     * @brief Accessor and modifier functions for the %property
     * sequence element.
     *
     * A child property of this property.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Property Property1Type;

    /**
     * @brief Element sequence container type.
     */
    typedef ::xsd::cxx::tree::sequence< Property1Type > Property1Sequence;

    /**
     * @brief Element iterator type.
     */
    typedef Property1Sequence::iterator Property1Iterator;

    /**
     * @brief Element constant iterator type.
     */
    typedef Property1Sequence::const_iterator Property1ConstIterator;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< Property1Type, char > Property1Traits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * sequence.
     *
     * @return A constant reference to the sequence container.
     */
    const Property1Sequence&
    property1 () const;

    /**
     * @brief Return a read-write reference to the element sequence.
     *
     * @return A reference to the sequence container.
     */
    Property1Sequence&
    property1 ();

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
    property1 (const Property1Sequence& s);

    //@}

    /**
     * @name name
     *
     * @brief Accessor and modifier functions for the %name
     * required attribute.
     *
     * Name of this property instance.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::aosl::Name NameType;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< NameType, char > NameTraits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const NameType&
    name () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    NameType&
    name ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    name (const NameType& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    name (::std::auto_ptr< NameType > p);

    /**
     * @brief Detach the attribute value from the object model.
     *
     * @return A pointer to the attribute value.
     *
     * Note that this function leaves the required attribute in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< NameType >
    detach_name ();

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    Property (const NameType&);

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Property (const ::xercesc::DOMElement& e,
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
    Property (const Property& x,
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
    virtual Property*
    _clone (::xml_schema::Flags f = 0,
            ::xml_schema::Container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~Property ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::Flags);

    protected:
    Property1Sequence property1_;
    ::xsd::cxx::tree::one< NameType > name_;

    //@endcond
  };

  bool
  operator== (const Property&, const Property&);

  bool
  operator!= (const Property&, const Property&);
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "aosl/property.hpp"
#include "aosl/property.inl"

#include "aosl/name.hpp"
#include "aosl/name.inl"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

namespace aosl
{
  ::std::ostream&
  operator<< (::std::ostream&, const Property&);
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
  operator<< (::xercesc::DOMElement&, const Property&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "aosl/property.inl"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__PROPERTY_HPP
