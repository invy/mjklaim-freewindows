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
 * @brief Generated from target.xsd.
 */

#ifndef AOSLCPP_AOSL__TARGET_HPP
#define AOSLCPP_AOSL__TARGET_HPP

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

#include "aoslcpp/aosl/target_forward.hpp"

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

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "aoslcpp/aosl/extension_forward.hpp"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %artofsequence.org/aosl/1.0
 * schema namespace.
 */
namespace aosl
{
  /**
   * @brief Class corresponding to the %target schema type.
   *
   * Informations about the target player/interpreter and platform.
   *
   * @nosubgrouping
   */
  class Target: public ::xml_schema::Type
  {
    public:
    /**
     * @name config
     *
     * @brief Accessor and modifier functions for the %config
     * optional element.
     *
     * Target-specific configuration informations.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Extension ConfigType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< ConfigType > ConfigOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< ConfigType, char > ConfigTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const ConfigOptional&
    config () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    ConfigOptional&
    config ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    config (const ConfigType& x);

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
    config (const ConfigOptional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    config (::std::auto_ptr< ConfigType > p);

    //@}

    /**
     * @name player
     *
     * @brief Accessor and modifier functions for the %player
     * optional attribute.
     *
     * Name identifiying the player/interpreter that this sequence is made
     * for.
     * Other players can read it too but somme player-specific extensions
     * will simply be ignored if the interpreter don't implement them.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::String PlayerType;

    /**
     * @brief Attribute optional container type.
     */
    typedef ::xsd::cxx::tree::optional< PlayerType > PlayerOptional;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< PlayerType, char > PlayerTraits;

    /**
     * @brief Return a read-only (constant) reference to the attribute
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const PlayerOptional&
    player () const;

    /**
     * @brief Return a read-write reference to the attribute container.
     *
     * @return A reference to the optional container.
     */
    PlayerOptional&
    player ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    player (const PlayerType& x);

    /**
     * @brief Set the attribute value.
     *
     * @param x An optional container with the new value to set.
     *
     * If the value is present in @a x then this function makes a copy 
     * of this value and sets it as the new value of the attribute.
     * Otherwise the attribute container is set the 'not present' state.
     */
    void
    player (const PlayerOptional& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    player (::std::auto_ptr< PlayerType > p);

    //@}

    /**
     * @name platform
     *
     * @brief Accessor and modifier functions for the %platform
     * optional attribute.
     *
     * Name identifiying the platform that this sequence is made for.
     * This is to clearly make the difference between a player being
     * available on
     * different platforms and performing differently while bieing having the
     * same code/binary.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::String PlatformType;

    /**
     * @brief Attribute optional container type.
     */
    typedef ::xsd::cxx::tree::optional< PlatformType > PlatformOptional;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< PlatformType, char > PlatformTraits;

    /**
     * @brief Return a read-only (constant) reference to the attribute
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const PlatformOptional&
    platform () const;

    /**
     * @brief Return a read-write reference to the attribute container.
     *
     * @return A reference to the optional container.
     */
    PlatformOptional&
    platform ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    platform (const PlatformType& x);

    /**
     * @brief Set the attribute value.
     *
     * @param x An optional container with the new value to set.
     *
     * If the value is present in @a x then this function makes a copy 
     * of this value and sets it as the new value of the attribute.
     * Otherwise the attribute container is set the 'not present' state.
     */
    void
    platform (const PlatformOptional& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    platform (::std::auto_ptr< PlatformType > p);

    //@}

    /**
     * @name website
     *
     * @brief Accessor and modifier functions for the %website
     * optional attribute.
     *
     * Website of the target provider.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::xml_schema::Uri WebsiteType;

    /**
     * @brief Attribute optional container type.
     */
    typedef ::xsd::cxx::tree::optional< WebsiteType > WebsiteOptional;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< WebsiteType, char > WebsiteTraits;

    /**
     * @brief Return a read-only (constant) reference to the attribute
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const WebsiteOptional&
    website () const;

    /**
     * @brief Return a read-write reference to the attribute container.
     *
     * @return A reference to the optional container.
     */
    WebsiteOptional&
    website ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    website (const WebsiteType& x);

    /**
     * @brief Set the attribute value.
     *
     * @param x An optional container with the new value to set.
     *
     * If the value is present in @a x then this function makes a copy 
     * of this value and sets it as the new value of the attribute.
     * Otherwise the attribute container is set the 'not present' state.
     */
    void
    website (const WebsiteOptional& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    website (::std::auto_ptr< WebsiteType > p);

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    Target ();

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Target (const ::xercesc::DOMElement& e,
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
    Target (const Target& x,
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
    virtual Target*
    _clone (::xml_schema::Flags f = 0,
            ::xml_schema::Container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~Target ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::Flags);

    protected:
    ConfigOptional config_;
    PlayerOptional player_;
    PlatformOptional platform_;
    WebsiteOptional website_;

    //@endcond
  };

  bool
  operator== (const Target&, const Target&);

  bool
  operator!= (const Target&, const Target&);
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "aoslcpp/aosl/extension.hpp"
#include "aoslcpp/aosl/extension.inl"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

namespace aosl
{
  ::std::ostream&
  operator<< (::std::ostream&, const Target&);
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
  operator<< (::xercesc::DOMElement&, const Target&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "aoslcpp/aosl/target.inl"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__TARGET_HPP
