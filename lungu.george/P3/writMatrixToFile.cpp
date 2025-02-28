#include "lungu.h"

namespace lungu
{
	void writeMatrixToFile(const std::string &filename, const int *matrix, int rows, int cols)
	{
		std::ofstream file(filename);
		if (!file)
		{
			throw std::runtime_error("Could not open output file: " + filename);
		}

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				file << matrix[i * cols + j] << " ";
			}
			file << std::endl;
		}
	}
}
