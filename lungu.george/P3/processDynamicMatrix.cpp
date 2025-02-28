#include "lungu.h"

namespace lungu
{
	void processDynamicMatrix(const std::string &inputFilename, const std::string &outputFilename)
	{
		std::ifstream file(inputFilename);
		if (!file)
		{
			throw std::runtime_error("Could not open file: " + inputFilename);
		}
		
		int rows, cols;
		file >> rows >> cols;
		if (rows <= 0 || cols <= 0)
		{
			throw std::runtime_error("Invalid matrix dimentions.\n");
		}

		int *matrix = new int[rows * cols];
		for (int i = 0; i < rows * cols; ++i)
		{
			if (!(file >> matrix[i]))
			{
				delete[] matrix;
				throw std::runtime_error("Invalid matrix data");
			}
		}

		transformMatrix(matrix, rows, cols);
		writeMatrixToFile(outputFilename, matrix, rows, cols);

		delete[] matrix;
	}
}
