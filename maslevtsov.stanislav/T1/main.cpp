#include <iostream>
#include <iomanip>
#include "rectangle.hpp"

int main()
{
  double areaSummary = 0;
  maslevtsov::Shape* shapes[10'000] = {nullptr};
  std::size_t shapeIndex = 0;
  bool isIgnoredShapes = false;
  std::string figureName = "";

  while (std::cin >> figureName && !std::cin.eof())
  {
    if (figureName == "RECTANGLE")
    {
      double bottomLeftX = 0, bottomLeftY = 0, topRightX = 0, topRightY = 0;
      std::cin >> bottomLeftX >> bottomLeftY >> topRightX >> topRightY;
      maslevtsov::Rectangle* rect = new maslevtsov::Rectangle({bottomLeftX, bottomLeftY}, {topRightX, topRightY});
      areaSummary += rect->getArea();
      shapes[shapeIndex++] = rect;
    }
    else
    {
      isIgnoredShapes = true;
    }
  }

  if (isIgnoredShapes)
  {
    std::cerr << "Some unsupported shapes has been ignored\n";
  }
  std::cout << std::fixed << std::setprecision(1) << areaSummary;
  maslevtsov::outputShapes(std::cout, shapes, shapeIndex);
  std::cout << '\n';
}
