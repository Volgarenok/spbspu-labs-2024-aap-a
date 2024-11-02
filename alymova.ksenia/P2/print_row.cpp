#include "taylor_table.h"
#include <stdexcept>
void alymova::print_row(double x, int max_summand, double error)
{
  double res_math = alymova::arctg(x);
  try
  {
    double res_taylor = alymova::taylor_row(x, max_summand, error);
    alymova::print(x, res_taylor, res_math);
  }
  catch (const std::logic_error& e)
  {
    alymova::print_error(x, res_math);
  }
}
