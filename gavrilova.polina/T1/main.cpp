#include <iostream>
#include <ostream>
#include <string>
#include "fabric_shape.hpp"
#include <iomanip>
namespace gavrilova {
  void scaleShape(Shape & shape, const point_t & center, double k) {
    point_t pos1 = shape.getFrameRect().pos;
    double difX = center.x - pos1.x;
    double difY = center.y - pos1.y;
    shape.move(center);
    shape.scale(k);
    difX *= k;
    difY *= k;
    shape.move(-difX, -difY);
  }
  void outRectangles(std::ostream & out, gavrilova::Shape ** Shapes, size_t nShapes) {
    if (nShapes) {
      for (size_t i = 0; i < nShapes; ++i) {
        rectangle_t rect = Shapes[i]->getFrameRect();
        //out << " " << rect.height << " " << rect.width << " " << rect.pos.x << " " << rect.pos.y << "\n";
        out << std::setprecision(3);
        out << " " << rect.pos.x - rect.width / 2 << " " << rect.pos.y - rect.height / 2;
        out << " " << rect.pos.x + rect.width / 2 << " " << rect.pos.y + rect.height / 2;
      }
      out << "\n";
    }
  }
}
int main()
{
  gavrilova::Shape * Shapes[1000] = {nullptr};
  gavrilova::point_t center{0,0};
  double koef = -1;
  size_t nShapes = 0;
  size_t nError = 0;
  size_t commonAreaBefore = 0;
  std::cout << std::fixed;
  std::cout.precision(1);
  while (!std::cin.eof() && std::cin) {
    try {
      Shapes[nShapes] = gavrilova::fabric_shape(std::cin, center, koef, nError);
    } catch (...) {
      //std::cerr << Error in creating shape;
      return 1;
    }
    //std::cout << "!!\n";
    if (Shapes[nShapes]) {
      commonAreaBefore += Shapes[nShapes]->getArea();
      ++nShapes;
    } else if (koef > 0 || std::cin.eof()) {
      break;
    }
    //std::cout << "nShapes = " << nShapes << "\n";
  }
  if (koef <= 0) {
    std::cerr << "ERROR\n";
    return 1;
  }
  if (!nShapes || nError) {
    std::cerr << "Возникли ошибки при вводе фигур";
  }
  std::cout << std::setprecision(2);
  std::cout << commonAreaBefore;
  gavrilova::outRectangles(std::cout, Shapes, nShapes);

  double commonAreaAfter = 0;
  for (size_t i = 0; i < nShapes; ++i) {
    gavrilova::scaleShape(*(Shapes[i]), center, koef);
    commonAreaAfter += Shapes[i]->getArea();
  }
  std::cout << commonAreaAfter;
  gavrilova::outRectangles(std::cout, Shapes, nShapes);

  for (size_t i = 0; i < nShapes; ++i) {
    delete Shapes[i];
   }
}

