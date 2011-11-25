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
 * @brief Generated from properties_graphic_object.xsd.
 */

#ifndef AOSLCPP_AOSL__PROPERTIES_GRAPHIC_OBJECT_HPP
#define AOSLCPP_AOSL__PROPERTIES_GRAPHIC_OBJECT_HPP

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

#include "aosl/properties_graphic_object_forward.hpp"

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

#include "aosl/box_forward.hpp"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "aosl/box_forward.hpp"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %artofsequence.org/aosl/1.0
 * schema namespace.
 */
namespace aosl
{
  /**
   * @brief Class corresponding to the %properties_graphic_object schema type.
   *
   * Graphic object representation. Properties for Objects with graphic
   * behaviour.
   *
   * @nosubgrouping
   */
  class Properties_graphic_object: public ::xml_schema::Type
  {
    public:
    /**
     * @name output
     *
     * @brief Accessor and modifier functions for the %output
     * optional element.
     *
     * Area in the Canvas where that the graphic output will occupy.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Box OutputType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< OutputType > OutputOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< OutputType, char > OutputTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const OutputOptional&
    output () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    OutputOptional&
    output ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    output (const OutputType& x);

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
    output (const OutputOptional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    output (::std::auto_ptr< OutputType > p);

    //@}

    /**
     * @name input
     *
     * @brief Accessor and modifier functions for the %input
     * optional element.
     *
     * Area in the Resource (if applicable) from wich the graphic input will
     * be extracted. 
     * Useful to use only a part of a resource, 
     * for example when having a sprite from a graphic texture.
     * 
     * A null-size input box (0,0,0) - the default value - means the whole
     * resource have to be used.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Box InputType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< InputType > InputOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< InputType, char > InputTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const InputOptional&
    input () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    InputOptional&
    input ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    input (const InputType& x);

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
    input (const InputOptional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    input (::std::auto_ptr< InputType > p);

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    Properties_graphic_object ();

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Properties_graphic_object (const ::xercesc::DOMElement& e,
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
    Properties_graphic_object (const Properties_graphic_object& x,
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
    virtual Properties_graphic_object*
    _clone (::xml_schema::Flags f = 0,
            ::xml_schema::Container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~Properties_graphic_object ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::Flags);

    protected:
    OutputOptional output_;
    InputOptional input_;

    //@endcond
  };

  bool
  operator== (const Properties_graphic_object&, const Properties_graphic_object&);

  bool
  operator!= (const Properties_graphic_object&, const Properties_graphic_object&);
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "aosl/box.hpp"
#include "aosl/box.inl"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

namespace aosl
{
  ::std::ostream&
  operator<< (::std::ostream&, const Properties_graphic_object&);
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
  operator<< (::xercesc::DOMElement&, const Properties_graphic_object&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "aosl/properties_graphic_object.inl"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__PROPERTIES_GRAPHIC_OBJECT_HPP