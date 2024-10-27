#include "header.h"

int main()
{
    const double error = 0.001;
    const double step = 0.05;

    double left = -1;
    double right = 1;
    std::size_t numberMax = 2;

    std::cin >> left >> right >> numberMax;

    if (std::cin.fail()) {
        std::cerr << "" << '\n';
        return 1;
    }
    if (right<left) {
        std::cerr << "" << '\n';
        return 1;
    }
    if ((right > 1) * (left < -1)) {
        std::cerr << "" << '\n';
        return 1;
    }

    asafov::table(left, right, step, numberMax, error);
    
    return 0;
}
