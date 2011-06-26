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
 * @brief Generated from meta.xsd.
 */

#ifndef AOSLCPP_AOSL__META_HPP
#define AOSLCPP_AOSL__META_HPP

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

#include "aoslcpp/aosl/meta_forward.hpp"

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

#include "aoslcpp/aosl/version_forward.hpp"

#include "aoslcpp/aosl/list_author_forward.hpp"

#include "aoslcpp/aosl/list_target_forward.hpp"

#include "aoslcpp/aosl/extension_forward.hpp"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "aoslcpp/aosl/version_forward.hpp"

#include "aoslcpp/aosl/list_author_forward.hpp"

#include "aoslcpp/aosl/list_target_forward.hpp"

#include "aoslcpp/aosl/extension_forward.hpp"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %http://artofsequence.org/aosl/1.x
 * schema namespace.
 */
namespace aosl
{
  /**
   * @brief Class corresponding to the %meta schema type.
   *
   * Additional informations about the sequence.
   *
   * @nosubgrouping
   */
  class AOSLCPP_API Meta: public ::xml_schema::Type
  {
    public:
    /**
     * @name version
     *
     * @brief Accessor and modifier functions for the %version
     * optional element.
     *
     * Version name of the Sequence.
     * The format of the versionning scheme is free.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Version VersionType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< VersionType > VersionOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< VersionType, char > VersionTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const VersionOptional&
    version () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    VersionOptional&
    version ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    version (const VersionType& x);

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
    version (const VersionOptional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    version (::std::auto_ptr< VersionType > p);

    //@}

    /**
     * @name authors
     *
     * @brief Accessor and modifier functions for the %authors
     * optional element.
     *
     * Informations about the authors of the sequence.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::List_author AuthorsType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< AuthorsType > AuthorsOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< AuthorsType, char > AuthorsTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const AuthorsOptional&
    authors () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    AuthorsOptional&
    authors ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    authors (const AuthorsType& x);

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
    authors (const AuthorsOptional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    authors (::std::auto_ptr< AuthorsType > p);

    //@}

    /**
     * @name description
     *
     * @brief Accessor and modifier functions for the %description
     * optional element.
     *
     * Description of the sequence's content.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::xml_schema::String DescriptionType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< DescriptionType > DescriptionOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< DescriptionType, char > DescriptionTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const DescriptionOptional&
    description () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    DescriptionOptional&
    description ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    description (const DescriptionType& x);

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
    description (const DescriptionOptional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    description (::std::auto_ptr< DescriptionType > p);

    //@}

    /**
     * @name website
     *
     * @brief Accessor and modifier functions for the %website
     * optional element.
     *
     * Website associated with this sequence.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::xml_schema::Uri WebsiteType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< WebsiteType > WebsiteOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< WebsiteType, char > WebsiteTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const WebsiteOptional&
    website () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    WebsiteOptional&
    website ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    website (const WebsiteType& x);

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
    website (const WebsiteOptional& x);

    /**
     * @brief Set the element value without copying.
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
     * @name licence
     *
     * @brief Accessor and modifier functions for the %licence
     * optional element.
     *
     * Licence of the sequence.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::xml_schema::String LicenceType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< LicenceType > LicenceOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< LicenceType, char > LicenceTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const LicenceOptional&
    licence () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    LicenceOptional&
    licence ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    licence (const LicenceType& x);

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
    licence (const LicenceOptional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    licence (::std::auto_ptr< LicenceType > p);

    //@}

    /**
     * @name targets
     *
     * @brief Accessor and modifier functions for the %targets
     * optional element.
     *
     * Informations about the players originally targetted for this sequence
     * and configuration data.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::List_target TargetsType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< TargetsType > TargetsOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< TargetsType, char > TargetsTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const TargetsOptional&
    targets () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    TargetsOptional&
    targets ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    targets (const TargetsType& x);

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
    targets (const TargetsOptional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    targets (::std::auto_ptr< TargetsType > p);

    //@}

    /**
     * @name infos
     *
     * @brief Accessor and modifier functions for the %infos
     * optional element.
     *
     * Additional informations.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::aosl::Extension InfosType;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< InfosType > InfosOptional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< InfosType, char > InfosTraits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const InfosOptional&
    infos () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    InfosOptional&
    infos ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    infos (const InfosType& x);

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
    infos (const InfosOptional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    infos (::std::auto_ptr< InfosType > p);

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    Meta ();

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    Meta (const ::xercesc::DOMElement& e,
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
    Meta (const Meta& x,
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
    virtual Meta*
    _clone (::xml_schema::Flags f = 0,
            ::xml_schema::Container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~Meta ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::Flags);

    protected:
    VersionOptional version_;
    AuthorsOptional authors_;
    DescriptionOptional description_;
    WebsiteOptional website_;
    LicenceOptional licence_;
    TargetsOptional targets_;
    InfosOptional infos_;

    //@endcond
  };

  AOSLCPP_API
  bool
  operator== (const Meta&, const Meta&);

  AOSLCPP_API
  bool
  operator!= (const Meta&, const Meta&);
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "aoslcpp/aosl/version.hpp"
#include "aoslcpp/aosl/version.inl"

#include "aoslcpp/aosl/list_author.hpp"
#include "aoslcpp/aosl/list_author.inl"

#include "aoslcpp/aosl/list_target.hpp"
#include "aoslcpp/aosl/list_target.inl"

#include "aoslcpp/aosl/extension.hpp"
#include "aoslcpp/aosl/extension.inl"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

namespace aosl
{
  AOSLCPP_API
  ::std::ostream&
  operator<< (::std::ostream&, const Meta&);
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
  operator<< (::xercesc::DOMElement&, const Meta&);
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "aoslcpp/aosl/meta.inl"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__META_HPP
