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
    const char * errorsum = "<MATH ERROR>";
    const size_t snd = std::strlen(errorsum);
    const size_t usu = 10;
    for (auto i = left; i < right; i += step){
        std::cout << std::setw(usu) << i;
        std::cout << " ";
        try{
            std::cout << std::setw(snd) << brevnov::f(i,k,error);
        } catch(std::logic_error & e){
            std::cout << std::setw(snd) << "<MATH ERROR>";
        }
        std::cout << " " << std::setw(usu) << atan(i); 
        std::cout<< "\n";
    }
    std::cout << std::setw(usu) << right;
    try{
        std::cout << " " << std::setw(snd) << brevnov::f(right, k, error);
    } catch (std::logic_error & e){
        std::cout << std::setw(snd) << "<MATH ERROR>";
    }
    std::cout << " " << std::setw(usu) << brevnov::atan(right);
    std::cout << "\n";
}
