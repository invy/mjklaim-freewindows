#ifndef HGUARD_AOSLCPP_CANVASSTATE_HPP__
#define HGUARD_AOSLCPP_CANVASSTATE_HPP__
#pragma once

#include <vector>

#include "aosl/object_ref.hpp"

namespace aosl { class Canvas; }

namespace aoslcpp
{
	/** Describe a state of a canvas.
	**/
	class CanvasState
	{
	public:

		CanvasState( const aosl::Canvas& canvas );

		void activate( aosl::Object_ref object );
		void deactivate( aosl::Object_ref object );

		
	private:

		const aosl::Canvas& m_canvas;

		std::vector< aosl::Object_ref > m_active_objects;
		std::vector< aosl::Object_ref > m_unactive_objects;

	};


}


#endif
