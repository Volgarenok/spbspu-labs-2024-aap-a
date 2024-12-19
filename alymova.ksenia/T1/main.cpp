#include <iostream>
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"
#include "shapesProcess.hpp"
#include "inputProcess.hpp"
int main()
{
  constexpr int max_size = 1000;
  alymova::Shape* shapes[max_size] = {};
  int shapes_now = 0;
  double scale_x = 0.0, scale_y = 0.0, scale_ratio = 1;
  bool wrong_shape_flag = false;
  try
  {
    alymova::makeShape(std::cin, shapes, shapes_now, wrong_shape_flag, scale_x, scale_y, scale_ratio);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error: memory not allocate\n";
    return 1;
  }
  catch (const std::logic_error& e)
  {
    clear(shapes);
    std::cerr << e.what() << "\n";
    return 1;
  }
  if (shapes_now == 0)
  {
    std::cerr << "Nothig to scale\n";
    return 1;
  }
  if (scale_ratio <= 0)
  {
    clear(shapes);
    std::cerr << "The scale ratio should be positive\n";
    return 1;
  }
  print(std::cout, shapes);
  std::cout << "\n";
  scale(shapes, alymova::point_t(scale_x, scale_y), scale_ratio);
  print(std::cout, shapes);
  std::cout << "\n";
  if (wrong_shape_flag)
  {
    std::cerr << "Incorrect description of the shapes\n";
  }
  clear(shapes);
}
