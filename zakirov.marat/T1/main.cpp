#include <iostream>
#include <cstddef>
#include <iomanip>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "ring.hpp"
#include "unified_shapes.hpp"

using namespace zakirov;

int main()
{
  Shape * shapes[10000] = {};
  size_t location = 0;
  bool shape_flag = false;
  double * scale_data = nullptr;
  double * data = nullptr;
  while (std::cin)
  {
    double * data = get_data(std::cin);
    if (!data)
    {
      std::cerr << "Warning! Some problems getting the string." << '\n';
      return 1;
    }

    try
    {
      shapes[location] = make_shape(data);
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

  if (shapes[0] == nullptr)
  {
    std::cerr << "Warning! No shapes entered." << '\n';
    clear_shapes(shapes, location);
    free(scale_data);
    return 1;
  }
  else if (!scale_data)
  {
    std::cerr << "Warning! Scale is not defined." << '\n';
    clear_shapes(shapes, location);
    free(data);
    return 1;
  }

  std::cout << std::fixed << std::setprecision(1);
  std::cout << get_total_area(shapes, location) << ' ';
  output_frame(std::cout, shapes, location);

  point_t target{scale_data[2], scale_data[3]};
  double coefficient = scale_data[4];

  try
  {
    scale_all_shapes(shapes, target, coefficient, location);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "Warning! The figure change coefficient is incorrect." << '\n';
    clear_shapes(shapes, location);
    free(scale_data);
    return 1;
  }

  std::cout << get_total_area(shapes, location) << ' ';
  output_frame(std::cout, shapes, location);

  if (shape_flag)
  {
    std::cerr << "Warning! One or more figures are specified incorrectly." << '\n';
  }

  clear_shapes(shapes, location);
  free(scale_data);
}
