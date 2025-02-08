#include "getShapeInfo.hpp"
#include <iostream>
#include <cstddef>
#include "rectangle.hpp"
#include "triangle.hpp"
#include "diamond.hpp"
#include "concave.hpp"
#include "outputRes.hpp"
#include "shape.hpp"

double dribas::getAllArea(Shape** myShapes, size_t shapeCount)
{
  double allArea = 0.0;
  for (size_t i = 0; i < shapeCount; i++) {
    allArea += myShapes[i]->getArea();
  }
  return allArea;
}

void dribas::scaling(dribas::Shape** myShapes, size_t shapeCount, dribas::point_t center, double ratio)
{
  for (size_t i = 0; i <shapeCount; i++) {
    dribas::point_t cneter = myShapes[i]->getFrameRect().pos;
    myShapes[i]->move(center);
    dribas::point_t center2 = myShapes[i]->getFrameRect().pos;
    double diffenceX = (center2.x - cneter.x) * ratio * - 1;
    double diffenceY = (center2.y - cneter.y) * ratio * - 1;
    myShapes[i]->scale(ratio);
    myShapes[i]->move(diffenceX, diffenceY);
  }
}

int dribas::getShapeInfo(std::istream& input, std::ostream& error, std::ostream& output, Shape** myShapes)
{
  std::string Mystr;
  int shapesCount = 0;
  bool scaled = false;
  try {
    while (input >> Mystr) {
      try {
        if (Mystr == "RECTANGLE") {
          point_t down, up;
          input >> down.x;
          input >> down.y;
          input >> up.x;
          input >> up.y;
          myShapes[shapesCount] =  new Rectangle{down, up};
          shapesCount++;
        } else if (Mystr == "TRIANGLE") {
          point_t a, b, c;
          input >> a.x;
          input >> a.y;
          input >> b.x;
          input >> b.y;
          input >> c.x;
          input >> c.y;
          myShapes[shapesCount] =  new Triangle{a, b, c};
          shapesCount++;
        } else if (Mystr == "DIAMOND") {
          point_t a, b, c;
          input >> a.x;
          input >> a.y;
          input >> b.x;
          input >> b.y;
          input >> c.x;
          input >> c.y;
          myShapes[shapesCount] =  new Diamond{a, b, c};
          shapesCount++;
        } else if (Mystr == "CONCAVE") {
          point_t a, b, c, d;
          input >> a.x;
          input >> a.y;
          input >> b.x;
          input >> b.y;
          input >> c.x;
          input >> c.y;
          input >> d.x;
          input >> d.y;
          myShapes[shapesCount] =  new Concave{a, b, c, d};
          shapesCount++;
        }
      } catch(const std::invalid_argument& e) {
        error << e.what() << '\n';
      }  
      if (Mystr == "SCALE") {
        scaled = true;
        if (shapesCount == 0) {
          error << "No shapes for scale\n";
          return -1;
        }
        point_t toCenter;
        double ratio;
        input >> toCenter.x;
        input >> toCenter.y;
        input >> ratio;
        try {
          outputRes(output, myShapes, shapesCount);
          scaling(myShapes, shapesCount, toCenter, ratio);
          outputRes(output, myShapes, shapesCount);
          return shapesCount;
        } catch (const std::invalid_argument& e) {
          error << e.what() << '\n';
          clear(myShapes, shapesCount);
          return -1;
        }
      }
    }
  } catch (const std::bad_alloc& e) {
    error << e.what() << '\n';
    clear(myShapes, shapesCount);
    return -1;
  } catch (const std::logic_error& e) {
    error << e.what() << '\n';
    clear(myShapes, shapesCount);
    return -1;
  }
  if (!scaled) {
    clear(myShapes, shapesCount);
    return -1;
  }
  return shapesCount;
}
void dribas::clear(Shape ** myshape, size_t shapeCount) {
  for (size_t i = 0; i < shapeCount; i++) {
    delete myshape[i];
  }
}
