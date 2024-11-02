#include "cmd_parameters.h"
#include <iostream>
#include <cstddef>
void alymova::print_matrix(std::ostream& output, int* matrix, size_t rows, size_t cols)
{
	output << matrix[0];
	for (size_t i = 1; i < rows * cols; i++)
	{
		output << " " << matrix[i];
	}
}
