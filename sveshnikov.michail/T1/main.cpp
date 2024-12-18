#include <iostream>
#include <string>
#include <iomanip>
#include "rectangle.hpp"

void output(std::ostream &in, sveshnikov::Shape **shapes, const size_t num_shapes);

int main()
{
  const size_t size = 10000;
  size_t num_shapes = 0;
  sveshnikov::Shape *shapes[size] = {};
  std::string shape_name = "";
  while (shape_name != "SCALE" || std::cin.eof())
  {
    std::cin >> shape_name;
    if (shape_name == "RECTANGLE")
    {
      double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
      std::cin >> x1 >> y1 >> x2 >> y2;
      if (x1 < x2 && y1 < y2)
      {
        sveshnikov::Rectangle rectangle = {{x1, y1}, {x2, y2}};
        *shapes[num_shapes] = rectangle;
      }
      else if (x1 > x2 && y1 > y2)
      {
        sveshnikov::Rectangle rectangle = {{x2, y2}, {x1, y1}};
        *shapes[num_shapes] = rectangle;
      }
      else
      {
        std::cerr << "ERROR: The rectangle should be described by the lower left and upper right points!\n";
        continue;
      }
      num_shapes++;
    }
  }

  if (shape_name != "SCALE")
  {
    std::cerr << "ERROR: The input must end with the zoom command!\n";
    return 1;
  }
  double zoom_ctr_x = 0.0, zoom_ctr_y = 0.0, k = 0.0;
  std::cin >> zoom_ctr_x >> zoom_ctr_y >> k;
  if (k <= 0)
  {
    std::cerr << "ERROR: Zoom coefficient must be positive!\n";
    return 1;
  }

  std::cout << std::fixed << std::setprecision(1);
  output(std::cout, shapes, num_shapes);

  
  return 0;
}

void output(std::ostream &in, sveshnikov::Shape **shapes, const size_t num_shapes)
{
  double total_area = 0.0;
  for (size_t i = 0; i < num_shapes; i++)
  {
    total_area += shapes[i]->getArea();
  }
  std::cout << total_area << " ";

  double low_left_x = 0.0, low_left_y = 0.0, up_right_x = 0.0, up_right_y = 0.0;
  for (size_t i = 0; i < num_shapes; i++)
  {
    sveshnikov::rectangle_t frame = shapes[i]->getFrameRect();
    low_left_x = frame.pos.x - frame.width / 2;
    low_left_y = frame.pos.y - frame.height / 2;
    up_right_x = frame.pos.x + frame.width / 2;
    up_right_y = frame.pos.y + frame.height / 2;
    std::cout << low_left_x << " " << low_left_y << " " << up_right_x << " " << up_right_y;
    if (i != num_shapes)
    {
      std::cout << " ";
    }
  }
  std::cout << '\n';
}
