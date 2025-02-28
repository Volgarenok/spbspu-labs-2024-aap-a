#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include "base-types.hpp"
#include "shape.hpp"
#include "composite-shape.hpp"
#include "makeShape.hpp"

int main()
{
  using namespace brevnov;
  std::cout << std::fixed << std::setprecision(1);
  size_t start_count_shape = 0;
  CompositeShape comp_sh(start_count_shape);
  std::string input_shape;
  point_t scale_p;
  double ratio = 0.0;
  bool isIncorrectParameters = false;
  bool scaleCommand = false;
  Shape * new_shape = nullptr;
  std::cin >> input_shape;
  while ((std::cin.good()) && (!scaleCommand))
  {
    try
    {
      new_shape = make_shape(input_shape, std::cin);
      comp_sh.push_back(new_shape);
    }
    catch (const std::bad_alloc & e)
    {
      std::cerr << "Not enough memory!\n";
      return 1;
    }
    catch (const std::invalid_argument& e)
    {
      isIncorrectParameters = true;
    }
    catch (const std::length_error& e)
    {
      delete new_shape;
      std::cerr << "Not enough memory!\n";
      return 1;
    }
    std::cin >> input_shape;
    if (input_shape == "SCALE")
    {
      scaleCommand = true;
    }
  }
  if (isIncorrectParameters)
  {
    std::cerr << "Some parameters were incorrect\n";
  }
  if (comp_sh.empty())
  {
    std::cerr << "Not a single figure was read\n";
    return 1;
  }
  if (!scaleCommand)
  {
    std::cerr << "No SCALE command!\n";
    return 1;
  }
  try
  {
    scale_p = scale(std::cin);
  }
  catch (const std::invalid_argument& f)
  {
    std::cerr << "incorrect scale point\n";
    return 1;
  }
  std::cin >> ratio;
  if (ratio <= 0.0)
  {
    std::cerr << "Incorrect retio\n";
    return 1;
  }
  std::cout << std::setprecision(1);
  std::cout << comp_sh.getArea() << " ";
  print_frame_coordinates(comp_sh, std::cout);
  std::cout << "\n";
  try
  {
    comp_sh.scale(ratio, scale_p);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Not enough memory for operatopn!\n";
    return 1;
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "Not correct scale!\n";
    return 1;
  }
  std::cout << comp_sh.getArea() << " ";
  print_frame_coordinates(comp_sh, std::cout);
  std::cout << "\n";
  return 0;
}
