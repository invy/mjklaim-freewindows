// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__AUTHOR_INL
#define AOSLCPP_AOSL__AUTHOR_INL

// Begin prologue.
//
//
// End prologue.

#include "aoslcpp/aosl/extension.hpp"
#include "aoslcpp/aosl/extension.inl"

namespace aosl
{
  // Author
  // 

  inline
  const Author::NameOptional& Author::
  name () const
  {
    return this->name_;
  }

  inline
  Author::NameOptional& Author::
  name ()
  {
    return this->name_;
  }

  inline
  void Author::
  name (const NameType& x)
  {
    this->name_.set (x);
  }

  inline
  void Author::
  name (const NameOptional& x)
  {
    this->name_ = x;
  }

  inline
  void Author::
  name (::std::auto_ptr< NameType > x)
  {
    this->name_.set (x);
  }

  inline
  const Author::AboutOptional& Author::
  about () const
  {
    return this->about_;
  }

  inline
  Author::AboutOptional& Author::
  about ()
  {
    return this->about_;
  }

  inline
  void Author::
  about (const AboutType& x)
  {
    this->about_.set (x);
  }

  inline
  void Author::
  about (const AboutOptional& x)
  {
    this->about_ = x;
  }

  inline
  void Author::
  about (::std::auto_ptr< AboutType > x)
  {
    this->about_.set (x);
  }

  inline
  const Author::CommentsOptional& Author::
  comments () const
  {
    return this->comments_;
  }

  inline
  Author::CommentsOptional& Author::
  comments ()
  {
    return this->comments_;
  }

  inline
  void Author::
  comments (const CommentsType& x)
  {
    this->comments_.set (x);
  }

  inline
  void Author::
  comments (const CommentsOptional& x)
  {
    this->comments_ = x;
  }

  inline
  void Author::
  comments (::std::auto_ptr< CommentsType > x)
  {
    this->comments_.set (x);
  }

  inline
  const Author::WebsiteOptional& Author::
  website () const
  {
    return this->website_;
  }

  inline
  Author::WebsiteOptional& Author::
  website ()
  {
    return this->website_;
  }

  inline
  void Author::
  website (const WebsiteType& x)
  {
    this->website_.set (x);
  }

  inline
  void Author::
  website (const WebsiteOptional& x)
  {
    this->website_ = x;
  }

  inline
  void Author::
  website (::std::auto_ptr< WebsiteType > x)
  {
    this->website_.set (x);
  }

  inline
  const Author::EmailOptional& Author::
  email () const
  {
    return this->email_;
  }

  inline
  Author::EmailOptional& Author::
  email ()
  {
    return this->email_;
  }

  inline
  void Author::
  email (const EmailType& x)
  {
    this->email_.set (x);
  }

  inline
  void Author::
  email (const EmailOptional& x)
  {
    this->email_ = x;
  }

  inline
  void Author::
  email (::std::auto_ptr< EmailType > x)
  {
    this->email_.set (x);
  }

  inline
  const Author::InfosOptional& Author::
  infos () const
  {
    return this->infos_;
  }

  inline
  Author::InfosOptional& Author::
  infos ()
  {
    return this->infos_;
  }

  inline
  void Author::
  infos (const InfosType& x)
  {
    this->infos_.set (x);
  }

  inline
  void Author::
  infos (const InfosOptional& x)
  {
    this->infos_ = x;
  }

  inline
  void Author::
  infos (::std::auto_ptr< InfosType > x)
  {
    this->infos_.set (x);
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__AUTHOR_INL
