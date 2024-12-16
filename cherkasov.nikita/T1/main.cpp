#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include "rectangle.h"
#include "square.h"
#include "parallelogram.h"

constexpr size_t maxShapes = 10000;
int main()
{
  cherkasov::Shape* shapes[maxShapes] = {nullptr};
  size_t shapeCount = 0;
  std::string inputCommand;
  bool scaleCommandIssued = false;
  while (std::getline(std::cin, inputCommand))
  {
    if (inputCommand.empty())
    {
      continue;
    }
    if (shapeCount >= maxShapes)
    {
      std::cerr << "Error: Shape limit exceeded\n";
      return 1;
    }
    if (inputCommand == "RECTANGLE")
    {
      double x1, y1, x2, y2;
      if (std::cin >> x1 >> y1 >> x2 >> y2)
      {
        shapes[shapeCount++] = new cherkasov::Rectangle({x1, y1}, {x2, y2});
      }
      else
      {
        std::cerr << "Error: invalid input for RECTANGLE\n";
      }
    }
    else if (inputCommand == "SQUARE")
    {
      double x, y, lenght;
      if (std::cin >> x >> y >> lenght && lenght > 0)
      {
        shapes[shapeCount++] = new cherkasov::Square({x, y}, lenght);
      }
      else
      {
        std::cerr << "Error: invalid input for SQUARE\n";
      }
    }
    else if (inputCommand == "PARALLELOGRAM")
    {
      double x1, y1, x2, y2, x3, y3;
      if (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
      {
        shapes[shapeCount++] = new cherkasov::Parallelogram({x1, y1}, {x2, y2}, {x3, y3});
      }
      else
      {
        std::cerr << "Error: invalid input for PARALLELOGRAMM\n";
      }
    }
    else
    {
      std::cerr << "Error: Unsupported shape " << inputCommand << "\n";
      return 1;
    }
    std::string remainingInput;
    std::getline(std::cin, remainingInput);
  }
  if (!scaleCommandIssued && shapeCount == 0)
  {
    std::cerr << "Error: No shapes were created and no SCALE command issued.\n";
    return 1;
  }
  std::cout << std::fixed << std::setprecision(1);
  double totalArea = 0.0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    if (shapes[i])
    {
      try
      {
        double area = shapes[i]->getArea();
        totalArea += area;
        std::cout << "Shape " << i + 1 << " Area: " << area << "\n";
      }
      catch (const std::exception& e)
      {
        std::cerr << "Error: Failed to calculate area for shape " << i + 1 << ": " << e.what() << "\n";
      }
      delete shapes[i];
      shapes[i] = nullptr;
    }
  }
  std::cout << "Total area of all shapes: " << totalArea << "\n";
  return 0;
}

