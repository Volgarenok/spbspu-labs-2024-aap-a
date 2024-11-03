#include "matrix.h"
#include <cstddef>
int alymova::check_size(size_t rows, size_t cols)
{
    if (rows == 0 && cols == 0)
    {
        return 1;
    }
    if ((rows * cols == 0) && (rows + cols != 0))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
