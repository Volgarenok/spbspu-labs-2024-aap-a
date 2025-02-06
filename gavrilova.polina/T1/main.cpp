#include <iostream>
#include <iomanip>
#include "make_shape.hpp"
#include "shapeManip.hpp"
#include "compositeShape.hpp"

int main()
{
  using namespace gavrilova;

  CompositeShape shapes;
  std::string shapeTypeOrScale;
  point_t center;
  double koef = 0;

  while (!std::cin.eof() && std::cin >> shapeTypeOrScale) {

    if (shapeTypeOrScale == "SCALE") {
      if (!(std::cin >> center.x >> center.y >> koef)) {
          std::cerr << "Ошибка ввода парамметров масштабирования!";
      }
    }
    Shape* shp = nullptr;
    try {
      shp = make_shape(std::cin, shapeTypeOrScale);
    } catch (const std::exception& e) {
      std::cerr << e.what();
    }
    if (!shp) {
      continue;
    }
    try {
      shapes.push_back(shp);
    } catch (const std::exception& e) {
      std::cerr << e.what();
      return 1;
    }
  }

  if (koef <= 0 || shapes.empty()) {
    std::cerr << "Ошибка! Неправильный коэффицент или фигуры отсутствуют";
    return 1;
  }

  double commonAreaBefore = shapes.getArea();
  std::cout << std::fixed << std::setprecision(1) << commonAreaBefore << " ";
  outRectangles(std::cout, shapes);
  std::cout << "\n";

  scaleShapes(shapes, center, koef);

  double commonAreaAfter = shapes.getArea();
  std::cout << std::fixed << std::setprecision(1) << commonAreaAfter << " ";
  outRectangles(std::cout, shapes);
  std::cout << "\n";
}
