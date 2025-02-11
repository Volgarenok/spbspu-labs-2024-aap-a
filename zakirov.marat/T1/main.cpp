#include <cstring>
#include <iostream>
#include <iomanip>
#include "composite-shape.hpp"
#include "io_data.hpp"
#include "shape_factory.hpp"

int main()
{
  using namespace zakirov;
  CompositeShape shapes;
  constexpr size_t step = 1;
  size_t scale_quantity = 0;
  bool shape_flag = false;
  double * scale_data = nullptr;
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
      scale_quantity = get_parameters_series(std::cin, scale_data);
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
      free(data);
      continue;
    }
    catch (const std::logic_error &)
    {
      free(data);
      free(new_shape);
      std::cerr << "Warning! Error in scale composition." << '\n';
      return 1;
    }

    free(data);
  }

  if (!shapes.empty() || !scale_data || scale_quantity != 3)
  {
    std::cerr << "Warning! No shapes entered or scale is not defined." << '\n';
    free(scale_data);
    free(data);
    return 1;
  }

  full_output(std::cout, shapes);
  std::cout << '\n';
  point_t target{scale_data[2], scale_data[3]};
  double coefficient = scale_data[4];
  try
  {
    check_scale_full_composition(shapes, target, coefficient);
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Warning! The figure change coefficient is incorrect." << '\n';
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
