#include <iostream>
namespace bocharov
{
  double f(double x, size_t k, double error);
  double stdf(double x);
}
int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  const double error = 0.001;
  const double step = 0.05;
  for (auto i = left; i < right; i+=step)
  {
    double value = f(i, k ,error);
    std::cout << i " " << value << " " <<  stdf(i) << "n\";
  }
}


double bocharov::f(double x, size_t k, double error)
{
  return 0;
}
