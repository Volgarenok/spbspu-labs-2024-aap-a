#include <iostream>
#include <iomanip>
#include "composite-shape.hpp"
#include "unified_shapes.hpp"

int main()
{
  using namespace zakirov;
  CompositeShape shapes;
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
    else if (data[0] == 1.0)
    {
      scale_data = data;
      break;
    }

    Shape * new_shape = nullptr;
    try
    {
      new_shape = make_shape(data);
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

  if (!shapes.empty() || !scale_data)
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
