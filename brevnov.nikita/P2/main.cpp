#include "brevnov.hpp"

int main(){ 
    double left = 0.0, right = 0.0;
    size_t k = 0;
    std::cin >> left >> right >> k;
    if (std::cin.fail()){
        std::cerr << "Input error!\n";
        return 1;
    }
    if ((left>=right)){
        std::cerr << "Incorrect input!\n";
    }
    brevnov::output(left, right, k);
    return 0;
}
