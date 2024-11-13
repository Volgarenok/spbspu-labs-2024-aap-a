#include <iostream>
#include <cstdlib>
#include "stream.h"
#include "matrixProcessing.h"

int main(int argc, char** argv)
{
    if (argc < 4)
    {
        std::cerr << "Not enough arguments\n";
        return 1;
    }
    if (argc > 4)
    {
        std::cerr << "Too many arguments\n";
        return 1;
    }
    char* pEnd = nullptr;
    const long arrayType = std::strtol(argv[1], &pEnd, 10);

    if (*pEnd != '\0')
    {
        std::cerr << "First parameter is not a number\n";
        return 1;
    }
    if ((arrayType == 1 || arrayType == 2) == false)
    {
        std::cerr << "First parameter is out of range\n";
        return 1;
    }
    int columns = 0, rows = 0;
    std::ifstream input(argv[2]);
    input >> columns >> rows;
    if (!input)
    {
        std::cerr << "Rows or columns are not a number\n";
        return 2;
    }
    if (columns < 0 || rows < 0)
    {
        std::cerr << "Rows and columns must be greater than 0\n";
        return 2;
    }
    std::ofstream output(argv[3]);
    if (rows == 0 || columns == 0)
    {
        output << "0\n";
        return 0;
    }
    size_t read = 0;
    int* matrix = nullptr;
    if (arrayType == 1)
    {
        int matrixStatic[1000] = {};
        matrix = matrixStatic;
    }
    else if (arrayType == 2)
    {
        int* matrixDynamic = nullptr;
        try
        {
            matrixDynamic = new int[columns * rows];
        }
        catch (const std::bad_alloc& e)
        {
            delete[] matrixDynamic;
            delete[] matrix;
            std::cerr << "Out of memory\n";
            return 2;
        }
        matrix = matrixDynamic;
    }
    if (!(balashov::inputMatrix(input, matrix, columns, rows, read)))
    {
        std::cerr << "Invalid input\n";
        return 2;
        delete[] matrix;
    }
    output << balashov::calculateMinSumSideDiagonal(matrix, columns, rows) << "\n";
    delete[] matrix;
}
