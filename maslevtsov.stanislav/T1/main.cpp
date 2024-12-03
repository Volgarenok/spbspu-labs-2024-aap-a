#include <iostream>
#include <iomanip>
#include <string>
#include "rectangle.hpp"

int main()
{
  std::string str = "";
  double bottomLeftX = 0, bottomLeftY = 0, topRightX = 0, topRightY = 0;
  while (std::cin >> str && !std::cin.eof())
  {
    if (str == "RECTANGLE")
    {
      std::cin >> bottomLeftX >> bottomLeftY >> topRightX >> topRightY;
      maslevtsov::Rectangle rect(
        maslevtsov::point_t{bottomLeftX, bottomLeftY}, maslevtsov::point_t{topRightX, topRightY});

      std::cout << std::fixed << std::setprecision(1) << rect.getArea();
      std::cout << '\n';
    }
  }
}
