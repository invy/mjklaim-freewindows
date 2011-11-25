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
 * @brief Generated from library.xsd.
 */

#ifndef AOSLCPP_AOSL__LIBRARY_HPP
#define AOSLCPP_AOSL__LIBRARY_HPP

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

#include "aosl/library_forward.hpp"

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

#include "aosl/list_include_forward.hpp"

#include "aosl/list_resource_forward.hpp"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "aosl/list_include_forward.hpp"

#include "aosl/list_resource_forward.hpp"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %artofsequence.org/aosl/1.0
 * schema namespace.
 */
namespace aosl
{
  /**
   * @brief Class corresponding to the %library schema type.
   *
   * The Library contain informations about a set of Resources that can be
   * used in a Sequence.
   *
   * @nosubgrouping
   */
  class Library: public ::xml_schema::Type
  {
    public:
    /**
     * @name import
     *
     * @brief Accessor and modifier functions for the %import
     * optional element.
     *
     * External libraries to import.
     * Importing a library means getting the resources of the target library
     * and 
     * putting them in this one.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::List_include ImportType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< ImportType > ImportOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< ImportType, char > ImportTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const ImportOptional&
    import () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    ImportOptional&
    import ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    import (const ImportType& x);

    /**
     * @brief Set the element value.
     *
     * @param x An optional container with the new value to set.
     *
     * If the value is present in @a x then this function makes a copy 
     * of this value and sets it as the new value of the element.
     * Otherwise the element container is set the 'not present' state.
     */
    void
    import (const ImportOptional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    import (::std::auto_ptr< ImportType > p);

    //@}

    /**
     * @name resources
     *
     * @brief Accessor and modifier functions for the %resources
     * required element.
     *
     * Resources to load to play this Sequence.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::List_resource ResourcesType;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< ResourcesType, char > ResourcesTraits;

    /**
     * @brief Return a read-only (constant) reference to the element.
     *
     * @return A constant reference to the element.
     */
    const ResourcesType&
    resources () const;

    /**
     * @brief Return a read-write reference to the element.
     *
     * @return A reference to the element.
     */
    ResourcesType&
    resources ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    resources (const ResourcesType& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    resources (::std::auto_ptr< ResourcesType > p);

    /**
     * @brief Detach the element value from the object model.
     *
     * @return A pointer to the element value.
     *
     * Note that this function leaves the required element in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< ResourcesType >
    detach_resources ();

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    Library (const ResourcesType&);

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes
     * (auto_ptr version).
     *
     * This constructor will try to use the passed values directly
     * instead of making copies.
     */
    Library (::std::auto_ptr< ResourcesType >&);

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Library (const ::xercesc::DOMElement& e,
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
    Library (const Library& x,
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
    virtual Library*
    _clone (::xml_schema::Flags f = 0,
            ::xml_schema::Container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~Library ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::Flags);

    protected:
    ImportOptional import_;
    ::xsd::cxx::tree::one< ResourcesType > resources_;

    //@endcond
  };

  bool
  operator== (const Library&, const Library&);

  bool
  operator!= (const Library&, const Library&);
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "aosl/list_include.hpp"
#include "aosl/list_include.inl"

#include "aosl/list_resource.hpp"
#include "aosl/list_resource.inl"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

namespace aosl
{
  ::std::ostream&
  operator<< (::std::ostream&, const Library&);
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
  operator<< (::xercesc::DOMElement&, const Library&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "aosl/library.inl"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__LIBRARY_HPP