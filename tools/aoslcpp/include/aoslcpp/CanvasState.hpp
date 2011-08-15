#ifndef HGUARD_AOSLCPP_CANVASSTATE_HPP__
#define HGUARD_AOSLCPP_CANVASSTATE_HPP__
#pragma once

#include <vector>

#include "aosl/object_ref.hpp"
#include "aosl/canvas.hpp"

namespace aoslcpp
{
	/** Describe a state of a canvas.
	**/
	class CanvasState
	{
	public:

		explicit CanvasState( const aosl::Canvas& canvas );

		void activate( aosl::Object_ref object );
		void deactivate( aosl::Object_ref object );
		void switch_state( aosl::Object_ref object );
		
	private:

		aosl::Canvas m_canvas;

		std::vector< aosl::Object_ref > m_active_objects;
		std::vector< aosl::Object_ref > m_unactive_objects;
		
	};


}


#endif
