#include "lungu.h"

namespace lungu
{
	bool validateArguments(int argc, char *argv[])
	{
		if (argc != 4)
		{
			std::cerr << ((argc < 4) ? "Not enough arguments.":"Too many arguments.\n");
			return 1;
		}
		std::string str_num = argv[1];
		for (char c : str_num)
		{
			if (!(std::isdigit(c)))
			{
                             std::cerr << "First parametr is not a number.\n";
			     return 1;
			}
		}
                int num = std::stoi(str_num);
		if (num != 1 && num != 2)
		{
		        std::cerr << "First parametr is out of range.\n";
			return 1;
		}
		return true;
	}

	std::pair<int, int> readMatrixFromFile(const std::string &filename, int *matrix, int maxSize)
	{
		std::ifstream file(filename);
		if (!file)
		{
			throw std::runtime_error("Could not open file: " + filename);
		}
		int rows, cols;
		file >> rows >> cols;

		if (rows <= 0 || cols <= 0 || (rows * cols) > maxSize)
		{
			throw std::runtime_error("Invalid matrix dimentions or size exceeds limit.\n");
		}
		for (int i = 0; i < (rows * cols); ++i)
		{
			if (!(file >> matrix[i]))
			{
				throw std::runtime_error("Invalid matrix data.\n");
			}
		}
		return {rows, cols};
	}


}
