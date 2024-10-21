#include "f.hpp"

double kos::f(double x, size_t k, double error)
{
	double last = x, ans = x;
	for(size_t i = 1; i < k; i++) {
		last = last * x * x * (i * 2 - 1) * (i * 2 - 1) / (i * 2 + 0.0) / (i * 2 + 1.0);
		ans += last;
	}
	return ans;
}

double kos::stdf(double x)
{
  return std::asin(x);
}