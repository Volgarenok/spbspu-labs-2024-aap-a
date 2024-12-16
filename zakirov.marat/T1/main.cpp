#include <iostream>
#include <cstddef>
#include <iomanip>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "ring.hpp"
#include "unified_shapes.hpp"

int main()
{
  bool shape_flag = false;
  zakirov::Shape * shapes[10000];
  double * scale_data = nullptr;
  size_t location = 0;
  while(true)
  {
    double * data = zakirov::get_data(std::cin);
    if (data)
    {
      shapes[location] = zakirov::make_shape(data);
      if (shapes[location] != nullptr)
      {
        ++location;
      }
      else if (data[0] == 4.0)
      {
        scale_data = data;
        break;
      }
      else
      {
        shape_flag = true;
      }
    }

    if (!std::cin)
    {
      free(data);
      break;
    }
  }
  std::cout << std::setprecision(1);
  double total_area = 0;
  for (size_t i = 0; i < location; ++i)
  {
    total_area += shapes[i] -> getArea();
  }

  std::cout << total_area;
  zakirov::output_frame(std::cout, shapes, location);

  total_area = 0;
  for (size_t i = 0; i < location; ++i)
  {
    zakirov::point_t target;
    target.x_ = scale_data[2];
    target.y_ = scale_data[3];

    zakirov::scale_from_point(shapes[i], target, scale_data[4]);
    total_area += shapes[i] -> getArea();
  }
  std::cout << total_area;
  zakirov::output_frame(std::cout, shapes, location);

  if (shape_flag)
  {
    std::cerr << "Warning! One or more figures are specified incorrectly." << '\n';
  }

  free(scale_data);
  for (size_t i = 0; i < location; ++i)
  {
    delete shapes[i];
  }
}
