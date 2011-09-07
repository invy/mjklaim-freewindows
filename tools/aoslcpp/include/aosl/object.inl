// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema
// to C++ data binding compiler, in the Proprietary License mode.
// You should have received a proprietary license from Code Synthesis
// Tools CC prior to generating this code. See the license text for
// conditions.
//

#ifndef AOSLCPP_AOSL__OBJECT_INL
#define AOSLCPP_AOSL__OBJECT_INL

// Begin prologue.
//
//
// End prologue.

#include "aosl/property.hpp"
#include "aosl/property.inl"

#include "aosl/extension.hpp"
#include "aosl/extension.inl"

#include "aosl/list_object.hpp"
#include "aosl/list_object.inl"

#include "aosl/object_id.hpp"
#include "aosl/object_id.inl"

#include "aosl/resource_ref.hpp"
#include "aosl/resource_ref.inl"

#include "aosl/layer_ref.hpp"
#include "aosl/layer_ref.inl"

namespace aosl
{
  // Object
  // 

  inline
  const Object::PropertiesOptional& Object::
  properties () const
  {
    return this->properties_;
  }

  inline
  Object::PropertiesOptional& Object::
  properties ()
  {
    return this->properties_;
  }

  inline
  void Object::
  properties (const PropertiesType& x)
  {
    this->properties_.set (x);
  }

  inline
  void Object::
  properties (const PropertiesOptional& x)
  {
    this->properties_ = x;
  }

  inline
  void Object::
  properties (::std::auto_ptr< PropertiesType > x)
  {
    this->properties_.set (x);
  }

  inline
  const Object::ExtensionOptional& Object::
  extension () const
  {
    return this->extension_;
  }

  inline
  Object::ExtensionOptional& Object::
  extension ()
  {
    return this->extension_;
  }

  inline
  void Object::
  extension (const ExtensionType& x)
  {
    this->extension_.set (x);
  }

  inline
  void Object::
  extension (const ExtensionOptional& x)
  {
    this->extension_ = x;
  }

  inline
  void Object::
  extension (::std::auto_ptr< ExtensionType > x)
  {
    this->extension_.set (x);
  }

  inline
  const Object::ChildrenOptional& Object::
  children () const
  {
    return this->children_;
  }

  inline
  Object::ChildrenOptional& Object::
  children ()
  {
    return this->children_;
  }

  inline
  void Object::
  children (const ChildrenType& x)
  {
    this->children_.set (x);
  }

  inline
  void Object::
  children (const ChildrenOptional& x)
  {
    this->children_ = x;
  }

  inline
  void Object::
  children (::std::auto_ptr< ChildrenType > x)
  {
    this->children_.set (x);
  }

  inline
  const Object::IdType& Object::
  id () const
  {
    return this->id_.get ();
  }

  inline
  Object::IdType& Object::
  id ()
  {
    return this->id_.get ();
  }

  inline
  void Object::
  id (const IdType& x)
  {
    this->id_.set (x);
  }

  inline
  void Object::
  id (::std::auto_ptr< IdType > x)
  {
    this->id_.set (x);
  }

  inline
  ::std::auto_ptr< Object::IdType > Object::
  detach_id ()
  {
    return this->id_.detach ();
  }

  inline
  const Object::ActiveType& Object::
  active () const
  {
    return this->active_.get ();
  }

  inline
  Object::ActiveType& Object::
  active ()
  {
    return this->active_.get ();
  }

  inline
  void Object::
  active (const ActiveType& x)
  {
    this->active_.set (x);
  }

  inline
  Object::ActiveType Object::
  active_default_value ()
  {
    return ActiveType (false);
  }

  inline
  const Object::ResourceOptional& Object::
  resource () const
  {
    return this->resource_;
  }

  inline
  Object::ResourceOptional& Object::
  resource ()
  {
    return this->resource_;
  }

  inline
  void Object::
  resource (const ResourceType& x)
  {
    this->resource_.set (x);
  }

  inline
  void Object::
  resource (const ResourceOptional& x)
  {
    this->resource_ = x;
  }

  inline
  void Object::
  resource (::std::auto_ptr< ResourceType > x)
  {
    this->resource_.set (x);
  }

  inline
  const Object::LayerOptional& Object::
  layer () const
  {
    return this->layer_;
  }

  inline
  Object::LayerOptional& Object::
  layer ()
  {
    return this->layer_;
  }

  inline
  void Object::
  layer (const LayerType& x)
  {
    this->layer_.set (x);
  }

  inline
  void Object::
  layer (const LayerOptional& x)
  {
    this->layer_ = x;
  }

  inline
  void Object::
  layer (::std::auto_ptr< LayerType > x)
  {
    this->layer_.set (x);
  }
}

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__OBJECT_INL
