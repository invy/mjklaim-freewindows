#include "Application.hpp"

#include <iostream>

int main( int arg_count, char** arg_array )
{
	std::cout << "Starting AOS Designer ... \n";

	aosd::Application app( arg_count, arg_array );
	auto result = app.exec();

	std::cout << "End of AOS Designer.";


	return result;
}