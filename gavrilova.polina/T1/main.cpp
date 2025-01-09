#include <iostream>
#include "fabric_shape.hpp"
#include "shapeManip.hpp"
#include <iomanip>

namespace gavrilova {
  void clearShapes(Shape** Shapes, size_t n);
}

int main()
{
  using namespace gavrilova;
  Shape* Shapes[1000] = {nullptr};
  point_t center{0,0};
  double koef = -1;
  size_t nShapes = 0;
  size_t nError = 0;
  double commonAreaBefore = 0;

  while (!std::cin.eof() && std::cin && koef <= 0) {
    try {
      Shapes[nShapes] = make_shape(std::cin, center, koef, nError);
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
