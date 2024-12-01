#include <iostream>
#include <string>
#include "rectangle.hpp"

int main()
{
  std::string str = "";
  double bottomLeftX = 0, bottomLeftY = 0, upRightX = 0, upRightY = 0;
  while (std::cin >> str && !std::cin.eof())
  {
    if (str == "RECTANGLE")
    {
      std::cin >> bottomLeftX >> bottomLeftY >> upRightX >> upRightY;
      maslevtsov::Rectangle rect(maslevtsov::rectangle_t{
        upRightX - bottomLeftX,
        upRightY - bottomLeftY,
        maslevtsov::point_t{(upRightX - bottomLeftX) / 2, (upRightY - bottomLeftY) / 2}});

      std::cout << rect.getArea();
      std::cout << '\n';
    }
  }
}
