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
    std::cout << std::setw(10);
    for (auto i = left; i < right; i += step){
        std::cout << i;
        std::cout << " ";
        try{
            std::cout << brevnov::f(i,k,error);
        } catch(std::logic_error & e){
            std::cout << "<MATH ERROR>";
        }
        std::cout << " " << brevnov::arctg(i); 
        std::cout<< "\n";
    }
    std::cout << right;
    try{
        std::cout << " " << brevnov::f(right, k, error);
    } catch (std::logic_error & e){
        std::cout << "<MATH ERROR>";
    }
    std::cout << " " << brevnov::arctg(right);
    std::cout << "\n";
}
