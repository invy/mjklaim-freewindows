#include "core/Sequence.hpp"

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

#include "util/Assert.hpp"

#include "aoslcpp/aosl/aosl.hpp"

#include "core/Project.hpp"

#include "Paths.hpp"

namespace aosd
{
namespace core
{

	namespace
	{

		std::unique_ptr< aosl::Sequence > create_empty_sequence( const SequenceInfos& infos )
		{
			std::auto_ptr<aosl::List_resource> resources ( new aosl::Library::ResourcesType() );
			std::auto_ptr<aosl::Library> library( new aosl::Library( resources ) );
			
			std::auto_ptr<aosl::Spatial_area> area( new aosl::Canvas::AreaType );
			area->x( infos.canvas_width );
			area->y( infos.canvas_height );
			area->z( 0 );

			std::auto_ptr<aosl::List_object> objects( new aosl::Canvas::ObjectsType );
			std::auto_ptr<aosl::Canvas> canvas( new aosl::Canvas( area, objects ) );

			std::auto_ptr<aosl::Navigation> navigation( new aosl::Navigation() );
			std::auto_ptr<aosl::List_move> moves( new aosl::List_move() );
			
			const std::string root_stage_id= "stage_0";
			std::auto_ptr<aosl::Stage> root_stage( new aosl::Stage( aosl::Stage_id(root_stage_id) ) );
			
			std::auto_ptr<aosl::List_stage> stages( new aosl::List_stage() );
			stages->stage().push_back( root_stage );

			std::auto_ptr<aosl::Story> story( new aosl::Story( stages, moves, aosl::Stage_ref(root_stage_id) ) );

			return std::unique_ptr< aosl::Sequence >( new aosl::Sequence( library, canvas, story, infos.name ) );
		}

	}
	
	Sequence::Sequence( Project& project, const SequenceInfos& infos )
		: m_project( project )
		, m_name( infos.name )
		, m_location( infos.location )
		, m_sequence( create_empty_sequence( infos ) )
	{
		
	}

	Sequence::Sequence( Project& project, const boost::filesystem::path sequence_file_path )
		: m_project( project )
		, m_location( sequence_file_path )
	{
		xml_schema::Properties properties;
		properties.schema_location( "artofsequence.org/aosl/1.0", path::AOSL_XSD_FILE.string() );

		boost::filesystem::ifstream filestream( full_location() );
		try
		{
			auto sequence = aosl::parse_sequence( filestream, 0, properties );
			m_sequence.reset( sequence.release() );
		}
		catch( const ::xsd::cxx::tree::parsing< char >& e )
		{
			AOSD_LOG_ERROR << e.what() << "\nDiagnostic : ";
			
			std::for_each( e.diagnostics().begin(), e.diagnostics().end(), []( const xsd::cxx::tree::error<char>& err )
			{
				AOSD_LOG_ERROR << "\n " << err;
			});
			
		}
		
		if( m_sequence )
		{
			m_name = m_sequence->name();
		}
	}

	Sequence::~Sequence()
	{

	}

	bool Sequence::save()
	{
		const auto sequence_file_path = full_location();
		const auto sequence_directory = sequence_file_path.parent_path();
		if( ! boost::filesystem::is_directory( sequence_directory ) )
		{
			boost::filesystem::create_directories( sequence_directory );
		}

		xml_schema::NamespaceInfomap namespace_infos;
		namespace_infos["aos"].name = "artofsequence.org/aosl/1.0";

		boost::filesystem::ofstream filestream( sequence_file_path );
		aosl::serialize_sequence( filestream, *m_sequence, namespace_infos );
		
		return true;
	}

	boost::filesystem::path Sequence::full_location() const
	{
		return m_project.directory_path() / location();
	}


}
}