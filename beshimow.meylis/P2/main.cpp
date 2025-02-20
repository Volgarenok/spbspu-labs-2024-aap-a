#include <iostream>
#include <iomanip>
#include <cmath>
#include "taylor.hpp"
#include "output.hpp"

int main(int argc, char* argv[])
{
    if (argc < 4)
    {
        std::cerr << "Error: Not enough arguments. Required: start and end of interval, and number of terms.\n";
        return 1;
    }

    double start = atof(argv[1]);
    double end = atof(argv[2]);
    if (start >= end)
    {
        std::cerr << "Error: Start of interval must be less than end.\n";
        return 1;
    }

    int terms = atoi(argv[3]);
    if (terms <= 0)
    {
        std::cerr << "Error: Number of terms must be positive.\n";
        return 1;
    }

    beshimow::print_header();
    double step = (end - start) / terms;
    for (double x = start; x <= end; x += step)
    {
        double taylor_val = beshimow::taylor_sin(x, terms, 0.0001);
        double exact_val = std::sin(x);
        beshimow::print_line(x, taylor_val, exact_val, false);
    }
    beshimow::print_footer();

    return 0;
}
