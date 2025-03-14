#include <iostream>
#include "rectangle.hpp"

int main()
{
  beshimow::point_t pos = {0.0, 0.0};
  beshimow::Rectangle rect(4.0, 5.0, pos);

  std::cout << "Rectangle area: " << rect.getArea() << "\n";

  beshimow::rectangle_t frame = rect.getFrameRect();
  std::cout << "Frame rect - Width: " << frame.width
            << ", Height: " << frame.height
            << ", Center: (" << frame.pos.x << ", " << frame.pos.y << ")\n";

  rect.move({2.0, 3.0});
  std::cout << "Moved to (" << frame.pos.x << ", " << frame.pos.y << ")\n";

  rect.scale(2.0);
  std::cout << "Scaled area: " << rect.getArea() << "\n";

  return 0;
}
