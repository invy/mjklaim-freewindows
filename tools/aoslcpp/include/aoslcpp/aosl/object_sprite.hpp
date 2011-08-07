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
 * @brief Generated from object_sprite.xsd.
 */

#ifndef AOSLCPP_AOSL__OBJECT_SPRITE_HPP
#define AOSLCPP_AOSL__OBJECT_SPRITE_HPP

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

#include "aoslcpp/aosl/object_sprite_forward.hpp"

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

#include "aoslcpp/aosl/object.hpp"

#include "aoslcpp/aosl/properties_graphic_object_forward.hpp"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "aoslcpp/aosl/object.hpp"

#include "aoslcpp/aosl/properties_graphic_object_forward.hpp"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %artofsequence.org/aosl/1.0
 * schema namespace.
 */
namespace aosl
{
  /**
   * @brief Class corresponding to the %object_sprite schema type.
   *
   * A Sprite is a simple graphic Object.
   *
   * @nosubgrouping
   */
  class Object_sprite: public ::aosl::Object
  {
    public:
    /**
     * @name graphic
     *
     * @brief Accessor and modifier functions for the %graphic
     * required element.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Properties_graphic_object GraphicType;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< GraphicType, char > GraphicTraits;

    /**
     * @brief Return a read-only (constant) reference to the element.
     *
     * @return A constant reference to the element.
     */
    const GraphicType&
    graphic () const;

    /**
     * @brief Return a read-write reference to the element.
     *
     * @return A reference to the element.
     */
    GraphicType&
    graphic ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    graphic (const GraphicType& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    graphic (::std::auto_ptr< GraphicType > p);

    /**
     * @brief Detach the element value from the object model.
     *
     * @return A pointer to the element value.
     *
     * Note that this function leaves the required element in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< GraphicType >
    detach_graphic ();

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    Object_sprite (const IdType&,
                   const GraphicType&);

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes
     * (auto_ptr version).
     *
     * This constructor will try to use the passed values directly
     * instead of making copies.
     */
    Object_sprite (const IdType&,
                   ::std::auto_ptr< GraphicType >&);

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Object_sprite (const ::xercesc::DOMElement& e,
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
    Object_sprite (const Object_sprite& x,
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
    virtual Object_sprite*
    _clone (::xml_schema::Flags f = 0,
            ::xml_schema::Container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~Object_sprite ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::Flags);

    protected:
    ::xsd::cxx::tree::one< GraphicType > graphic_;

    //@endcond
  };

  bool
  operator== (const Object_sprite&, const Object_sprite&);

  bool
  operator!= (const Object_sprite&, const Object_sprite&);
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "aoslcpp/aosl/object.inl"

#include "aoslcpp/aosl/properties_graphic_object.hpp"
#include "aoslcpp/aosl/properties_graphic_object.inl"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

namespace aosl
{
  ::std::ostream&
  operator<< (::std::ostream&, const Object_sprite&);
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
  operator<< (::xercesc::DOMElement&, const Object_sprite&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "aoslcpp/aosl/object_sprite.inl"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__OBJECT_SPRITE_HPP
