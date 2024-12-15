#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "rectangle.h"

constexpr size_t maxShapes = 10000;
int main()
{
  cherkasov::Shape* shapes[maxShapes] = {nullptr};
  size_t shapeCount = 0;
  std::string inputCommand;
  while (std::cin >> inputCommand)
  {
  try
  {
    if (inputCommand == "RECTANGLE")
    {
      double x1, y1, x2, y2;
      std::cin >> x1 >> y1 >> x2 >> y2;
    if (shapeCount >= maxShapes)
    {
      throw std::logic_error("Shape limit exceeded");
    }
      shapes[shapeCount++] = new cherkasov::Rectangle({x1, y1}, {x2, y2});
    }
    else if (inputCommand == "SCALE")
    {
      double dx, dy, k;
      std::cin >> dx >> dy >> k;
    if (k <= 0)
    {
      throw std::logic_error("Scale factor must be positive");
    }
  for (size_t i = 0; i < shapeCount; ++i)
  {
    if (shapes[i] != nullptr)
    {
      shapes[i]->move(dx, dy);
      shapes[i]->scale(k);
    }
  }
  break;
  }
    else
    {
      std::cerr << "Unsupported inputcommand: " << inputCommand << "\n";
    }
  }
    catch (const std::exception& e)
    {
      std::cerr << "Error: " << e.what() << "\n";
    }
  }
  std::cout << std::fixed << std::setprecision(1);
  for (size_t i = 0; i < shapeCount; ++i)
  {
    if (shapes[i] != nullptr)
    {
      std::cout << "Shape " << i + 1 << "Area: " << shapes[i]->getArea() << "\n";
      delete shapes[i];
    }
  }
  return 0;
}
