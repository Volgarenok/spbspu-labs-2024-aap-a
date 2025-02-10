#include <string>
#include <exception>
#include <iomanip>
#include "build_shapes.hpp"
#include "shape_actions.hpp"

int main()
{
  sveshnikov::CompositeShape comp_shp;
  std::string shape_name;
  try
  {
    while (shape_name != "SCALE" && !std::cin.eof())
    {
      std::cin >> shape_name;
      try
      {
        if (shape_name == "RECTANGLE")
        {
          sveshnikov::build_rectangle(std::cin, comp_shp);
        }
        else if (shape_name == "RING")
        {
          sveshnikov::build_ring(std::cin, comp_shp);
        }
        else if (shape_name == "ELLIPSE")
        {
          sveshnikov::build_ellipse(std::cin, comp_shp);
        }
        else if (shape_name == "SQUARE")
        {
          sveshnikov::build_square(std::cin, comp_shp);
        }
      }
      catch (const std::logic_error &e)
      {
        std::cerr << e.what() << "\n";
      }
    }
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  if (shape_name != "SCALE")
  {
    std::cerr << "ERROR: The input must end with the zoom command!\n";
    return 1;
  }
  if (comp_shp.empty())
  {
    std::cerr << "ERROR: Nothing To Scale!\n";
    return 1;
  }
  double zoom_ctr_x = 0.0, zoom_ctr_y = 0.0, k = 0.0;
  std::cin >> zoom_ctr_x >> zoom_ctr_y >> k;
  std::cout << std::fixed << std::setprecision(1);
  std::cout << comp_shp.getArea() << " ";
  sveshnikov::output_frame(std::cout, comp_shp);
  std::cout << "\n";
  try
  {
    sveshnikov::isotropic_scaling(comp_shp, zoom_ctr_x, zoom_ctr_y, k);
  }
  catch (const std::logic_error &e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << comp_shp.getArea() << " ";
  sveshnikov::output_frame(std::cout, comp_shp);
  std::cout << "\n";
  return 0;
}
