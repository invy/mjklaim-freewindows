#include "aoslcpp/algorithm/find.hpp"

#include "aosl/aosl.hpp"

namespace aoslcpp
{
	optional<aosl::Object> find_object( const aosl::List_object& list_objects, const aosl::Object_ref object_ref )
	{
		const auto& objects = list_objects.object();

		if( objects.empty() )
			return optional<aosl::Object>();

		for( auto it = objects.begin(); it != objects.end(); ++it )
		{
			const auto& object = *it;
			if( object.id() == object_ref )
				return object;

			auto child_found = find_object( object, object_ref );
			if( child_found )
				return child_found;
		}

		return optional<aosl::Object>();
	}

	optional<aosl::Object> find_object( const aosl::Canvas& canvas, const aosl::Object_ref object_ref )
	{
		return find_object( canvas.objects(), object_ref );
	}

	
	optional<aosl::Object> find_object( const aosl::Object& parent, const aosl::Object_ref object_ref )
	{
		return parent.children() ? find_object( *parent.children(), object_ref ) : optional<aosl::Object>();
	}

	optional<aosl::Move> find_move( const aosl::Story& story, const aosl::Move_ref move_ref )
	{
		const auto& moves = story.moves().move();

		if( moves.empty() )
			return optional<aosl::Move>();

		auto find_it = std::find_if( moves.begin(), moves.end(), [&]( const aosl::Move& move ){ return move.id() && *move.id() == move_ref; });

		return find_it != moves.end() ? *find_it : optional<aosl::Move>();
	}

	optional<aosl::Stage> find_stage( const aosl::Story& story, const aosl::Stage_ref stage_ref )
	{
		const auto& stages = story.stages().stage();

		if( stages.empty() )
			return optional<aosl::Stage>();

		auto find_it = std::find_if( stages.begin(), stages.end(), [&]( const aosl::Stage& stage ){ return stage.id() == stage_ref; });

		return find_it != stages.end() ? *find_it : optional<aosl::Stage>();
	}

}