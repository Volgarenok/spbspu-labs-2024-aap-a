#include <iostream>
#include "Shape.hpp"
#include "base-types.hpp"
#include "shapes_tools.h"
#include "concave.h"
#include "rectangle.h"
#include "complexquad.h"
#include "triangle.h"
#include <iomanip>

int main()
{
  timofeev::Shape* shapes[10000];
  std::string input;
  size_t count = 0;
  bool incorrect_values = false;
  timofeev::point_t izo_pos;
  double factor;
  bool scale_availability = false;
  while (std::cin >> input)
  {
    if (input == "RECTANGLE")
    {
      double x1;
      double y1;
      double x2;
      double y2;
      std::cin >> x1 >> y1 >> x2 >> y2;
      if (x1 >= x2 || y1 >= y2)
      {
        incorrect_values = true;
      }
      else
      {
        shapes[count++] = new timofeev::Rectangle(x1, y1, x2, y2);
      }
    }
    else if (input == "CONCAVE")
    {
      double x1;
      double y1;
      double x2;
      double y2;
      double x3;
      double y3;
      double x4;
      double y4;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
      if (!timofeev::correct_triangle({ x1, y1 }, { x2, y2 }, { x3, y3 }))
      {
        incorrect_values = true;
      }
      if (!timofeev::is_point_in_triangle({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 }))
      {
        incorrect_values = true;
      }
      else
      {
        shapes[count++] = new timofeev::Concave({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 });
      }
    }
    else if (input == "COMPLEXQUAD")
    {
      double x1;
      double y1;
      double x2;
      double y2;
      double x3;
      double y3;
      double x4;
      double y4;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
      timofeev::point_t pos;
      pos = timofeev::cross_point({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 });
      if (!timofeev::is_point_in_quad({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 }, pos))
      {
        incorrect_values = true;
      }
      else
      {
        shapes[count++] = new timofeev::Complexquad({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 });
      }
    }
    else if (input == "TRIANGLE")
    {
      double x1;
      double y1;
      double x2;
      double y2;
      double x3;
      double y3;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      if (!timofeev::correct_triangle({ x1, y1 }, { x2, y2 }, { x3, y3 }))
      {
        incorrect_values = true;
      }
      else
      {
        shapes[count++] = new timofeev::Triangle({ x1, y1 }, { x2, y2 }, { x3, y3 });
      }
    }
    else if (input == "SCALE")
    {
      scale_availability = true;
      std::cin >> izo_pos.x >> izo_pos.y >> factor;
      if (factor <= 0)
      {
        std::cerr  << "factor must be positive\n";
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
  timofeev::print_frame_rect(shapes, count);
  timofeev::izoscale(shapes, count, izo_pos, factor);
  std::cout << "\n";
  std::cout << print_sum_area(shapes, count);
  timofeev::print_frame_rect(shapes, count);
  std::cout << "\n";
  shape_delete(shapes, count);
  return 0;
}
