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
      if (!(std::cin >> x1 >> y1 >> x2 >> y2))
      {
        std::cerr << "Error: Invalid input for RECTANGLE\n";
        return 1;
      }
      if (x1 > x2) std::swap(x1, x2);
      if (y1 > y2) std::swap(y1, y2);

      shapes[shapeCount++] = new cherkasov::Rectangle({x1, y1}, {x2, y2});
    }
    else if (inputCommand == "SQUARE")
    {
      double x, y, lenght;
      if (!(std::cin >> x >> y >> lenght) || lenght <= 0)
      {
        std::cerr << "Error: Invalid input for SQUARE\n";
        return 1;
      }

      shapes[shapeCount++] = new cherkasov::Square({x, y}, lenght);
    }
    else if (inputCommand == "PARALLELOGRAM")
    {
      double x1, y1, x2, y2, x3, y3;
      if (!(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3))
      {
        std::cerr << "Error: Invalid input for PARALLELOGRAM\n";
        return 1;
      }

      shapes[shapeCount++] = new cherkasov::Parallelogram({x1, y1}, {x2, y2}, {x3, y3});
    }
    else if (inputCommand == "SCALE")
    {
      scaleCommandIssued = true;
      double dx, dy, k;
      if (!(std::cin >> dx >> dy >> k) || k <= 0)
      {
        std::cerr << "Error: Invalid input for SCALE or non-positive factor\n";
        return 1;
      }

      for (size_t i = 0; i < shapeCount; ++i)
      {
        if (shapes[i])
        {
          shapes[i]->move(dx, dy);
          shapes[i]->scale(k);
        }
      }
    }
    else
    {
      std::cerr << "Error: Unsupported command '" << inputCommand << "'\n";
      return 1;
    }
    std::string remainingInput;
    std::getline(std::cin, remainingInput);
  }
  if (!scaleCommandIssued)
  {
    std::cerr << "Error: SCALE command was not issued\n";
    return 1;
  }
  if (shapeCount == 0)
  {
    std::cerr << "Error: No shapes created\n";
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
