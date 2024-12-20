#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include "rectangle.h"
#include "square.h"
#include "parallelogram.h"
#include "diamond.h"
#include "deleteShapes.h"
#include "calculArea.h"
#include "outputFrameCoordinates.h"
#include "scaling.h"

constexpr size_t maxShapes = 10000;
int main()
{
  cherkasov::Shape* shapes[maxShapes] = {nullptr};
  size_t shapeCount = 0;
  std::string inputCommand;
  cherkasov::point_t isoCenter;
  double scalingFactor;
  bool scalingRequested = false;
  while (std::cin >> inputCommand)
  {
    try
    {
      if (inputCommand == "RECTANGLE")
      {
        double x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        shapes[shapeCount++] = new cherkasov::Rectangle(x1, y1, x2, y2);
      }
      else if (inputCommand == "SQUARE")
      {
        double x1, y1, lenght;
        std::cin >> x1 >> y1 >> lenght;
        shapes[shapeCount++] = new cherkasov::Square(x1, y1, lenght);
      }
      else if (inputCommand == "PARALLELOGRAM")
      {
        double x1, y1, x2, y2, x3, y3;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        shapes[shapeCount++] = new cherkasov::Parallelogram({x1, y1}, {x2, y2}, {x3, y3});
      }
      else if (inputCommand == "DIAMOND")
      {
        double cx, cy, d1, d2;
        std::cin >> cx >> cy >> d1 >> d2;
        shapes[shapeCount++] = new cherkasov::Diamond(cx, cy, d1, d2);
      }
      else if (inputCommand == "SCALE")
      {
        scalingRequested = true;
        std::cin >> isoCenter.x >> isoCenter.y >> scalingFactor;
        if (scalingFactor <= 0)
        {
          throw std::invalid_argument("Scaling factor must be positive");
        }
        break;
        }
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << "\n";
    }
  }
  if (shapeCount == 0 || !scalingRequested)
  {
    std::cerr << "No shapes or scaling not specified\n";
    cherkasov::deleteShapes(shapes, shapeCount);
    return 1;
  }
  std::cout << std::fixed << std::setprecision(1);
  std::cout << cherkasov::calculArea(shapes, shapeCount);
  std::cout << cherkasov::outputFrameCoordinates(shapeArray, shapeCount);
  std::cout << cherkasov::scaling(shapeArray, shapeCount, isoCenter, scalingFactor);
  std::cout << "\n";
  std::cout << cherkasov::calculArea(shapes, shapeCount);
  std::cout << cherkasov::outputFrameCoordinates(shapes, shapeCount);
  std::cout << "\n";
  cherkasov::deleteShapes(shapes, shapeCount);
  return 0;
}
