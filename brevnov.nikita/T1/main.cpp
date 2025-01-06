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
  size_t start_count_shape = 30;
  brevnov::CompositeShape Cs(start_count_shape);
  std::string input_shape;
  brevnov::point_t scale_p;
  double ratio = 0.0;
  bool isIncorrectParameters = false, iswereLogicerror = false;
  bool scaleCommand = false;
  brevnov::Shape * new_shape = nullptr;
  while (std::cin >> input_shape)
  {
    if (std::cin.eof())
    {
      std::cerr << "EOF!!\n";
      return 1;
    }
    else if (input_shape == "SCALE")
    {
      scale_p = brevnov::scale(std::cin);
      std::cin >> ratio;
      if (ratio <= 0.0)
      {
        std::cerr << "Incorrect retio\n";
        return 1;
      }
      scaleCommand = true;
      break;
    }
    else
    {
      try
      {
        new_shape = brevnov::make_shape(input_shape, std::cin);
      }
      catch (const std::bad_alloc & e)
      {
        std::cerr << "Not enough memory!";
        return 1;
      }
      catch (const std::logic_error & t)
      {
        iswereLogicerror = true;
      }
      catch (const std::invalid_argument & f)
      {
        isIncorrectParameters = true;
      }
      Cs.push_back(new_shape);
    }
  }
  if (isIncorrectParameters)
  {
    std::cerr << "Some parameters were incorrect\n";
  }
  if (iswereLogicerror)
  {
    std::cerr << "Logic error happend\n";
  }
  if (count_of_shape == 0)
  {
    std::cerr << "Not a single figure was read\n";
    return 1;
  }
  if (!scaleCommand)
  {
    std::cerr << "No SCALE command!\n";
    return 1;
  }
  std::cout << std::setprecision(1);
  std::cout << Cs.getArea() << " ";
  Cs.print_frame_coordinates(std::cout);
  std::cout << "\n";
  Cs.scale(ratio, scale_p);
  std::cout << Cs.getArea() << " ";
  Cs.print_frame_coordinates(std::cout);
  std::cout << "\n";
  return 0;
}
