#include <iostream>
#include <cmath>
#include "taylor.hpp"
#include "output.hpp"

using namespace beshimow;

int main() {
  double start = -0.5, end =

0.5;
  size_t max_terms = 10;
  double step = 0.1;
  double error_threshold = 0.001;

  print_header();
  for (double x = start; x <= end; x += step) {
    double taylor_val = taylor_sin(x, max_terms, error_threshold);
    double exact_val = std::sin(x);
    print_line(x, taylor_val, exact_val, std::abs(taylor_val - exact_val) > error_threshold);
  }
  print_footer();

  return 0;
}
