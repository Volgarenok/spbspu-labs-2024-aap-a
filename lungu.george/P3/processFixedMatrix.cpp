#include "lungu.h"

namespace lungu
{
	void processFixedSizeMatrix(const std::string &inputFilename, const std::string &outputFilename)
	{
		const int maxSize = 10000;
		int matrix[maxSize];
		auto [rows, cols] = readMatrixFromFile(inputFilename, matrix, maxSize);
		transformMatrix(matrix, rows, cols);
		writeMatrixToFile(outputFilename, matrix, rows, cols);
	}
}
