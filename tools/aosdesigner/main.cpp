#include "Application.hpp"

int main( int arg_count, char** arg_array )
{
    aosd::Application app( arg_count, arg_array );
    return app.exec();
}