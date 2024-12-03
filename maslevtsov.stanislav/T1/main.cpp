#include <iostream>
#include <iomanip>
#include "rectangle.hpp"

int main()
{
  double areaSummary = 0;
  while (!std::cin.eof())
  {
    maslevtsov::Shape* shape = nullptr;
    try
    {
      shape = maslevtsov::makeShape(std::cin);
    }
    catch (const std::logic_error& e)
    {
      std::cerr << "Figure is not supported\n";
    }
    areaSummary += shape->getArea();
  }

  std::cout << std::fixed << std::setprecision(1) << areaSummary << '\n';
}
