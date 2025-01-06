#include <iostream>
#include "fabric_shape.hpp"
#include "shapeManip.hpp"
#include <iomanip>

namespace gavrilova {
  void clearShapes(Shape** Shapes, size_t n);
}

int main()
{
  gavrilova::Shape* Shapes[1000] = {nullptr};
  gavrilova::point_t center{0,0};
  double koef = -1;
  size_t nShapes = 0;
  size_t nError = 0;
  double commonAreaBefore = 0;

  while (!std::cin.eof() && std::cin) {
    try {
      Shapes[nShapes] = gavrilova::make_shape(std::cin, center, koef, nError);
    } catch (const std::exception& e) {
      std::cerr << e.what();
      return 1;
    }
    if (Shapes[nShapes]) {
      commonAreaBefore += Shapes[nShapes]->getArea();
      ++nShapes;
    } else if (koef > 0 || std::cin.eof()) {
      break;
    }
  }
  if (koef <= 0) {
    std::cerr << "Kоэфицент не введен или введен неправильно\n";
    gavrilova::clearShapes(Shapes, nShapes);
    return 1;
  }
  if (nError) {
    std::cerr << "Возникли ошибки при вводе фигур\n";
  }
  if (!nShapes) {
    return 1;
  }
  std::cout << std::fixed << std::setprecision(1) << commonAreaBefore;
  gavrilova::outRectangles(std::cout, Shapes, nShapes);

  double commonAreaAfter = 0;

  gavrilova::scaleShapes(Shapes, nShapes, center, koef, commonAreaAfter);

  std::cout << std::fixed << std::setprecision(1) << commonAreaAfter;
  gavrilova::outRectangles(std::cout, Shapes, nShapes);

  gavrilova::clearShapes(Shapes, nShapes);
}

