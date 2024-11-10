#include <iostream>
#include "taylor.h"

int main()
{
    const double error = 0.042;
    const double step = 0.05;
    double left = 0.0, right = 0.0;
    size_t max = 0;

    std::cout << "Enter the start,end of the calculation interval and maximum numbers:";
    std::cin >> left >> right >> max;

    if (std::cin.fail())
    {
        std::cerr << "Error. Wrong imput." << '\n';
        return 1;
    }

    if (max <= 0 || left <= -0.7 || right >= 0.7 || left > right)
    {
        std::cerr << "Error. Incorrect values." << '\n';
        return 1;
    }

    for (auto i = left; i < right; i += step)
    {
        ivanova::Output(i, max, error);
        std::cout << '\n';
    }
    ivanova::Output(right, max, error);
    std::cout << "\n";
}
