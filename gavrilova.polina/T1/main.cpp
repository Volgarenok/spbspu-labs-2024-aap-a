#include <iostream>
#include <string>
#include "fabric_shape.hpp"
namespace gavrilova {
  void scaleShape(Shape & shape, point_t center, double k) {
    point_t pos1 = shape.getFrameRect().pos;
    shape.move(center);
    double difX = shape.getFrameRect().pos.x - pos1.x;
    double difY = shape.getFrameRect().pos.y - pos1.y;
    shape.scale(k);
    difX *= k;
    difY *= k;
    shape.move(-difX, -difY);
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

  while (!std::cin.eof() && std::cin) {
    try {
      Shapes[nShapes] = gavrilova::fabric_shape(std::cin, center, koef, nError);
    } catch (...) {
      //std::cerr << Error in creating shape;
      return 1;
    }
    std::cout << "!!\n";
    if (Shapes[nShapes]) {
      commonAreaBefore += Shapes[nShapes]->getArea();
    }
    ++nShapes;
    std::cout << "nShapes = " << nShapes << "\n";
  }
  if (koef <= 0) {
    std::cerr << "ERROR\n";
    return 1;
  }
  for (size_t i = 0; i < nShapes; ++i) {
    gavrilova::scaleShape(*(Shapes[i]), center, koef);
  }
  //std::cout << Форма отмасштабирована\n;
   for (size_t i = 0; i < nShapes; ++i) {
       delete Shapes[i]; 
   }
}

