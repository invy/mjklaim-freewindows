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
 * @brief Generated from change.xsd.
 */

#ifndef AOSLCPP_AOSL__CHANGE_HPP
#define AOSLCPP_AOSL__CHANGE_HPP

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

#include "aosl/change_forward.hpp"

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

#include "aosl/list_effect_forward.hpp"

#include "aosl/script_forward.hpp"

#include "aosl/extension_forward.hpp"

#include "aosl/change_type_forward.hpp"

#include "aosl/object_ref_forward.hpp"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "aosl/list_effect_forward.hpp"

#include "aosl/script_forward.hpp"

#include "aosl/extension_forward.hpp"

#include "aosl/change_type_forward.hpp"

#include "aosl/object_ref_forward.hpp"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %artofsequence.org/aosl/1.0
 * schema namespace.
 */
namespace aosl
{
  /**
   * @brief Class corresponding to the %change schema type.
   *
   * A Change describe a set of transformations (geometric or not) that
   * will be applied to an Object.
   * Changes are contained in Moves that are applied when going from one
   * Stage to another.
   * A Change can be a transform, activate, deactivate, switch or any other
   * interpreter-specific change.
   *
   * @nosubgrouping
   */
  class Change: public ::xml_schema::Type
  {
    public:
    /**
     * @name effects
     *
     * @brief Accessor and modifier functions for the %effects
     * optional element.
     *
     * Interpreter-defined effects to apply to the Change interpretation.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::List_effect EffectsType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< EffectsType > EffectsOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< EffectsType, char > EffectsTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const EffectsOptional&
    effects () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    EffectsOptional&
    effects ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    effects (const EffectsType& x);

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
    effects (const EffectsOptional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    effects (::std::auto_ptr< EffectsType > p);

    //@}

    /**
     * @name script
     *
     * @brief Accessor and modifier functions for the %script
     * optional element.
     *
     * Script to execute when this Change is applied.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Script ScriptType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< ScriptType > ScriptOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< ScriptType, char > ScriptTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const ScriptOptional&
    script () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    ScriptOptional&
    script ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    script (const ScriptType& x);

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
    script (const ScriptOptional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    script (::std::auto_ptr< ScriptType > p);

    //@}

    /**
     * @name extension
     *
     * @brief Accessor and modifier functions for the %extension
     * optional element.
     *
     * Interpreter-defined additional informations.
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
     * @name type
     *
     * @brief Accessor and modifier functions for the %type
     * optional attribute with a default value.
     *
     * Name of the type of this Change.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::aosl::Change_type TypeType;

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
     * @name object
     *
     * @brief Accessor and modifier functions for the %object
     * required attribute.
     *
     * Object to wich this change applies.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::aosl::Object_ref ObjectType;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< ObjectType, char > ObjectTraits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const ObjectType&
    object () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    ObjectType&
    object ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    object (const ObjectType& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    object (::std::auto_ptr< ObjectType > p);

    /**
     * @brief Detach the attribute value from the object model.
     *
     * @return A pointer to the attribute value.
     *
     * Note that this function leaves the required attribute in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< ObjectType >
    detach_object ();

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    Change (const ObjectType&);

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Change (const ::xercesc::DOMElement& e,
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
    Change (const Change& x,
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
    virtual Change*
    _clone (::xml_schema::Flags f = 0,
            ::xml_schema::Container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~Change ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::Flags);

    protected:
    EffectsOptional effects_;
    ScriptOptional script_;
    ExtensionOptional extension_;
    ::xsd::cxx::tree::one< TypeType > type_;
    static const TypeType type_default_value_;
    ::xsd::cxx::tree::one< ObjectType > object_;

    //@endcond
  };

  bool
  operator== (const Change&, const Change&);

  bool
  operator!= (const Change&, const Change&);
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "aosl/list_effect.hpp"
#include "aosl/list_effect.inl"

#include "aosl/script.hpp"
#include "aosl/script.inl"

#include "aosl/extension.hpp"
#include "aosl/extension.inl"

#include "aosl/change_type.hpp"
#include "aosl/change_type.inl"

#include "aosl/object_ref.hpp"
#include "aosl/object_ref.inl"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

namespace aosl
{
  ::std::ostream&
  operator<< (::std::ostream&, const Change&);
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
  operator<< (::xercesc::DOMElement&, const Change&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "aosl/change.inl"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__CHANGE_HPP
