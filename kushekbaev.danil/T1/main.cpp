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
  double scaleCoeff = 0, scaleX = 0, scaleY = 0;
  kushekbaev::point_t scalePoint;

  while (std::cin >> shapeName)
  {
    if (shapeName == "RECTANGLE")
    {
      double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
      if (!(std::cin >> x1 >> y1 >> x2 >> y2))
      {
        std::cerr << "Rectangle reading error" << "\n";
        clearMemory(capacity, shapeCounter);
        return 1;
      }

      if (x1 >= x2 || y1 >= y2)
      {
        std::cerr << "Coordinates of left point couldnt be greater than coordinates of right point" << "\n";
        clearMemory(capacity, shapeCounter);
        return 1;
      }

      kushekbaev::point_t lowerLeft = { x1, y1 };
      kushekbaev::point_t upperRight = { x2, y2 };

      try
      {
        capacity[shapeCounter] = new kushekbaev::Rectangle(lowerLeft, upperRight);
        shapeCounter++;
      }
      catch (std::bad_alloc& e)
      {
        std::cerr << "bad alloc" << "\n";
        clearMemory(capacity, shapeCounter);
        return 1;
      }
    }

    else if (shapeName == "SCALE")
    {
      if(!(std::cin >> scaleX >> scaleY >> scaleCoeff))
      {
        std::cerr << "Scale reading error";
        clearMemory(capacity, shapeCounter);
        return 1;
      }

      if (scaleCoeff <= 0)
      {
        std::cerr << "Scale value should be positive";
        clearMemory(capacity, shapeCounter);
        return 1;
      }

      scalePoint = { scaleX, scaleY };

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
    std::cerr << "We reached the end of program" << "\n";
    return 0;
  }

  std::cout << std::fixed << std::setprecision(1) << getTotalArea(capacity, shapeCounter);
  coordOutput(capacity, shapeCounter);
  std::cout << "\n";

  scaleEverything(shapeCounter, capacity, scaleCoeff, scalePoint);

  std::cout << getTotalArea(capacity, shapeCounter);
  coordOutput(capacity, shapeCounter);
  clearMemory(capacity, shapeCounter);
}
