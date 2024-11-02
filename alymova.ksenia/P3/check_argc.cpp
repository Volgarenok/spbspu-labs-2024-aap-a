#include "cmd_parameters.h"
#include <stdexcept>
void alymova::check_argc(int argc)
{
	if (argc - 1 > 3)
	{
		throw std::logic_error("Too many arguments");
	}
	if (argc - 1 < 3)
	{
		throw std::logic_error("Not  enough  arguments");
	}
}
