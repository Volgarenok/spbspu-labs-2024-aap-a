#include <cstring>
#include <iostream>
#include <iomanip>
#include <resize_line.hpp>
#include "composite-shape.hpp"
#include "io_data.hpp"
#include "shape_factory.hpp"

int main()
{
  using namespace zakirov;
  CompositeShape shapes;
  constexpr size_t step = 1;
  bool shape_flag = false;
  double * scale_data = nullptr;
  double scale_quantity = 0;
  double * data = nullptr;
  while (std::cin)
  {
    char * data = get_to_symbol(std::cin, step, ' ');
    if (!data)
    {
      std::cerr << "Warning! Some problems getting the string." << '\n';
      return 1;
    }
    else if (!std::strcmp(data, "SCALE"))
    {
      scale_data = get_parameters_series(std::cin);
      scale_quantity = scale_data[0];
      free(data);
      break;
    }

    Shape * new_shape = nullptr;
    try
    {
      new_shape = make_shape(std::cin, data);
      shapes.push_back(new_shape);
    }
    catch (const std::invalid_argument &)
    {
      shape_flag = true;
    }
    catch (const std::bad_alloc & e)
    {
      free(data);
      std::cerr << e.what() << '\n';
      return 1;
    }
    catch (const std::logic_error & e)
    {
      free(data);
      new_shape->~Shape();
      free(new_shape);
      std::cerr << e.what() << '\n';
      return 1;
    }

    free(data);
  }

  if (shapes.empty() || !scale_data || scale_quantity != 3)
  {
    std::cerr << "Some problem in getting shapes" << '\n';
    free(scale_data);
    free(data);
    return 1;
  }

  full_output(std::cout, shapes);
  std::cout << '\n';
  point_t target{scale_data[1], scale_data[2]};
  double coefficient = scale_data[3];
  try
  {
    scale_check_full_composition(shapes, target, coefficient);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << e.what() << '\n';
    free(scale_data);
    return 1;
  }

  full_output(std::cout, shapes);
  std::cout << '\n';
  if (shape_flag)
  {
    std::cerr << "Warning! One or more figures are specified incorrectly." << '\n';
  }

  free(scale_data);
}
