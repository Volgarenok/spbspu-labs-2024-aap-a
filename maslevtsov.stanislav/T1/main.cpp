#include <iostream>
#include <iomanip>
#include "rectangle.hpp"

int main()
{
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
    std::cout << std::fixed << std::setprecision(1) << shape->getArea() << '\n';
  }
}
