#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstddef>
#include "taylor_arctg.hpp"

namespace {
    const double absolute_error = 1e-5;
    const int N = 40;
}

int main() {
    double beg = 0.0;
    double end = 0.0;
    size_t max_n = 0;
    std::cin >> beg >> end >> max_n;
    if (!std::cin || beg >= end)
        return 1;

    double step = (end - beg) / N;
    std::cout << std::left << std::setprecision(8);
    for (int i = 0; i < N+1; i++) {
        double x = beg + step * i;
        double std_res = atan(x);
        double my_res = 0;
        bool error = false;
        try {
            my_res = zholobov::f(x, max_n, absolute_error);
        }
        catch (std::runtime_error&) {
            error = true;
        }
        std::cout << std::setw(12) << x;
        if (error)
            std::cout << std::setw(13) << "<MATH ERROR>";
        else
            std::cout << std::setw(13) << my_res;
        std::cout << std_res << "\n";
    }
    return 0;
}
