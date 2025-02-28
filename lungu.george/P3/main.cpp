#include "lungu.h"

int main(int argc, char *argv[])
{
	if (!lungu::validateArguments(argc, argv))
	{
		return 1;
	}
	int taskNumber = std::stoi(argv[1]);
	std::string inputFilename = argv[2];
	std::string outputFilename = argv[3];
	try
	{
		if (taskNumber == 1)
		{
			lungu::processFixedSizeMatrix(inputFilename, outputFilename);
		}
		else if (taskNumber == 2)
		{
			lungu::processDynamicMatrix(inputFilename, outputFilename);
		}
		else
		{
			std::cerr << "Invalid task number: " << taskNumber << std::endl;
			return 1;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 2;
	}


	return 0;
}
