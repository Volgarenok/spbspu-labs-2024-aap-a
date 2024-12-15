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
    else if (inputCommand == "SQUARE")
    {
      double x, y, sideLength;
      std::cin >> x >> y >> sideLength;
      if (shapeCount >= maxShapes)
      {
        throw std::logic_error("Shape limit exceeded");
      }
     shapes[shapeCount++] = new cherkasov::Square({x, y}, sideLength);
    }
    else if (inputCommand == "PARALLELOGRAM")
    {
      double x1, y1, x2, y2, x3, y3;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      if (shapeCount >= maxShapes)
      {
        throw std::logic_error("Shape limit exceeded");
      }
     shapes[shapeCount++] = new cherkasov::Parallelogram({x1, y1}, {x2, y2}, {x3, y3});
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
    }
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory allocation error: " << e.what() << "\n";
    return 1;
  }
  catch (const std::logic_error& e)
  {
    std::cerr << "error: " << e.what() << "\n";
  }
    catch (const std::exception& e)
    {
      std::cerr << "Error: " << e.what() << "\n";
    }
  }
  std::cout << std::fixed << std::setprecision(1);
  for (size_t i = 0; i < shapeCount; ++i)
  {
    if (shapes[i])
    {
      std::cout << "Shape " << i + 1 << " Area: " << shapes[i]->getArea() << "\n";
      delete shapes[i];
    }
  }
  return 0;
}
