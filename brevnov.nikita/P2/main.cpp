#include "brevnov.hpp"

int main()
{ 
    double left = 0.0, right = 0.0;
    size_t k = 0;
    std::cin >> left >> right >> k;
    if (std::cin.eof())
    {
        std::cerr << "Error!End of file!\n";
    }
    if (std::cin.fail())
    {
        std::cerr << "Input error!\n";
        return 1;
    }
    if ((left>=right) or (std::abs(left)>1) or (std::abs(right)>1))
    {
        std::cerr << "Incorrect input!\n";
    }
    brevnov::outputing(left, right, k);
    return 0;
}
