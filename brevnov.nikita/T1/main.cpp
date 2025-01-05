#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include "base-types.hpp"
#include "shape.hpp"
#include "makeShape.hpp"

int main()
{
  std::cout << std::fixed << std::setprecision(1);
  constexpr size_t max_size_of_shape = 10000;
  size_t count_of_shape = 0;
  brevnov::Shape * shapes[max_size_of_shape] = {};
  std::string input_shape;
  brevnov::point_t scale_p;
  double ratio = 0.0;
  bool isIncorrectParameters = false;
  bool scaleCommand = false;
  try
  {
    while (std::cin >> input_shape)
    {
      if (std::cin.eof())
      {
        std::cerr << "EOF!!\n";
        brevnov::destroy_shape(shapes, count_of_shape);
        return 1;
      }
      else if (input_shape == "RECTANGLE")
      {
        try
        {
          shapes[count_of_shape] = brevnov::make_rectangle(std::cin);
          count_of_shape++;
        }
        catch (const std::invalid_argument & e)
        {
          isIncorrectParameters = true;
        }
      }
      else if (input_shape == "DIAMOND")
      {
        try
        {
          shapes[count_of_shape] = brevnov::make_diamond(std::cin);
          count_of_shape++;
        }
        catch(const std::invalid_argument & e)
        {
          isIncorrectParameters = true;
        }
      }
      else if (input_shape == "ELLIPSE")
      {
        try
        {
          shapes[count_of_shape] = brevnov::make_ellipse(std::cin);
          count_of_shape++;
        }
        catch(const std::invalid_argument & e)
        {
          isIncorrectParameters = true;
        }
      }
      else if (input_shape == "SCALE")
      {
        scale_p = brevnov::scale(std::cin);
        std::cin >> ratio;
        if (ratio <= 0.0)
        {
          std::cerr << "Incorrect retio\n";
          brevnov::destroy_shape(shapes, count_of_shape);
          return 1;
        }
        scaleCommand = true;
        break;
      }
    }
    if (isIncorrectParameters)
    {
      std::cerr << "Some parameters were incorrect\n";
    }
    if (count_of_shape == 0)
    {
      std::cerr << "Not a single figure was read\n";
      return 1;
    }
    if (!scaleCommand)
    {
      std::cerr << "No SCALE command!\n";
      brevnov::destroy_shape(shapes, count_of_shape);
      return 1;
    }
    std::cout << std::setprecision(1);
    std::cout << brevnov::get_sum_area(shapes, count_of_shape) << " ";
    brevnov::print_frame_coordinates(shapes, count_of_shape, std::cout);
    std::cout << "\n";
    brevnov::scale_shape(shapes, count_of_shape, scale_p, ratio);
    std::cout << brevnov::get_sum_area(shapes, count_of_shape) << " ";
    brevnov::print_frame_coordinates(shapes, count_of_shape, std::cout);
    std::cout << "\n";
    brevnov::destroy_shape(shapes, count_of_shape);
    return 0;
  }
  catch(const std::bad_alloc& e)
  {
    std::cerr << "Not emough memory\n";
    brevnov::destroy_shape(shapes, count_of_shape);
    return 1;
  }
}
