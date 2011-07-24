#ifndef HGUARD_AOSD_CORE_PATHS_HPP__
#define HGUARD_AOSD_CORE_PATHS_HPP__
#pragma once

#include <boost/filesystem/path.hpp>

namespace aosd
{
namespace path
{
	namespace bfs = boost::filesystem;

	/// Default directory to look in when we start looking for project directories.
	extern const bfs::path DEFAULT_PROJECTS_DIR;

	/// Project infos file, defining the whole project.
	extern const bfs::path PROJECT_INFO_FILE;

	/// Common library directory where all it's resources will be contained.
	extern const bfs::path PROJECT_LIBRARY_DIR;

	/// Common library definition file.
	extern const bfs::path PROJECT_LIBRARY_FILE;

	/// Meta informations common to all the sequences.
	extern const bfs::path PROJECT_META_FILE;

	/// Directory containing the project's sequences.
	extern const bfs::path PROJECT_SEQUENCES_DIR;

	/// Generate the path of a sequence directory.
	bfs::path SEQUENCE_DIR( const std::string& sequence_codename );

	/// Generate the path of a sequence file definition.
	bfs::path SEQUENCE_FILE( const std::string& sequence_codename );

}
}


#endif
