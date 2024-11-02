#include "matrix.h"
#include <cstddef>
int* alymova::create_dynamic(size_t rows, size_t cols)
{
	int* matrix = new int[rows * cols];
	return matrix;
}
