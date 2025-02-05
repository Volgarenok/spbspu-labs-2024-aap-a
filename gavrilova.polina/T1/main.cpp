#include <iostream>
#include "make_shape.hpp"
#include "shapeManip.hpp"
#include "compositeShape.hpp"
#include <iomanip>

namespace gavrilova {
  void clearShapes(Shape** Shapes, size_t n);
}

int main()
{
  using namespace gavrilova;

  CompositeShape Shapes;
  size_t nError = 0;
  std::string shapeTypeOrScale;
  point_t center;
  double koef = 0;

  while (!std::cin.eof() && std::cin >> shapeTypeOrScale) {

    if (shapeTypeOrScale == "SCALE") {
      if (!(std::cin >> center.x >> center.y >> koef)) {
          std::cerr << " ";
      }
    }
    Shape* shp = make_shape(std::cin, shapeTypeOrScale, nError);
    if (shp) {
      try {
        Shapes.push_back(shp);
      } catch (const std::exception& e) {
        std::cerr << e.what();
        return 1;
      }
    }
  }

  if (koef <= 0 || Shapes.empty()) {
    return 1;
  }
  if (nError) {
    std::cerr << "Возникли ошибки при вводе фигур\n";
  }

  double commonAreaBefore = Shapes.getArea();
  std::cout << std::fixed << std::setprecision(1) << commonAreaBefore << " ";
  outRectangles(std::cout, Shapes);
  std::cout << "\n";

  scaleShapes(Shapes, center, koef);

  double commonAreaAfter = Shapes.getArea();
  std::cout << std::fixed << std::setprecision(1) << commonAreaAfter << " ";
  outRectangles(std::cout, Shapes);
  std::cout << "\n";
}
