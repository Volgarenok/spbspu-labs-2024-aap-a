#include <iostream>
#include "rectangle.hpp"

int main()
{
  beshimow::point_t pos = {0.0, 0.0};
  beshimow::Rectangle rect(4.0, 5.0, pos);

  beshimow::Shape* shape = &rect;

  std::cout << "Rectangle area: " << shape->getArea() << "\n";

  beshimow::rectangle_t frame = shape->getFrameRect();
  std::cout << "Frame rect - Width: " << frame.width
            << ", Height: " << frame.height
            << ", Center: (" << frame.pos.x << ", " << frame.pos.y << ")\n";

  shape->move({2.0, 3.0});
  frame = shape->getFrameRect();
  std::cout << "Moved to (" << frame.pos.x << ", " << frame.pos.y << ")\n";

  shape->scale(2.0);
  std::cout << "Scaled area: " << shape->getArea() << "\n";

  return 0;
}
