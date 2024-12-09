#include <cstring>
#include <iostream>
#include "io_utils.hpp"
#include "main_utils.hpp"
#include "shape_utils.hpp"

int main()
{
  constexpr size_t shapesCapacity = 10'000;
  kizhin::Shape* shapes[shapesCapacity];
  size_t shapesSize = 0;

  bool isScaleCommand = false;
  char* currentName = nullptr;
  double* currentParams = nullptr;
  try {
    while (std::cin && !isScaleCommand) {
      kizhin::parseInputString(std::cin, &currentName, &currentParams);
      if (currentName && std::strcmp(currentName, "SCALE") == 0) {
        isScaleCommand = true;
      } else {
        kizhin::Shape* currentShape = kizhin::createShape(currentName, currentParams);
        if (currentShape) {
          shapes[shapesSize++] = currentShape;
        } else {
          kizhin::outputShapeError(std::cerr, currentName, currentParams) << '\n';
        }
        kizhin::resetPointers(&currentName, &currentParams);
      }
    }
    if (!isScaleCommand) {
      throw std::logic_error("Error: no 'SCALE' command\n");
    } else if (!shapesSize) {
      throw std::logic_error("Error: no shapes to perform 'SCALE' command\n");
    }

    kizhin::outputShapesInfo(std::cout, shapes, shapesSize) << '\n';
    const double* scalingParams = currentParams;
    kizhin::scaleShapes(shapes, shapesSize, scalingParams);
    kizhin::outputShapesInfo(std::cout, shapes, shapesSize) << '\n';
  } catch (const std::exception& e) {
    kizhin::resetPointers(&currentName, &currentParams);
    kizhin::deleteShapes(shapes, shapesSize);
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }

  kizhin::resetPointers(&currentName, &currentParams);
  kizhin::deleteShapes(shapes, shapesSize);
}
