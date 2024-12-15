#include "getShapeInfo.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "diamond.hpp"
#include "concave.hpp"

double dribas::getAllArea(Shape** myShapes, size_t shapeCount)
{
  double allArea = 0.0;
  for (size_t i = 0; i < shapeCount; i++) {
    allArea += myShapes[i]->getArea();
  }
  return allArea;
}

void dribas::scaling(Shape** myShapes, size_t shapeCount, Point_t center, double ratio)
{
  for (size_t i = 0; i <shapeCount; i++) {
    myShapes[i]->move(center);
    myShapes[i]->scale(ratio);
  }
}

size_t dribas::getShapeInfo(std::istream& input, std::ostream& error, Shape** myShapes)
{
  std::string Mystr;
  size_t shapesCount = 0;
  try {
    while (input >> Mystr) {
      if (Mystr == "RECTANGLE") {
        std::cout <<"sdad";
        try {
          Point_t down, up; 
          input >> down.x_;
          input >> down.y_;
          input >> up.x_;
          input >> up.y_;
          myShapes[shapesCount] =  new Rectangle{down, up};
          std::cout << myShapes[shapesCount]->getArea();
          shapesCount++;
        } catch (const std::invalid_argument& e) {
          error << e.what() << '\n';
        }
      } else if (Mystr == "TRIANGLE") {
        try {
          Point_t a, b, c; 
          input >> a.x_;
          input >> a.y_;
          input >> b.x_;
          input >> b.y_;
          input >> c.x_;
          input >> c.y_;
          myShapes[shapesCount] =  new Triangle{a, b, c};
          std::cout << myShapes[shapesCount]->getFrameRect().width_;
          shapesCount++;
        } catch (const std::invalid_argument& e) {
          error << e.what() << '\n';
        }
      } else if (Mystr == "DIAMOND") {
        try {
          Point_t a, b, c; 
          input >> a.x_;
          input >> a.y_;
          input >> b.x_;
          input >> b.y_;
          input >> c.x_;
          input >> c.y_;
          myShapes[shapesCount] =  new Diamond{a, b, c};
          shapesCount++;
        } catch (const std::invalid_argument& e) {
          error << e.what() << '\n';
        }
      } else if (Mystr == "CONCAVE") {
        try {
          Point_t a, b, c, d; 
          input >> a.x_;
          input >> a.y_;
          input >> b.x_;
          input >> b.y_;
          input >> c.x_;
          input >> c.y_;
          input >> d.x_;
          input >> d.y_;
          myShapes[shapesCount] =  new Concave{a, b, c, d};
          shapesCount++;
        } catch (const std::invalid_argument& e) {
          error << e.what() << '\n';
        }
      } else if (Mystr == "SCALE") {
        if (shapesCount == 0) {
          error << "No shapes for scale\n";
          return 0;
        }
        Point_t toCenter;
        input >> toCenter.x_;
        input >> toCenter.y_;
        double ratio;
        input >> ratio;
        try {
          scaling(myShapes, shapesCount, toCenter, ratio);
        } catch (const std::invalid_argument& e) {
          error << e.what() << '\n';
        }
      }
    }
  } catch (const std::bad_alloc& e) {
    error << e.what() << '\n';
    clear(myShapes);
    return 0;
  } catch (const std::logic_error& e) {
    error << e.what() << '\n';
    clear(myShapes);
    return 0;
  }
  return shapesCount;
}
void dribas::clear(Shape ** myshape) {
  for (size_t i = 0; i < 10000; i++) {
    delete [] myshape[i];
  }
}