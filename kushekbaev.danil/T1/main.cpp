#include "rectangle.hpp"
#include <iostream>
#include <string>

int main()
{
  std::string shapeName;
  while (std::cin) {
    if (std::cin.eof())
    {
      return 0;
    }
    else if (std::cin >> shapeName && shapeName == "RECTANGLE")
    {
      kushekbaev::point_t lowerLeft;
      kushekbaev::point_t upperRight;
      std::cin >> lowerLeft.x >> lowerLeft.y >> upperRight.x >> upperRight.y;
      if (lowerLeft.x >= upperRight.x || lowerLeft.y >= upperRight.y)
      {
        std::cerr << "Incorrect parameters" << "\n";
        break;
      }
      kushekbaev::Rectangle* gol = nullptr;
      try
      {
        kushekbaev::Rectangle* gol = new kushekbaev::Rectangle(lowerLeft, upperRight);
        double area = gol -> getArea();
        std::cout << area << "\n";
      }
      catch (std::bad_alloc& e)
      {
        delete gol;
        gol = nullptr;
        std::cerr << "bad alloc" << "\n";
        return 1;
      }
      shapeName = "";
      std::cout << "good" << "\n";
    }
    else
    {
      std::cout << "unsupported type" << "\n";
    }
  }
}
