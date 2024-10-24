#include <iostream>

int main()
{
	double start = 0.0, finish = 0.0;
	int max_summand = 0;
	std::cin >> start >> finish >> max_summand;
	if (!std::cin.good())
	{
		std::cerr << "Incorrect input\n";
		return 1;
	}
	if (start < -1 || finish > 1 || start > finish)
	{
		std::cerr << "Incorrect interval\n";
		return 1;
	}
	
}
