#include <iostream>
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"
#include "inputProcess.hpp"
#include "composite-shape.hpp"
int main()
{
  try
  {
    alymova::CompositeShape shapes;
    bool wrong_shape_flag = false;
    double scale_params[3] = {};
    alymova::makeShape(std::cin, shapes, wrong_shape_flag, scale_params);
    if (shapes.empty())
    {
      std::cerr << "Nothing to scale\n";
      return 1;
    }
    alymova::print(std::cout, shapes);
    std::cout << "\n";
    alymova::scale(shapes, alymova::point_t{scale_params[0], scale_params[1]}, scale_params[2]);
    alymova::print(std::cout, shapes);
    std::cout << "\n";
    if (wrong_shape_flag)
    {
      std::cerr << "Incorrect description of the shapes\n";
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error" << "\n";
    return 1;
  }
}
