#include "Application.hpp"

#include "util/Log.hpp"

int main( int arg_count, char** arg_array )
{
	// TODO : add exception handling here
	aosd::Application app( arg_count, arg_array );
	auto result = app.run();

	return result;
}