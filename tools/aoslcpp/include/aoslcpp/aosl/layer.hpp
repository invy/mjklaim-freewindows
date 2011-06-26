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
 * @brief Generated from layer.xsd.
 */

#ifndef AOSLCPP_AOSL__LAYER_HPP
#define AOSLCPP_AOSL__LAYER_HPP

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

#include "aoslcpp/aosl/layer_forward.hpp"

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

#include "aoslcpp/aosl/extension_forward.hpp"

#include "aoslcpp/aosl/layer_id_forward.hpp"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "aoslcpp/aosl/extension_forward.hpp"

#include "aoslcpp/aosl/layer_id_forward.hpp"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %http://artofsequence.org/aosl/1.x
 * schema namespace.
 */
namespace aosl
{
  /**
   * @brief Class corresponding to the %layer schema type.
   *
   * A Layer is a way to activate and deactivate a group of unrelated
   * objects.
   * It is orthogonal to the hierarchical organisation of Objects.
   * An object bound to a layer will be active when both it's parent object
   * and the layer are active,
   * but will be inactive if any one of them is deactivated.
   * It can be used for localization (one layer per language with texts in
   * it).
   *
   * @nosubgrouping
   */
  class AOSLCPP_API Layer: public ::xml_schema::Type
  {
    public:
    /**
     * @name extension
     *
     * @brief Accessor and modifier functions for the %extension
     * optional element.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Extension ExtensionType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< ExtensionType > ExtensionOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< ExtensionType, char > ExtensionTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const ExtensionOptional&
    extension () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    ExtensionOptional&
    extension ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    extension (const ExtensionType& x);

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
    extension (const ExtensionOptional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    extension (::std::auto_ptr< ExtensionType > p);

    //@}

    /**
     * @name id
     *
     * @brief Accessor and modifier functions for the %id
     * required attribute.
     *
     * Id of the Layer, to be used by Objects that are bound to it.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::aosl::Layer_id IdType;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< IdType, char > IdTraits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const IdType&
    id () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    IdType&
    id ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    id (const IdType& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    id (::std::auto_ptr< IdType > p);

    /**
     * @brief Detach the attribute value from the object model.
     *
     * @return A pointer to the attribute value.
     *
     * Note that this function leaves the required attribute in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< IdType >
    detach_id ();

    //@}

    /**
     * @name active
     *
     * @brief Accessor and modifier functions for the %active
     * optional attribute with a default value.
     *
     * Is this Layer active or unactive?
     * When active all the bound Objects will be active if their parent is
     * active too.
     * When unactive all the bound Objects will be unactive, without
     * considering the parent's state.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::Boolean ActiveType;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< ActiveType, char > ActiveTraits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const ActiveType&
    active () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    ActiveType&
    active ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    active (const ActiveType& x);

    /**
     * @brief Return the default value for the attribute.
     *
     * @return The attribute's default value.
     */
    static ActiveType
    active_default_value ();

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
    Layer ();

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    Layer (const IdType&);

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Layer (const ::xercesc::DOMElement& e,
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
    Layer (const Layer& x,
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
    virtual Layer*
    _clone (::xml_schema::Flags f = 0,
            ::xml_schema::Container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~Layer ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::Flags);

    protected:
    ExtensionOptional extension_;
    ::xsd::cxx::tree::one< IdType > id_;
    ::xsd::cxx::tree::one< ActiveType > active_;

    //@endcond
  };

  AOSLCPP_API
  bool
  operator== (const Layer&, const Layer&);

  AOSLCPP_API
  bool
  operator!= (const Layer&, const Layer&);
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "aoslcpp/aosl/extension.hpp"
#include "aoslcpp/aosl/extension.inl"

#include "aoslcpp/aosl/layer_id.hpp"
#include "aoslcpp/aosl/layer_id.inl"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

namespace aosl
{
  AOSLCPP_API
  ::std::ostream&
  operator<< (::std::ostream&, const Layer&);
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
  operator<< (::xercesc::DOMElement&, const Layer&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "aoslcpp/aosl/layer.inl"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__LAYER_HPP
