#include "FindingTylor.hpp"

double zakirov::find_atanh(double point, size_t addition_depth, const double kError)
{
  int num_power = 1.0;
  double tylor = 0.0;
  double last_term = 0.0;
  for (size_t i = 0; i < addition_depth; ++i)
  {
    double term = 1.0;
    
    tylor += std::pow(point, num_power)/num_power;

    num_power += 2;
    last_term = term;
  }

  if (std::abs(last_term) > kError)
  {
    throw std::logic_error("<MATH_ERROR>");
  }

  return tylor;
}

double zakirov::get_atanh(double point)
{
  return std::atanh(point);
}