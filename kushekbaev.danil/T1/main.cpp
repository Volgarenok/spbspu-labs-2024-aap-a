#include "rectangle.hpp"
#include <iostream>
#include <string>

int main()
{
  std::string shapeName;
  if (std::cin >> shapeName && shapeName == "RECTANGLE")
  {
    kushekbaev::point_t lowerLeft;
    kushekbaev::point_t upperRight;
    std::cin >> lowerLeft.x >> lowerLeft.x >> upperRight.x >> upperRight.y;
    kushekbaev::Rectangle* gol = nullptr;
    try
    {
      kushekbaev::Rectangle* gol = new kushekbaev::Rectangle(lowerLeft, upperRight);
    }
    catch (std::bad_alloc& e)
    {
      delete gol;
      std::cerr << "bad alloc" << "\n";
      gol = nullptr;
      return 1;
    }
    shapeName = "";
    std::cout << "good";
  }
}
