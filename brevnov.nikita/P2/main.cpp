#include "brevnov.hpp"

int main()
{ 
    double left = 0.0, right = 0.0;
    size_t k = 0;
    std::cin >> left >> right >> k;
    if (std::cin.eof())
    {
        std::cerr << "Error!End of file!\n";
        return 1;
    }
    if (std::cin.fail())
    {
        std::cerr << "Input error!\n";
        return 1;
    }
    if (left>=right)
    {
        std::cerr << "Incorrect input!\n";
        return 1;
    }
    brevnov::outputing(left, right, k);
    return 0;
}
