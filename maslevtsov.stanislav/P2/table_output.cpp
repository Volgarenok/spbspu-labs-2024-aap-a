#include "table_output.hpp"
#include "taylor_series.hpp"

void maslevtsov::stringOutput(double current, size_t k, const double error)
{
  std::cout << current;
  std::cout << ' ';
  try
  {
    std::cout << maslevtsov::taylorSeries(current, k, error);
  }
  catch (const std::logic_error &e)
  {
    std::cout << "<MATH ERROR>";
  }
  std::cout << ' ' << 1 / (sqrt(1 - pow(current, 2)));
  std::cout << '\n';
}

void maslevtsov::tableOutput(double left, double right, size_t k, const double step, const double error)
{
  for (auto i = left; i < right; i += step)
  {
    maslevtsov::stringOutput(i, k, error);
  }
  maslevtsov::stringOutput(right, k, error);
}