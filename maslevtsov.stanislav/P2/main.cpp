#include "taylor_series.hpp"
#include "table_output.hpp"

int main()
{
  const double absError = 0.001;
  const double step = 0.05;

  double left = 0.0, right = 0.0;
  size_t numberMax = 0;
  std::cin >> left >> right >> numberMax;
  if (!std::cin)
  {
    std::cerr << "Incorrect input\n";
    return 1;
  }
  if ((left > right) || (left < -1) || (right > 1))
  {
    std::cerr << "Incorrect boundaries\n";
    return 1;
  }

  maslevtsov::tableOutput(left, right, numberMax, step, absError);
}
