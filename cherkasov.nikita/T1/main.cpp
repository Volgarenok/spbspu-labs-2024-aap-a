#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <limits>
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
    try
    {
    if (shapeCount >= maxShapes)
    {
      throw std::logic_error("Shape limit exceeded");
    }
    if (inputCommand == "RECTANGLE")
    {
      double x1, y1, x2, y2;
      if (!(std::cin >> x1 >> y1 >> x2 >> y2))
      {
        throw std::invalid_argument("Invalid input for RECTANGLE");
      }
      if (x1 > x2)
      {
        double temp = x1;
        x1 = x2;
        x2 = temp;
      }
      if (y1 > y2)
      {
        double temp = y1;
        y1 = y2;
        y2 = temp;
      }
     shapes[shapeCount++] = new cherkasov::Rectangle({x1, y1}, {x2, y2});
    }
    else if (inputCommand == "SQUARE")
    {
      double x, y, sideLength;
      if (!(std::cin >> x >> y >> sideLength))
      {
        throw std::invalid_argument("Invalid input for SQUARE");
      }
      shapes[shapeCount++] = new cherkasov::Square({x, y}, sideLength);
    }
    else if (inputCommand == "PARALLELOGRAM")
    {
      double x1, y1, x2, y2, x3, y3;
      if (!(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3))
      {
        throw std::invalid_argument("Invalid input for PARALLELOGRAM");
      }
      shapes[shapeCount++] = new cherkasov::Parallelogram({x1, y1}, {x2, y2}, {x3, y3});
    }
    else if (inputCommand == "SCALE")
    {
      scaleCommandIssued = true;
      double dx, dy, k;
      if (!(std::cin >> dx >> dy >> k))
      {
        throw std::invalid_argument("Invalid input for SCALE");
      }
      if (k <= 0)
      {
        throw std::logic_error("Scale factor must be positive");
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
      std::cerr << "Unsupported command: " << inputCommand << "\n";
      std::cin.clear();
      std::string invalidInput;
      std::getline(std::cin, invalidInput);
    }
  }
    catch (const std::invalid_argument& e)
    {
      std::cerr << "Invalid argument: " << e.what() << "\n";
      std::cin.clear();
      std::string invalidInput;
      std::getline(std::cin, invalidInput);
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Memory allocation error: " << e.what() << "\n";
      break;
    }
    catch (const std::logic_error& e)
    {
      std::cerr << "Logic error: " << e.what() << "\n";
    }
    catch (const std::exception& e)
    {
      std::cerr << "Error: " << e.what() << "\n";
    }
  }
  if (!scaleCommandIssued)
  {
    std::cerr << "Error: SCALE command was not issued\n";
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
      std::cerr << "Failed to calculate area for shape " << i + 1 << ": " << e.what() << "\n";
    }
    delete shapes[i];
    shapes[i] = nullptr;
    }
  }
  std::cout << "Total area of all shapes: " << totalArea << "\n";
  for (size_t i = 0; i < maxShapes; ++i)
  {
    delete shapes[i];
    shapes[i] = nullptr;
  }
  return 0;
}
