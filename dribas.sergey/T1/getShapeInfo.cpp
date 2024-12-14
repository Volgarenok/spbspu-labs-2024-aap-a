#include "getShapeInfo.hpp"
#include "enterStr.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "diamond.hpp"
size_t dribas::getShapeInfo(std::istream& input, Shape** myShapes)
{
  std::string Mystr;
  std::string Shapesname[5] = {"RECTANGLE", "TRIANGLE", "DIAMOND", "CONCAVE", "SCALE"};
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
          std::cerr << e.what() << '\n';
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
          std::cerr << e.what() << '\n';
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
          std::cout << myShapes[shapesCount]->getArea();
          shapesCount++;
        } catch (const std::invalid_argument& e) {
          std::cerr << e.what() << '\n';
        }

      }
    }
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << '\n';
    clear(myShapes);
    return 0;
  } catch (const std::logic_error& e) {
    std::cerr << e.what() << '\n';
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