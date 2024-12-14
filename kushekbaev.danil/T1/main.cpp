#include "rectangle.hpp"
#include "shapeManipulations.hpp"
#include <iostream>
#include <string>
#include <iomanip>

int main()
{
  kushekbaev::Shape* capacity[10000]{};
  size_t shapeCounter = 0;
  std::string shapeName;
  kushekbaev::point_t scaler;
  double V = 0;
  while (std::cin >> shapeName)
  {
    if (shapeName == "RECTANGLE")
    {
      try
      {
        capacity[shapeCounter] = kushekbaev::createRectangle(std::cin);
        shapeCounter++;
      }
      catch (std::bad_alloc& e)
      {
        clearMemory(capacity, shapeCounter);
        std::cerr << "bad alloc" << "\n";
        return 1;
      }
    }
    else if (shapeName == "SCALE")
    {
      std::cin >> scaler.x >> scaler.y >> V;
      if (V <= 0)
      {
        std::cerr << "Scale coefficient should be greater than zero";
        clearMemory(capacity, shapeCounter);
      }
      break;
    }
    shapeName = "";
  }

  if (shapeCounter == 0)
  {
    std::cerr << "Shapeless input" << "\n";
    return 1;
  }

  if (std::cin.eof())
  {
    std::cout << "We reached the end of program" << "\n";
    return 0;
  }

  std::cout << std::fixed << std::setprecision(1) << getTotalArea(capacity, shapeCounter) << "\n";
  coordOutput(capacity, shapeCounter);

  scaleEverything(shapeCounter, capacity, scaler, V);

  std::cout << getTotalArea(capacity, shapeCounter) << "\n";
  clearMemory(capacity, shapeCounter);
}
