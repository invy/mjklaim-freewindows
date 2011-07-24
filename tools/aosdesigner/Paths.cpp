#include "Paths.hpp"

namespace aosd
{
namespace path
{

	const bfs::path DEFAULT_PROJECTS_DIR	= "~/";
	const bfs::path PROJECT_INFO_FILE		= "./project.info";
	const bfs::path PROJECT_LIBRARY_DIR		= "./library/";
	const bfs::path PROJECT_LIBRARY_FILE	= PROJECT_LIBRARY_DIR / "library.aosl";
	const bfs::path PROJECT_META_FILE		= "./meta.aosl";
	const bfs::path PROJECT_SEQUENCES_DIR	= "./sequences/";
	
	bfs::path SEQUENCE_DIR( const std::string& sequence_codename )
	{
		// TODO : add some checks
		return PROJECT_SEQUENCES_DIR / sequence_codename;
	}

	bfs::path SEQUENCE_FILE( const std::string& sequence_codename )
	{
		// TODO : add some checks
		return SEQUENCE_DIR( sequence_codename ) / (sequence_codename + ".aosl" );
	}


}
}
