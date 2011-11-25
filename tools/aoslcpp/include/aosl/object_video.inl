// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__OBJECT_VIDEO_INL
#define AOSLCPP_AOSL__OBJECT_VIDEO_INL

// Begin prologue.
//
//
// End prologue.

#include "aosl/object.inl"

#include "aosl/properties_graphic_object.hpp"
#include "aosl/properties_graphic_object.inl"

#include "aosl/properties_stream_object.hpp"
#include "aosl/properties_stream_object.inl"

namespace aosl
{
  // Object_video
  // 

  inline
  const Object_video::GraphicType& Object_video::
  graphic () const
  {
    return this->graphic_.get ();
  }

  inline
  Object_video::GraphicType& Object_video::
  graphic ()
  {
    return this->graphic_.get ();
  }

  inline
  void Object_video::
  graphic (const GraphicType& x)
  {
    this->graphic_.set (x);
  }

  inline
  void Object_video::
  graphic (::std::auto_ptr< GraphicType > x)
  {
    this->graphic_.set (x);
  }

  inline
  ::std::auto_ptr< Object_video::GraphicType > Object_video::
  detach_graphic ()
  {
    return this->graphic_.detach ();
  }

  inline
  const Object_video::StreamType& Object_video::
  stream () const
  {
    return this->stream_.get ();
  }

  inline
  Object_video::StreamType& Object_video::
  stream ()
  {
    return this->stream_.get ();
  }

  inline
  void Object_video::
  stream (const StreamType& x)
  {
    this->stream_.set (x);
  }

  inline
  void Object_video::
  stream (::std::auto_ptr< StreamType > x)
  {
    this->stream_.set (x);
  }

  inline
  ::std::auto_ptr< Object_video::StreamType > Object_video::
  detach_stream ()
  {
    return this->stream_.detach ();
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__OBJECT_VIDEO_INL