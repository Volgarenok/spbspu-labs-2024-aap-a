#include "shape.hpp"
#include "base-types.hpp"
#include "shapes_tools.hpp"
#include "concave.hpp"
#include "rectangle.hpp"
#include "complexquad.hpp"
#include "triangle.hpp"
#include <iostream>
#include <iomanip>

int main()
{
  using namespace timofeev;
  Shape* shapes[10000];
  std::string input;
  size_t count = 0;
  bool incorrect_values = false;
  point_t iso_pos;
  double factor;
  bool scale_availability = false;
  while (std::cin >> input && !std::cin.eof() && !std::cin == '\0')
  {
    if (input == "RECTANGLE")
    {
      double x1, y1, x2, y2;
      std::cin >> x1 >> y1 >> x2 >> y2;
      if (x1 >= x2 || y1 >= y2)
      {
        incorrect_values = true;
      }
      else
      {
        shapes[count++] = new Rectangle({ x1, y1 }, { x2, y2 });
      }
    }
    else if (input == "CONCAVE")
    {
      double x1, y1, x2, y2, x3, y3, x4, y4;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
      if (!correct_triangle({ x1, y1 }, { x2, y2 }, { x3, y3 }))
      {
        incorrect_values = true;
      }
      if (!is_point_in_triangle({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 }))
      {
        incorrect_values = true;
      }
      else
      {
        shapes[count++] = new Concave({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 });
      }
    }
    else if (input == "COMPLEXQUAD")
    {
      double x1, y1, x2, y2, x3, y3, x4, y4;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
      point_t pos;
      pos = cross_point({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 });
      if (!is_point_in_quad({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 }, pos))
      {
        incorrect_values = true;
      }
      else
      {
        shapes[count++] = new Complexquad({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 });
      }
    }
    else if (input == "TRIANGLE")
    {
      double x1, y1, x2, y2, x3, y3;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      if (!correct_triangle({ x1, y1 }, { x2, y2 }, { x3, y3 }))
      {
        incorrect_values = true;
      }
      else
      {
        shapes[count++] = new Triangle({ x1, y1 }, { x2, y2 }, { x3, y3 });
      }
    }
    else if (input == "SCALE")
    {
      scale_availability = true;
      std::cin >> iso_pos.x >> iso_pos.y >> factor;
      if (factor <= 0)
      {
        std::cerr  << "Factor must be positive\n";
        shape_delete(shapes, count);
        return 1;
      }
      break;
    }
    else if (std::cin.eof())
    {
      std::cerr << "EOF :(\n";
      shape_delete(shapes, count);
      return 1;
    }
  }
  if (!scale_availability)
  {
    std::cerr << "Scale was not given\n";
    shape_delete(shapes, count);
    return 1;
  }
  if (count == 0)
  {
    std::cerr << "Zero shapes found\n";
    return 1;
  }
  if (incorrect_values)
  {
    std::cerr << "Input was bad\n";
  }
  std::cout << std::fixed << std::setprecision(1) << print_sum_area(shapes, count);
  print_frame_rect(shapes, count);
  isoscale(shapes, count, iso_pos, factor);
  std::cout << "\n";
  std::cout << print_sum_area(shapes, count);
  print_frame_rect(shapes, count);
  std::cout << "\n";
  shape_delete(shapes, count);
  return 0;
}
