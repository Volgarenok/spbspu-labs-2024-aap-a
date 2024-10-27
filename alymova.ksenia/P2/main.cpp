#include <iostream>
#include <cstddef>
#include "taylor_table_funcs.h"
int main()
{
  constexpr double error = 0.0001;
  constexpr double step = 0.05;
  double start = 0.0, finish = 0.0;
  size_t max_summand = 0;
  std::cin >> start >> finish >> max_summand;
  if (!std::cin.good())
  {
    std::cerr << "Incorrect input\n";
    return 1;
  }
  if (start <= -1 || finish >= 1 || start >= finish)
  {
    std::cerr << "Incorrect interval\n";
    return 1;
  }
  for (double i = start; i < finish; i += step)
  {
    if (std::abs(i) < error)
    {
      i = 0.0;
    }
    double res = alymova::arctg(i);
    try
    {
      double x = alymova::taylor_row(i, max_summand, error);
      alymova::print(i, x, res);
    }
    catch (const std::logic_error& e)
    {
      alymova::print_error(i, res);
    }
    std::cout << "\n";
  }
  double res = alymova::arctg(finish);
  try
  {
    double x = alymova::taylor_row(finish, max_summand, error);
    alymova::print(finish, x, res);
  }
  catch (const std::logic_error& e)
  {
    alymova::print_error(finish, res);
  }
  std::cout << "\n";
}
