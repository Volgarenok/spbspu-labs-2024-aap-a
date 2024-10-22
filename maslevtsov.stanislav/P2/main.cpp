#include "taylor_series.hpp"
#include "table_output.hpp"

int main()
{
  const double error = 0.001;
  const double step = 0.1;

  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin)
  {
    std::cerr << "Incorrect input\n";
    return 1;
  }
  if ((left >= right) || (left < -1) || (right > 1))
  {
    std::cerr << "Incorrect boundaries\n";
    return 1;
  }

  maslevtsov::tableOutput(left, right, k, step, error);
}