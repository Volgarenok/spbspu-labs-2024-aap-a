#include <iostream>
#include <cmath>
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

    const double error = 0.001;
    const double step = 0.05;
    for (auto i = left; i < right; i += step){
        double value = brevnov::f(i,k,error);
        std::cout << i;
        std::cout << " " << value;
        std::cout << " " << brevnov::arctg(i); 
        std::cout<< "\n";
    }
}
