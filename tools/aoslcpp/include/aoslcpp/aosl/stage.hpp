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
 * @brief Generated from stage.xsd.
 */

#ifndef AOSLCPP_AOSL__STAGE_HPP
#define AOSLCPP_AOSL__STAGE_HPP

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

#include "aoslcpp/aosl/stage_forward.hpp"

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

#include "aoslcpp/aosl/navigation_forward.hpp"

#include "aoslcpp/aosl/script_forward.hpp"

#include "aoslcpp/aosl/extension_forward.hpp"

#include "aoslcpp/aosl/stage_id_forward.hpp"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "aoslcpp/aosl/navigation_forward.hpp"

#include "aoslcpp/aosl/script_forward.hpp"

#include "aoslcpp/aosl/extension_forward.hpp"

#include "aoslcpp/aosl/stage_id_forward.hpp"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %artofsequence.org/aosl/1.0
 * schema namespace.
 */
namespace aosl
{
  /**
   * @brief Class corresponding to the %stage schema type.
   *
   * A Stage describe a specific state in the path followed by the
   * player/interpreter when playing the Sequence.
   * A Stage is to a Story what a vertex is to a graph.
   *
   * @nosubgrouping
   */
  class Stage: public ::xml_schema::Type
  {
    public:
    /**
     * @name navigation
     *
     * @brief Accessor and modifier functions for the %navigation
     * optional element.
     *
     * Navigation informations that will overload the Story navigation
     * informations when we reach this stage.
     * Setting this stage-specific Navigation is useful for allowing special
     * actions or choices on specific occasions.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Navigation NavigationType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< NavigationType > NavigationOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< NavigationType, char > NavigationTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const NavigationOptional&
    navigation () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    NavigationOptional&
    navigation ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    navigation (const NavigationType& x);

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
    navigation (const NavigationOptional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    navigation (::std::auto_ptr< NavigationType > p);

    //@}

    /**
     * @name script
     *
     * @brief Accessor and modifier functions for the %script
     * optional element.
     *
     * Script to execute when we reach this stage.
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
     * @name id
     *
     * @brief Accessor and modifier functions for the %id
     * required attribute.
     *
     * Id of the stage.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::aosl::Stage_id IdType;

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
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    Stage (const IdType&);

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Stage (const ::xercesc::DOMElement& e,
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
    Stage (const Stage& x,
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
    virtual Stage*
    _clone (::xml_schema::Flags f = 0,
            ::xml_schema::Container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~Stage ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::Flags);

    protected:
    NavigationOptional navigation_;
    ScriptOptional script_;
    ExtensionOptional extension_;
    ::xsd::cxx::tree::one< IdType > id_;

    //@endcond
  };

  bool
  operator== (const Stage&, const Stage&);

  bool
  operator!= (const Stage&, const Stage&);
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "aoslcpp/aosl/navigation.hpp"
#include "aoslcpp/aosl/navigation.inl"

#include "aoslcpp/aosl/script.hpp"
#include "aoslcpp/aosl/script.inl"

#include "aoslcpp/aosl/extension.hpp"
#include "aoslcpp/aosl/extension.inl"

#include "aoslcpp/aosl/stage_id.hpp"
#include "aoslcpp/aosl/stage_id.inl"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

namespace aosl
{
  ::std::ostream&
  operator<< (::std::ostream&, const Stage&);
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
  operator<< (::xercesc::DOMElement&, const Stage&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "aoslcpp/aosl/stage.inl"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__STAGE_HPP
