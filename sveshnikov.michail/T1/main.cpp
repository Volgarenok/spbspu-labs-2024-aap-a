#include <string>
#include <exception>
#include <iomanip>
#include "build_shapes.hpp"
#include "shape_actions.hpp"

void clear(sveshnikov::Shape **shapes);

int main()
{
  const size_t size = 10000;
  size_t num_shapes = 0;
  sveshnikov::Shape *shapes[size] = {nullptr};
  std::string shape_name = "";
  try
  {
    while (shape_name != "SCALE" && !std::cin.eof())
    {
      std::cin >> shape_name;
      if (shape_name == "RECTANGLE")
      {
        try
        {
          sveshnikov::build_rectangle(std::cin, shapes, num_shapes);
        }
        catch (const std::logic_error& e)
        {
          std::cerr << "ERROR: The rectangle should be described by the lower left and upper right points!\n";
        }
      }
      else if (shape_name == "RING")
      {
        try
        {
          sveshnikov::build_ring(std::cin, shapes, num_shapes);
        }
        catch (const std::logic_error& e)
        {
          std::cerr << "ERROR: The radiuses of the ring must be given by positive numbers!\n";
        }
      }
      else if (shape_name == "ELLIPSE")
      {
        try
        {
          sveshnikov::build_ellipse(std::cin, shapes, num_shapes);
        }
        catch (const std::logic_error& e)
        {
          std::cerr << "ERROR: The radiuses of the ellipse must be given by positive numbers!\n";
        }
      }
    }
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "ERROR: Memmory not allocated!";
    clear(shapes);
    return 1;
  }
  if (shape_name != "SCALE")
  {
    std::cerr << "ERROR: The input must end with the zoom command!\n";
    clear(shapes);
    return 1;
  }
  double zoom_ctr_x = 0.0, zoom_ctr_y = 0.0, k = 0.0;
  std::cin >> zoom_ctr_x >> zoom_ctr_y >> k;
  if (k <= 0)
  {
    std::cerr << "ERROR: Zoom coefficient must be positive!\n";
    clear(shapes);
    return 1;
  }
  std::cout << std::fixed << std::setprecision(1);
  output_total_area(std::cout, shapes);
  output_frame(std::cout, shapes);
  sveshnikov::isotropic_scaling(shapes, zoom_ctr_x, zoom_ctr_y, k);
  output_total_area(std::cout, shapes);
  output_frame(std::cout, shapes);
  clear(shapes);
  return 0;
}

void clear(sveshnikov::Shape **shapes)
{
  for (size_t i = 0; shapes[i] != nullptr; i++)
  {
    delete shapes[i];
  }
}
