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
          std::cerr << "Error! Invalid scale parametrs.";
      }
    }
    Shape* shp = nullptr;
    try {
      shp = make_shape(std::cin, shapeTypeOrScale);
      shapes.push_back(shp);
    } catch (const std::bad_alloc& e) {
      std::cerr << e.what();
      if (!shp) {
        continue;
      }
      return 1;
    } catch (const std::invalid_argument & e) {
      std::cerr << e.what();
      return 1;
    } catch (const std::logic_error & e) {
      std::cerr << e.what();
      continue;
    }
  }

  if (koef <= 0 || shapes.empty()) {
    std::cerr << "Error! Invalid koefficient or there are no shapes";
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
