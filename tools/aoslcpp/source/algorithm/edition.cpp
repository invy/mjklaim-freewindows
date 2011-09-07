#include "aoslcpp/algorithm/edition.hpp"

#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "aosl/aosl.hpp"

namespace aoslcpp
{
	const std::string DEFAULT_SEQUENCE_ID_PREFIX( "sequence-" );
	const std::string DEFAULT_FIRST_STAGE_NAME( "stage_0" );

	std::unique_ptr< aosl::Sequence > make_empty_sequence( const std::string& sequence_name
														, const double canvas_width, const double canvas_height, const double canvas_depth
														, const std::string& sequence_id
														, const std::string& fist_stage_id
														)
	{
		std::auto_ptr<aosl::List_resource> resources ( new aosl::Library::ResourcesType() );
		std::auto_ptr<aosl::Library> library( new aosl::Library( resources ) );

		std::auto_ptr<aosl::Spatial_area> area( new aosl::Canvas::AreaType );
		area->x( canvas_width );
		area->y( canvas_height );
		area->z( canvas_depth );

		std::auto_ptr<aosl::List_object> objects( new aosl::Canvas::ObjectsType );
		std::auto_ptr<aosl::Canvas> canvas( new aosl::Canvas( area, objects ) );

		std::auto_ptr<aosl::Navigation> navigation( new aosl::Navigation() );
		std::auto_ptr<aosl::List_move> moves( new aosl::List_move() );

		const std::string root_stage_id= fist_stage_id.empty() ? DEFAULT_FIRST_STAGE_NAME : fist_stage_id;
		std::auto_ptr<aosl::Stage> root_stage( new aosl::Stage( aosl::Stage_id(root_stage_id) ) );

		std::auto_ptr<aosl::List_stage> stages( new aosl::List_stage() );
		stages->stage().push_back( root_stage );

		std::auto_ptr<aosl::Story> story( new aosl::Story( stages, moves, aosl::Stage_ref(root_stage_id) ) );

		aosl::Unique_id unique_id( sequence_id );

		if( sequence_id.empty() )
		{
			static boost::uuids::random_generator new_sequence_id_generator;
			unique_id = aosl::Unique_id( DEFAULT_SEQUENCE_ID_PREFIX + to_string( new_sequence_id_generator() ) );
		}
		
		return std::unique_ptr< aosl::Sequence >( new aosl::Sequence( library, canvas, story, sequence_name, unique_id ) );
	}

}