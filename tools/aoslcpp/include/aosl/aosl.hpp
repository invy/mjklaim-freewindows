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
 * @brief Generated from aosl.xsd.
 */

#ifndef AOSLCPP_AOSL__AOSL_HPP
#define AOSLCPP_AOSL__AOSL_HPP

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

#include "aosl/aosl_forward.hpp"

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

#include "aosl/unit_space.hpp"

#include "aosl/unit_time.hpp"

#include "aosl/unit_stream.hpp"

#include "aosl/value_percent.hpp"

#include "aosl/angle.hpp"

#include "aosl/angle_type.hpp"

#include "aosl/vector.hpp"

#include "aosl/rotation.hpp"

#include "aosl/box.hpp"

#include "aosl/transformation.hpp"

#include "aosl/referential.hpp"

#include "aosl/axis_origin_x.hpp"

#include "aosl/axis_positive_x.hpp"

#include "aosl/axis_x.hpp"

#include "aosl/axis_origin_y.hpp"

#include "aosl/axis_positive_y.hpp"

#include "aosl/axis_y.hpp"

#include "aosl/axis_origin_z.hpp"

#include "aosl/axis_positive_z.hpp"

#include "aosl/axis_z.hpp"

#include "aosl/coordinate_system.hpp"

#include "aosl/spatial_area.hpp"

#include "aosl/source_uri.hpp"

#include "aosl/extension.hpp"

#include "aosl/name.hpp"

#include "aosl/email.hpp"

#include "aosl/version.hpp"

#include "aosl/property.hpp"

#include "aosl/controller.hpp"

#include "aosl/activation.hpp"

#include "aosl/script.hpp"

#include "aosl/sequence.hpp"

#include "aosl/meta.hpp"

#include "aosl/library.hpp"

#include "aosl/canvas.hpp"

#include "aosl/story.hpp"

#include "aosl/author.hpp"

#include "aosl/list_author.hpp"

#include "aosl/target.hpp"

#include "aosl/list_target.hpp"

#include "aosl/resource_type.hpp"

#include "aosl/resource_type_generic.hpp"

#include "aosl/resource_type_specific.hpp"

#include "aosl/resource.hpp"

#include "aosl/list_resource.hpp"

#include "aosl/library_include.hpp"

#include "aosl/list_include.hpp"

#include "aosl/layer.hpp"

#include "aosl/list_layer.hpp"

#include "aosl/properties_stream_object.hpp"

#include "aosl/properties_graphic_object.hpp"

#include "aosl/properties_interactive_object.hpp"

#include "aosl/object.hpp"

#include "aosl/list_object.hpp"

#include "aosl/object_special.hpp"

#include "aosl/object_sprite.hpp"

#include "aosl/object_audio.hpp"

#include "aosl/object_video.hpp"

#include "aosl/object_interactive.hpp"

#include "aosl/stage.hpp"

#include "aosl/list_stage.hpp"

#include "aosl/move.hpp"

#include "aosl/list_move.hpp"

#include "aosl/change.hpp"

#include "aosl/change_type_generic.hpp"

#include "aosl/change_type_specific.hpp"

#include "aosl/change_type.hpp"

#include "aosl/list_change.hpp"

#include "aosl/change_special.hpp"

#include "aosl/change_activate.hpp"

#include "aosl/change_deactivate.hpp"

#include "aosl/change_switch.hpp"

#include "aosl/change_transform_base.hpp"

#include "aosl/change_transform.hpp"

#include "aosl/effect.hpp"

#include "aosl/list_effect.hpp"

#include "aosl/navigation.hpp"

#include "aosl/event.hpp"

#include "aosl/event_type.hpp"

#include "aosl/event_signal_base.hpp"

#include "aosl/event_signal.hpp"

#include "aosl/event_input_base.hpp"

#include "aosl/event_input.hpp"

#include "aosl/event_selection_base.hpp"

#include "aosl/event_selection.hpp"

#include "aosl/signal_source.hpp"

#include "aosl/input_key.hpp"

#include "aosl/input_value.hpp"

#include "aosl/unique_id.hpp"

#include "aosl/stage_id.hpp"

#include "aosl/move_id.hpp"

#include "aosl/layer_id.hpp"

#include "aosl/resource_id.hpp"

#include "aosl/object_id.hpp"

#include "aosl/unique_ref.hpp"

#include "aosl/stage_ref.hpp"

#include "aosl/resource_ref.hpp"

#include "aosl/target_move_ref.hpp"

#include "aosl/special_move_ref.hpp"

#include "aosl/move_ref.hpp"

#include "aosl/target_layer_ref.hpp"

#include "aosl/special_layer_ref.hpp"

#include "aosl/layer_ref.hpp"

#include "aosl/target_object_ref.hpp"

#include "aosl/special_object_ref.hpp"

#include "aosl/object_ref.hpp"

#undef XSD_DONT_INCLUDE_INLINE
#else

#include "aosl/unit_space.hpp"

#include "aosl/unit_time.hpp"

#include "aosl/unit_stream.hpp"

#include "aosl/value_percent.hpp"

#include "aosl/angle.hpp"

#include "aosl/angle_type.hpp"

#include "aosl/vector.hpp"

#include "aosl/rotation.hpp"

#include "aosl/box.hpp"

#include "aosl/transformation.hpp"

#include "aosl/referential.hpp"

#include "aosl/axis_origin_x.hpp"

#include "aosl/axis_positive_x.hpp"

#include "aosl/axis_x.hpp"

#include "aosl/axis_origin_y.hpp"

#include "aosl/axis_positive_y.hpp"

#include "aosl/axis_y.hpp"

#include "aosl/axis_origin_z.hpp"

#include "aosl/axis_positive_z.hpp"

#include "aosl/axis_z.hpp"

#include "aosl/coordinate_system.hpp"

#include "aosl/spatial_area.hpp"

#include "aosl/source_uri.hpp"

#include "aosl/extension.hpp"

#include "aosl/name.hpp"

#include "aosl/email.hpp"

#include "aosl/version.hpp"

#include "aosl/property.hpp"

#include "aosl/controller.hpp"

#include "aosl/activation.hpp"

#include "aosl/script.hpp"

#include "aosl/sequence.hpp"

#include "aosl/meta.hpp"

#include "aosl/library.hpp"

#include "aosl/canvas.hpp"

#include "aosl/story.hpp"

#include "aosl/author.hpp"

#include "aosl/list_author.hpp"

#include "aosl/target.hpp"

#include "aosl/list_target.hpp"

#include "aosl/resource_type.hpp"

#include "aosl/resource_type_generic.hpp"

#include "aosl/resource_type_specific.hpp"

#include "aosl/resource.hpp"

#include "aosl/list_resource.hpp"

#include "aosl/library_include.hpp"

#include "aosl/list_include.hpp"

#include "aosl/layer.hpp"

#include "aosl/list_layer.hpp"

#include "aosl/properties_stream_object.hpp"

#include "aosl/properties_graphic_object.hpp"

#include "aosl/properties_interactive_object.hpp"

#include "aosl/object.hpp"

#include "aosl/list_object.hpp"

#include "aosl/object_special.hpp"

#include "aosl/object_sprite.hpp"

#include "aosl/object_audio.hpp"

#include "aosl/object_video.hpp"

#include "aosl/object_interactive.hpp"

#include "aosl/stage.hpp"

#include "aosl/list_stage.hpp"

#include "aosl/move.hpp"

#include "aosl/list_move.hpp"

#include "aosl/change.hpp"

#include "aosl/change_type_generic.hpp"

#include "aosl/change_type_specific.hpp"

#include "aosl/change_type.hpp"

#include "aosl/list_change.hpp"

#include "aosl/change_special.hpp"

#include "aosl/change_activate.hpp"

#include "aosl/change_deactivate.hpp"

#include "aosl/change_switch.hpp"

#include "aosl/change_transform_base.hpp"

#include "aosl/change_transform.hpp"

#include "aosl/effect.hpp"

#include "aosl/list_effect.hpp"

#include "aosl/navigation.hpp"

#include "aosl/event.hpp"

#include "aosl/event_type.hpp"

#include "aosl/event_signal_base.hpp"

#include "aosl/event_signal.hpp"

#include "aosl/event_input_base.hpp"

#include "aosl/event_input.hpp"

#include "aosl/event_selection_base.hpp"

#include "aosl/event_selection.hpp"

#include "aosl/signal_source.hpp"

#include "aosl/input_key.hpp"

#include "aosl/input_value.hpp"

#include "aosl/unique_id.hpp"

#include "aosl/stage_id.hpp"

#include "aosl/move_id.hpp"

#include "aosl/layer_id.hpp"

#include "aosl/resource_id.hpp"

#include "aosl/object_id.hpp"

#include "aosl/unique_ref.hpp"

#include "aosl/stage_ref.hpp"

#include "aosl/resource_ref.hpp"

#include "aosl/target_move_ref.hpp"

#include "aosl/special_move_ref.hpp"

#include "aosl/move_ref.hpp"

#include "aosl/target_layer_ref.hpp"

#include "aosl/special_layer_ref.hpp"

#include "aosl/layer_ref.hpp"

#include "aosl/target_object_ref.hpp"

#include "aosl/special_object_ref.hpp"

#include "aosl/object_ref.hpp"

#endif // XSD_DONT_INCLUDE_INLINE

/**
 * @brief C++ namespace for the %artofsequence.org/aosl/1.0
 * schema namespace.
 */
namespace aosl
{
}

#ifndef XSD_DONT_INCLUDE_INLINE

#include "aosl/unit_space.inl"

#include "aosl/unit_time.inl"

#include "aosl/unit_stream.inl"

#include "aosl/value_percent.inl"

#include "aosl/angle.inl"

#include "aosl/angle_type.inl"

#include "aosl/vector.inl"

#include "aosl/rotation.inl"

#include "aosl/box.inl"

#include "aosl/transformation.inl"

#include "aosl/referential.inl"

#include "aosl/axis_origin_x.inl"

#include "aosl/axis_positive_x.inl"

#include "aosl/axis_x.inl"

#include "aosl/axis_origin_y.inl"

#include "aosl/axis_positive_y.inl"

#include "aosl/axis_y.inl"

#include "aosl/axis_origin_z.inl"

#include "aosl/axis_positive_z.inl"

#include "aosl/axis_z.inl"

#include "aosl/coordinate_system.inl"

#include "aosl/spatial_area.inl"

#include "aosl/source_uri.inl"

#include "aosl/extension.inl"

#include "aosl/name.inl"

#include "aosl/email.inl"

#include "aosl/version.inl"

#include "aosl/property.inl"

#include "aosl/controller.inl"

#include "aosl/activation.inl"

#include "aosl/script.inl"

#include "aosl/sequence.inl"

#include "aosl/meta.inl"

#include "aosl/library.inl"

#include "aosl/canvas.inl"

#include "aosl/story.inl"

#include "aosl/author.inl"

#include "aosl/list_author.inl"

#include "aosl/target.inl"

#include "aosl/list_target.inl"

#include "aosl/resource_type.inl"

#include "aosl/resource_type_generic.inl"

#include "aosl/resource_type_specific.inl"

#include "aosl/resource.inl"

#include "aosl/list_resource.inl"

#include "aosl/library_include.inl"

#include "aosl/list_include.inl"

#include "aosl/layer.inl"

#include "aosl/list_layer.inl"

#include "aosl/properties_stream_object.inl"

#include "aosl/properties_graphic_object.inl"

#include "aosl/properties_interactive_object.inl"

#include "aosl/object.inl"

#include "aosl/list_object.inl"

#include "aosl/object_special.inl"

#include "aosl/object_sprite.inl"

#include "aosl/object_audio.inl"

#include "aosl/object_video.inl"

#include "aosl/object_interactive.inl"

#include "aosl/stage.inl"

#include "aosl/list_stage.inl"

#include "aosl/move.inl"

#include "aosl/list_move.inl"

#include "aosl/change.inl"

#include "aosl/change_type_generic.inl"

#include "aosl/change_type_specific.inl"

#include "aosl/change_type.inl"

#include "aosl/list_change.inl"

#include "aosl/change_special.inl"

#include "aosl/change_activate.inl"

#include "aosl/change_deactivate.inl"

#include "aosl/change_switch.inl"

#include "aosl/change_transform_base.inl"

#include "aosl/change_transform.inl"

#include "aosl/effect.inl"

#include "aosl/list_effect.inl"

#include "aosl/navigation.inl"

#include "aosl/event.inl"

#include "aosl/event_type.inl"

#include "aosl/event_signal_base.inl"

#include "aosl/event_signal.inl"

#include "aosl/event_input_base.inl"

#include "aosl/event_input.inl"

#include "aosl/event_selection_base.inl"

#include "aosl/event_selection.inl"

#include "aosl/signal_source.inl"

#include "aosl/input_key.inl"

#include "aosl/input_value.inl"

#include "aosl/unique_id.inl"

#include "aosl/stage_id.inl"

#include "aosl/move_id.inl"

#include "aosl/layer_id.inl"

#include "aosl/resource_id.inl"

#include "aosl/object_id.inl"

#include "aosl/unique_ref.inl"

#include "aosl/stage_ref.inl"

#include "aosl/resource_ref.inl"

#include "aosl/target_move_ref.inl"

#include "aosl/special_move_ref.inl"

#include "aosl/move_ref.inl"

#include "aosl/target_layer_ref.inl"

#include "aosl/special_layer_ref.inl"

#include "aosl/layer_ref.inl"

#include "aosl/target_object_ref.inl"

#include "aosl/special_object_ref.inl"

#include "aosl/object_ref.inl"

#endif // XSD_DONT_INCLUDE_INLINE

#include <iosfwd>

namespace aosl
{
}

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace aosl
{
  /**
   * @name Parsing functions for the %sequence document root.
   *
   * The root element for a Sequence.
   * In a full AOSL file, this should be the only root object.
   */
  //@{

  /**
   * @brief Parse a URI or a local file.
   *
   * @param uri A URI or a local file name.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function uses exceptions to report parsing errors.
   */
  ::std::auto_ptr< ::aosl::Sequence >
  parse_sequence (const ::std::string& uri,
                  ::xml_schema::Flags f = 0,
                  const ::xml_schema::Properties& p = ::xml_schema::Properties ());

  /**
   * @brief Parse a URI or a local file with an error handler.
   *
   * @param uri A URI or a local file name.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  ::std::auto_ptr< ::aosl::Sequence >
  parse_sequence (const ::std::string& uri,
                  ::xml_schema::ErrorHandler& eh,
                  ::xml_schema::Flags f = 0,
                  const ::xml_schema::Properties& p = ::xml_schema::Properties ());

  /**
   * @brief Parse a URI or a local file with a Xerces-C++ DOM error
   * handler.
   *
   * @param uri A URI or a local file name.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  ::std::auto_ptr< ::aosl::Sequence >
  parse_sequence (const ::std::string& uri,
                  ::xercesc::DOMErrorHandler& eh,
                  ::xml_schema::Flags f = 0,
                  const ::xml_schema::Properties& p = ::xml_schema::Properties ());

  /**
   * @brief Parse a standard input stream.
   *
   * @param is A standrad input stream.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function uses exceptions to report parsing errors.
   */
  ::std::auto_ptr< ::aosl::Sequence >
  parse_sequence (::std::istream& is,
                  ::xml_schema::Flags f = 0,
                  const ::xml_schema::Properties& p = ::xml_schema::Properties ());

  /**
   * @brief Parse a standard input stream with an error handler.
   *
   * @param is A standrad input stream.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  ::std::auto_ptr< ::aosl::Sequence >
  parse_sequence (::std::istream& is,
                  ::xml_schema::ErrorHandler& eh,
                  ::xml_schema::Flags f = 0,
                  const ::xml_schema::Properties& p = ::xml_schema::Properties ());

  /**
   * @brief Parse a standard input stream with a Xerces-C++ DOM error
   * handler.
   *
   * @param is A standrad input stream.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  ::std::auto_ptr< ::aosl::Sequence >
  parse_sequence (::std::istream& is,
                  ::xercesc::DOMErrorHandler& eh,
                  ::xml_schema::Flags f = 0,
                  const ::xml_schema::Properties& p = ::xml_schema::Properties ());

  /**
   * @brief Parse a standard input stream with a resource id.
   *
   * @param is A standrad input stream.
   * @param id A resource id.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * The resource id is used to identify the document being parsed in
   * diagnostics as well as to resolve relative paths.
   *
   * This function uses exceptions to report parsing errors.
   */
  ::std::auto_ptr< ::aosl::Sequence >
  parse_sequence (::std::istream& is,
                  const ::std::string& id,
                  ::xml_schema::Flags f = 0,
                  const ::xml_schema::Properties& p = ::xml_schema::Properties ());

  /**
   * @brief Parse a standard input stream with a resource id and an
   * error handler.
   *
   * @param is A standrad input stream.
   * @param id A resource id.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * The resource id is used to identify the document being parsed in
   * diagnostics as well as to resolve relative paths.
   *
   * This function reports parsing errors by calling the error handler.
   */
  ::std::auto_ptr< ::aosl::Sequence >
  parse_sequence (::std::istream& is,
                  const ::std::string& id,
                  ::xml_schema::ErrorHandler& eh,
                  ::xml_schema::Flags f = 0,
                  const ::xml_schema::Properties& p = ::xml_schema::Properties ());

  /**
   * @brief Parse a standard input stream with a resource id and a
   * Xerces-C++ DOM error handler.
   *
   * @param is A standrad input stream.
   * @param id A resource id.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * The resource id is used to identify the document being parsed in
   * diagnostics as well as to resolve relative paths.
   *
   * This function reports parsing errors by calling the error handler.
   */
  ::std::auto_ptr< ::aosl::Sequence >
  parse_sequence (::std::istream& is,
                  const ::std::string& id,
                  ::xercesc::DOMErrorHandler& eh,
                  ::xml_schema::Flags f = 0,
                  const ::xml_schema::Properties& p = ::xml_schema::Properties ());

  /**
   * @brief Parse a Xerces-C++ input source.
   *
   * @param is A Xerces-C++ input source.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function uses exceptions to report parsing errors.
   */
  ::std::auto_ptr< ::aosl::Sequence >
  parse_sequence (::xercesc::InputSource& is,
                  ::xml_schema::Flags f = 0,
                  const ::xml_schema::Properties& p = ::xml_schema::Properties ());

  /**
   * @brief Parse a Xerces-C++ input source with an error handler.
   *
   * @param is A Xerces-C++ input source.
   * @param eh An error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  ::std::auto_ptr< ::aosl::Sequence >
  parse_sequence (::xercesc::InputSource& is,
                  ::xml_schema::ErrorHandler& eh,
                  ::xml_schema::Flags f = 0,
                  const ::xml_schema::Properties& p = ::xml_schema::Properties ());

  /**
   * @brief Parse a Xerces-C++ input source with a Xerces-C++ DOM
   * error handler.
   *
   * @param is A Xerces-C++ input source.
   * @param eh A Xerces-C++ DOM error handler.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function reports parsing errors by calling the error handler.
   */
  ::std::auto_ptr< ::aosl::Sequence >
  parse_sequence (::xercesc::InputSource& is,
                  ::xercesc::DOMErrorHandler& eh,
                  ::xml_schema::Flags f = 0,
                  const ::xml_schema::Properties& p = ::xml_schema::Properties ());

  /**
   * @brief Parse a Xerces-C++ DOM document.
   *
   * @param d A Xerces-C++ DOM document.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   */
  ::std::auto_ptr< ::aosl::Sequence >
  parse_sequence (const ::xercesc::DOMDocument& d,
                  ::xml_schema::Flags f = 0,
                  const ::xml_schema::Properties& p = ::xml_schema::Properties ());

  /**
   * @brief Parse a Xerces-C++ DOM document.
   *
   * @param d A pointer to the Xerces-C++ DOM document.
   * @param f Parsing flags.
   * @param p Parsing properties. 
   * @return A pointer to the root of the object model.
   *
   * This function is normally used together with the keep_dom and
   * own_dom parsing flags to assign ownership of the DOM document
   * to the object model.
   */
  ::std::auto_ptr< ::aosl::Sequence >
  parse_sequence (::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >& d,
                  ::xml_schema::Flags f = 0,
                  const ::xml_schema::Properties& p = ::xml_schema::Properties ());

  //@}
}

#include <iosfwd>

#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/framework/XMLFormatter.hpp>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

namespace aosl
{
  /**
   * @name Serialization functions for the %sequence document root.
   *
   * The root element for a Sequence.
   * In a full AOSL file, this should be the only root object.
   */
  //@{

  /**
   * @brief Serialize to a standard output stream.
   *
   * @param os A standrad output stream.
   * @param x An object model to serialize.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function uses exceptions to report serialization errors.
   */
  void
  serialize_sequence (::std::ostream& os,
                      const ::aosl::Sequence& x, 
                      const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                      const ::std::string& e = "UTF-8",
                      ::xml_schema::Flags f = 0);

  /**
   * @brief Serialize to a standard output stream with an error handler.
   *
   * @param os A standrad output stream.
   * @param x An object model to serialize.
   * @param eh An error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  void
  serialize_sequence (::std::ostream& os,
                      const ::aosl::Sequence& x, 
                      ::xml_schema::ErrorHandler& eh,
                      const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                      const ::std::string& e = "UTF-8",
                      ::xml_schema::Flags f = 0);

  /**
   * @brief Serialize to a standard output stream with a Xerces-C++ DOM
   * error handler.
   *
   * @param os A standrad output stream.
   * @param x An object model to serialize.
   * @param eh A Xerces-C++ DOM error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  void
  serialize_sequence (::std::ostream& os,
                      const ::aosl::Sequence& x, 
                      ::xercesc::DOMErrorHandler& eh,
                      const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                      const ::std::string& e = "UTF-8",
                      ::xml_schema::Flags f = 0);

  /**
   * @brief Serialize to a Xerces-C++ XML format target.
   *
   * @param ft A Xerces-C++ XML format target.
   * @param x An object model to serialize.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function uses exceptions to report serialization errors.
   */
  void
  serialize_sequence (::xercesc::XMLFormatTarget& ft,
                      const ::aosl::Sequence& x, 
                      const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                      const ::std::string& e = "UTF-8",
                      ::xml_schema::Flags f = 0);

  /**
   * @brief Serialize to a Xerces-C++ XML format target with an error
   * handler.
   *
   * @param ft A Xerces-C++ XML format target.
   * @param x An object model to serialize.
   * @param eh An error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  void
  serialize_sequence (::xercesc::XMLFormatTarget& ft,
                      const ::aosl::Sequence& x, 
                      ::xml_schema::ErrorHandler& eh,
                      const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                      const ::std::string& e = "UTF-8",
                      ::xml_schema::Flags f = 0);

  /**
   * @brief Serialize to a Xerces-C++ XML format target with a
   * Xerces-C++ DOM error handler.
   *
   * @param ft A Xerces-C++ XML format target.
   * @param x An object model to serialize.
   * @param eh A Xerces-C++ DOM error handler.
   * @param m A namespace information map.
   * @param e A character encoding to produce XML in.
   * @param f Serialization flags.
   *
   * This function reports serialization errors by calling the error
   * handler.
   */
  void
  serialize_sequence (::xercesc::XMLFormatTarget& ft,
                      const ::aosl::Sequence& x, 
                      ::xercesc::DOMErrorHandler& eh,
                      const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                      const ::std::string& e = "UTF-8",
                      ::xml_schema::Flags f = 0);

  /**
   * @brief Serialize to an existing Xerces-C++ DOM document.
   *
   * @param d A Xerces-C++ DOM document.
   * @param x An object model to serialize.
   * @param f Serialization flags.
   *
   * Note that it is your responsibility to create the DOM document
   * with the correct root element as well as set the necessary
   * namespace mapping attributes.
   */
  void
  serialize_sequence (::xercesc::DOMDocument& d,
                      const ::aosl::Sequence& x,
                      ::xml_schema::Flags f = 0);

  /**
   * @brief Serialize to a new Xerces-C++ DOM document.
   *
   * @param x An object model to serialize.
   * @param m A namespace information map.
   * @param f Serialization flags.
   * @return A pointer to the new Xerces-C++ DOM document.
   */
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >
  serialize_sequence (const ::aosl::Sequence& x, 
                      const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                      ::xml_schema::Flags f = 0);

  //@}
}

#ifndef XSD_DONT_INCLUDE_INLINE
#include "aosl/aosl.inl"
#endif // XSD_DONT_INCLUDE_INLINE

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // AOSLCPP_AOSL__AOSL_HPP
