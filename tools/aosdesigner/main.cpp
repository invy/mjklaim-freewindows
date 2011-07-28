#include <memory>

#include "Application.hpp"
#include "util/Log.hpp"

int main( int arg_count, char** arg_array )
{
	// TODO : add basic (MSVC) memory leak checks

	// TODO : add exception handling here
	auto app = std::unique_ptr<aosd::Application>( new aosd::Application( arg_count, arg_array ) );
	auto result = app->run();

	return result;
}