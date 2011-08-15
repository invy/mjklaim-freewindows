#ifndef HGUARD_AOSLCPP_CANVASSTATE_HPP__
#define HGUARD_AOSLCPP_CANVASSTATE_HPP__
#pragma once

#include <vector>
#include <functional>

#include "aosl/object_ref.hpp"
#include "aosl/canvas.hpp"

namespace aosl { class Change; }

namespace aoslcpp
{
	/** Describe a state of a canvas.
	**/
	class CanvasState
	{
	public:

		explicit CanvasState( const aosl::Canvas& canvas );

		void activate( const aosl::Object_ref object_ref );
		void deactivate( const aosl::Object_ref object_ref );
		void switch_state( const aosl::Object_ref object_ref );

		void execute( const aosl::Change& change );
		
	private:

		aosl::Canvas m_canvas;

	};


}


#endif
