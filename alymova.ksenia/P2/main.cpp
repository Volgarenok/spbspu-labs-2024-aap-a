#include <iostream>
#include "funcs.h"

int main()
{
  double start = 0.0, finish = 0.0;
  int max_summand = 0;
  const double error = 0.0001;
  const double step = 0.05;
  std::cin >> start >> finish >> max_summand;
  if (!std::cin.good())
  {
    std::cerr << "Incorrect input\n";
    return 1;
  }
  if (start < -1 || finish > 1 || start >= finish)
  {
    std::cerr << "Incorrect interval\n";
    return 1;
  }
  for (double i = start; i < finish; i += step)
  {
    if (abs(i) < error)
    {
      alymova::print(0, alymova::arctg(0), alymova::taylor_row(0, max_summand, error));
    }
    else
    {
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
    }
  }
  try
  {
    double x = alymova::taylor_row(finish, max_summand, error);
    alymova::print(finish, x, alymova::arctg(finish));
  }
  catch (const std::logic_error& e)
  {
    alymova::print_error(finish, alymova::arctg(finish));
  }
}
