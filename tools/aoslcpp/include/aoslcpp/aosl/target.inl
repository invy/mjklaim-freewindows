// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__TARGET_INL
#define AOSLCPP_AOSL__TARGET_INL

// Begin prologue.
//
//
// End prologue.

#include "aoslcpp/aosl/extension.hpp"
#include "aoslcpp/aosl/extension.inl"

namespace aosl
{
  // Target
  // 

  inline
  const Target::ConfigOptional& Target::
  config () const
  {
    return this->config_;
  }

  inline
  Target::ConfigOptional& Target::
  config ()
  {
    return this->config_;
  }

  inline
  void Target::
  config (const ConfigType& x)
  {
    this->config_.set (x);
  }

  inline
  void Target::
  config (const ConfigOptional& x)
  {
    this->config_ = x;
  }

  inline
  void Target::
  config (::std::auto_ptr< ConfigType > x)
  {
    this->config_.set (x);
  }

  inline
  const Target::PlayerOptional& Target::
  player () const
  {
    return this->player_;
  }

  inline
  Target::PlayerOptional& Target::
  player ()
  {
    return this->player_;
  }

  inline
  void Target::
  player (const PlayerType& x)
  {
    this->player_.set (x);
  }

  inline
  void Target::
  player (const PlayerOptional& x)
  {
    this->player_ = x;
  }

  inline
  void Target::
  player (::std::auto_ptr< PlayerType > x)
  {
    this->player_.set (x);
  }

  inline
  const Target::PlatformOptional& Target::
  platform () const
  {
    return this->platform_;
  }

  inline
  Target::PlatformOptional& Target::
  platform ()
  {
    return this->platform_;
  }

  inline
  void Target::
  platform (const PlatformType& x)
  {
    this->platform_.set (x);
  }

  inline
  void Target::
  platform (const PlatformOptional& x)
  {
    this->platform_ = x;
  }

  inline
  void Target::
  platform (::std::auto_ptr< PlatformType > x)
  {
    this->platform_.set (x);
  }

  inline
  const Target::WebsiteOptional& Target::
  website () const
  {
    return this->website_;
  }

  inline
  Target::WebsiteOptional& Target::
  website ()
  {
    return this->website_;
  }

  inline
  void Target::
  website (const WebsiteType& x)
  {
    this->website_.set (x);
  }

  inline
  void Target::
  website (const WebsiteOptional& x)
  {
    this->website_ = x;
  }

  inline
  void Target::
  website (::std::auto_ptr< WebsiteType > x)
  {
    this->website_.set (x);
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__TARGET_INL
