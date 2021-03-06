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
 * @brief Generated from transformation.xsd.
 */

#ifndef AOSLCPP_AOSL__TRANSFORMATION_HPP
#define AOSLCPP_AOSL__TRANSFORMATION_HPP

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

#include "aosl/transformation_forward.hpp"

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

#include "aosl/referential_forward.hpp"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "aosl/vector_forward.hpp"

#include "aosl/rotation_forward.hpp"

#include "aosl/referential_forward.hpp"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %artofsequence.org/aosl/1.0
 * schema namespace.
 */
namespace aosl
{
  /**
   * @brief Class corresponding to the %transformation schema type.
   *
   * Geometric transformation in graphic space. 
   * The referential says if it's absolute or relative to the target
   * object's position.
   *
   * @nosubgrouping
   */
  class Transformation: public ::xml_schema::Type
  {
    public:
    /**
     * @name translation
     *
     * @brief Accessor and modifier functions for the %translation
     * optional element.
     *
     * Translation to apply to the object position.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Vector TranslationType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< TranslationType > TranslationOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< TranslationType, char > TranslationTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const TranslationOptional&
    translation () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    TranslationOptional&
    translation ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    translation (const TranslationType& x);

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
    translation (const TranslationOptional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    translation (::std::auto_ptr< TranslationType > p);

    //@}

    /**
     * @name scale
     *
     * @brief Accessor and modifier functions for the %scale
     * optional element.
     *
     * Scale to apply to the object's size.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Vector ScaleType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< ScaleType > ScaleOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< ScaleType, char > ScaleTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const ScaleOptional&
    scale () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    ScaleOptional&
    scale ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    scale (const ScaleType& x);

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
    scale (const ScaleOptional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    scale (::std::auto_ptr< ScaleType > p);

    //@}

    /**
     * @name rotation
     *
     * @brief Accessor and modifier functions for the %rotation
     * optional element.
     *
     * Rotation to apply to the object's orientation, relative to it's the
     * center.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Rotation RotationType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< RotationType > RotationOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< RotationType, char > RotationTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const RotationOptional&
    rotation () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    RotationOptional&
    rotation ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    rotation (const RotationType& x);

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
    rotation (const RotationOptional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    rotation (::std::auto_ptr< RotationType > p);

    //@}

    /**
     * @name center
     *
     * @brief Accessor and modifier functions for the %center
     * optional element.
     *
     * Center point in object space to used to apply rotations.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Vector CenterType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< CenterType > CenterOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< CenterType, char > CenterTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const CenterOptional&
    center () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    CenterOptional&
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
     * @brief Set the element value.
     *
     * @param x An optional container with the new value to set.
     *
     * If the value is present in @a x then this function makes a copy 
     * of this value and sets it as the new value of the element.
     * Otherwise the element container is set the 'not present' state.
     */
    void
    center (const CenterOptional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    center (::std::auto_ptr< CenterType > p);

    //@}

    /**
     * @name referential
     *
     * @brief Accessor and modifier functions for the %referential
     * optional attribute with a default value.
     *
     * The referential says if the transformation is applied from the current
     * object's state
     * OR is done from the origin, meaning that this transformation becomes
     * the new state of the object.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::aosl::Referential ReferentialType;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< ReferentialType, char > ReferentialTraits;

    /**
     * @brief Return a read-only (constant) reference to the attribute.
     *
     * @return A constant reference to the attribute.
     */
    const ReferentialType&
    referential () const;

    /**
     * @brief Return a read-write reference to the attribute.
     *
     * @return A reference to the attribute.
     */
    ReferentialType&
    referential ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    referential (const ReferentialType& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly
     * instead of making a copy.
     */
    void
    referential (::std::auto_ptr< ReferentialType > p);

    /**
     * @brief Detach the attribute value from the object model.
     *
     * @return A pointer to the attribute value.
     *
     * Note that this function leaves the required attribute in 
     * the original object model uninitialized.
     */
    ::std::auto_ptr< ReferentialType >
    detach_referential ();

    /**
     * @brief Return the default value for the attribute.
     *
     * @return A read-only (constant) reference to the attribute's
     * default value.
     */
    static const ReferentialType&
    referential_default_value ();

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    Transformation ();

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Transformation (const ::xercesc::DOMElement& e,
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
    Transformation (const Transformation& x,
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
    virtual Transformation*
    _clone (::xml_schema::Flags f = 0,
            ::xml_schema::Container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~Transformation ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::Flags);

    protected:
    TranslationOptional translation_;
    ScaleOptional scale_;
    RotationOptional rotation_;
    CenterOptional center_;
    ::xsd::cxx::tree::one< ReferentialType > referential_;
    static const ReferentialType referential_default_value_;

    //@endcond
  };

  bool
  operator== (const Transformation&, const Transformation&);

  bool
  operator!= (const Transformation&, const Transformation&);
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "aosl/vector.hpp"
#include "aosl/vector.inl"

#include "aosl/rotation.hpp"
#include "aosl/rotation.inl"

#include "aosl/referential.hpp"
#include "aosl/referential.inl"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

namespace aosl
{
  ::std::ostream&
  operator<< (::std::ostream&, const Transformation&);
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
  operator<< (::xercesc::DOMElement&, const Transformation&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "aosl/transformation.inl"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__TRANSFORMATION_HPP
