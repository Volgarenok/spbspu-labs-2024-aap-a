#include <iostream>
#include <iomanip>
#include "geomFunc.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "circle.hpp"

using namespace belobrov;

int main() {
  Shape* shapes[1000];
  size_t shapeCount = 0;
  std::string inputCommand;
  point_t isoCenter;
  double k = 0.0;
  bool scalingRequested = false;

  while (std::cin >> inputCommand) {
    if (inputCommand.empty()) {
      continue;
    }
    if (inputCommand == "RECTANGLE") {
      if (shapeCount >= 1000) {
        std::cerr << "Maximum number of shapes (1000) reached.\n";
        deleteShapes(shapes, shapeCount);
        return 1;
      }
      double x1, y1, x2, y2;
      std::cin >> x1 >> y1 >> x2 >> y2;
      if (x1 >= x2 || y1 >= y2) {
        std::cerr << "Invalid rectangle coordinates: lower-left must be less than upper-right.\n";
        continue;
      }
      shapes[shapeCount] = new Rectangle(x1, y1, x2, y2);
      if (shapes[shapeCount] == nullptr) {
        std::cerr << "Memory allocation failed for rectangle.\n";
        deleteShapes(shapes, shapeCount);
        return 1;
      }
      shapeCount++;

    } else if (inputCommand == "TRIANGLE") {
      double x1, y1, x2, y2, x3, y3;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      if (!isCorrectTriangle({x1, y1}, {x2, y2}, {x3, y3})) {
        std::cerr << "Invalid triangle coordinates.\n";
        continue;
      } else {
        shapes[shapeCount++] = new Triangle(x1, y1, x2, y2, x3, y3);
      }

    } else if (inputCommand == "CIRCLE") {
      double x, y, radius;
      std::cin >> x >> y >> radius;
      try {
        shapes[shapeCount++] = new Circle(x, y, radius);
      } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
      }

    } else if (inputCommand == "SCALE") {
      std::cin >> isoCenter.x >> isoCenter.y >> k;
      if (k <= 0) {
        std::cerr << "Scaling factor must be positive.\n";
        deleteShapes(shapes, shapeCount);
        return 1;
      }
      scalingRequested = true;
      break;

    } else {
      std::cerr << "Unknown command: " << inputCommand << "\n";
      deleteShapes(shapes, shapeCount);
      return 1;
    }
  }

  if (!scalingRequested) {
    std::cerr << "Scaling command (SCALE) was not provided.\n";
    deleteShapes(shapes, shapeCount);
    return 1;
  }

  if (shapeCount == 0) {
    std::cerr << "No shapes were created.\n";
    return 1;
  }

  std::cout << std::fixed << std::setprecision(1) << calculateTotalArea(shapes, shapeCount) << " ";
  outputFrameCoordinates(shapes, shapeCount);
  std::cout << "\n";

  applyIsoScaling(shapes, shapeCount, isoCenter, k);

  std::cout << calculateTotalArea(shapes, shapeCount) << " ";
  outputFrameCoordinates(shapes, shapeCount);
  std::cout << "\n";

  deleteShapes(shapes, shapeCount);
  return 0;
}
