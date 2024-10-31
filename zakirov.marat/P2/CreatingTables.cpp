#include "CreatingTables.hpp"
#include "FindingTylor.hpp"

void zakirov::tylor_string(double point, size_t addition_depth, const double &kError)
{

  std::cout << std::setw(10) << point << " ";

  try
  {
    double find_point = zakirov::find_atanh(point, addition_depth, kError);
    std::cout << std::setw(12) << find_point << " ";
  }
  catch (const std::logic_error &e)
  {
    std::cout << std::setw(12) << "<MATH_ERROR>" << " ";
  }

  double get_point = zakirov::get_atanh(point);
  std::cout << std::setw(10) << get_point << "\n";
}


void zakirov::tylor_table(double left, double right, size_t addition_depth,
    const double &kStep, const double &kError)
{
  for (double i = left; i < right; i += kStep)
  {
    zakirov::tylor_string(i, addition_depth, kError);
  }
  zakirov::tylor_string(right, addition_depth, kError);
}
