#include <iostream>
#include "make_shape.hpp"
#include "shapeManip.hpp"
#include <iomanip>

namespace gavrilova {
  void clearShapes(Shape** Shapes, size_t n);
}

int main()
{
  using namespace gavrilova;
  Shape* Shapes[1000] = {nullptr};

  size_t nShapes = 0;
  size_t nError = 0;
  double commonAreaBefore = 0;
  std::string shapeTypeOrScale;
  point_t center;
  double koef = 0;

  while (!std::cin.eof() && std::cin >> shapeTypeOrScale) {

    if (shapeTypeOrScale == "SCALE") {
      if (!(std::cin >> center.x >> center.y >> koef)) {
          std::cerr << " ";
      }
    }

    try {
      Shapes[nShapes] = make_shape(std::cin, shapeTypeOrScale, nError);
    } catch (const std::exception& e) {
      std::cerr << e.what();
      return 1;
    }
    if (Shapes[nShapes]) {
      commonAreaBefore += Shapes[nShapes]->getArea();
      ++nShapes;
    }
  }

  if (nError) {
    std::cerr << "Возникли ошибки при вводе фигур\n";
  }

  if (!nShapes) {
    return 1;
  }

  std::cout << std::fixed << std::setprecision(1) << commonAreaBefore << " ";
  outRectangles(std::cout, Shapes, nShapes);
  std::cout << "\n";

  double commonAreaAfter = 0;
  try {
    commonAreaAfter = scaleShapes(Shapes, nShapes, center, koef);
  }catch(const std::logic_error& e) {
    std::cerr << e.what();
    clearShapes(Shapes, nShapes);
    return 1;
  }

  std::cout << std::fixed << std::setprecision(1) << commonAreaAfter << " ";
  outRectangles(std::cout, Shapes, nShapes);
  std::cout << "\n";

  clearShapes(Shapes, nShapes);
}

