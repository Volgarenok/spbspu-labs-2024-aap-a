#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstddef>
#include "taylor_arctg.hpp"

const double absolute_error = 1e-5;
const int N = 20;

int main() {
    double beg = 0.0;
    double end = 0.0;
    size_t max_n = 0;
    std::cin >> beg >> end >> max_n;
    if (!std::cin || beg >= end)
        return 1;

    double step = (end - beg) / N;
    for (int i = 0; i < N+1; i++) {
        double x = beg + step * i;
        double std_res = atan(x);
        double my_res = 0;
        try {
            my_res = taylor_arctg(x, max_n, absolute_error);
        }
        catch (std::runtime_error&) {
            std::cout << std::setprecision(8) << x << " <MATH ERROR> " << std_res << "\n";
            continue;
        }
        std::cout << std::setprecision(8) << x << " " << my_res << " " << std_res << "    " << abs(my_res - std_res) << "\n";

    }
    return 0;
}