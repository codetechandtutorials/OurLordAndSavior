#include "../../Adder/adder.h"
#include <cstdlib>
int main(int argc, char** argv)
{
	if (argc < 3) 	return -1; // invalid parameter count

	float cpp_add_value = atof(argv[1]) + atof(argv[2]);

    float adder_add_value = add(atof(argv[1]), atof(argv[2]));

	int return_value = (cpp_add_value == adder_add_value) ? EXIT_SUCCESS : EXIT_FAILURE; 

	return return_value;

}