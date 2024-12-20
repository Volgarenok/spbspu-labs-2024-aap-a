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
  zakirov::Shape * shapes[10000];
  size_t location = 0;
  bool shape_flag = false;
  double * scale_data = nullptr;
  while(true)
  {
    double * data = zakirov::get_data(std::cin);
    if (data)
    {
      try
      {
        shapes[location] = zakirov::make_shape(data);
      }
      catch (const std::invalid_argument & e)
      {
        shape_flag = true;
        free(data);
        continue;
      }

      if (data[0] == 1.0)
      {
        scale_data = data;
        break;
      }
      else if (std::cin.eof())
      {
        std::cerr << "Warning! Scale is not defined." << '\n';
        zakirov::clear_shapes(shapes, location);
        free(data);
        return 1;
      }
      else if (data[0] == 0.0)
      {
        free(data);
      }
      else
      {
        ++location;
        free(data);
      }
    }
    else
    {
      std::cerr << "Warning! Some problems getting the string." << '\n';
      return 1;
    }
  }

  if (shapes[0] == nullptr)
  {
    std::cerr << "Warning! No shapes entered." << '\n';
    zakirov::clear_shapes(shapes, location);
    free(scale_data);
    return 1;
  }
  else if (scale_data[4] <= 0)
  {
    std::cerr << "Warning! The figure change coefficient is incorrect." << '\n';
    zakirov::clear_shapes(shapes, location);
    free(scale_data);
    return 1;
  }

  double total_area = 0;
  for (size_t i = 0; i < location; ++i)
  {
    total_area += shapes[i] -> getArea();
  }

  std::cout << std::fixed << std::setprecision(1) << total_area;
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

  zakirov::clear_shapes(shapes, location);
  free(scale_data);
}
