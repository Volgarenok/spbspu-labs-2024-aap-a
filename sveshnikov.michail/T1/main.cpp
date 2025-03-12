#include <string>
#include <exception>
#include <iomanip>
#include "build_shapes.hpp"
#include "shape_actions.hpp"

void outputCompShp(std::ostream &out, sveshnikov::CompositeShape &comp_shp);

int main()
{
  using namespace sveshnikov;
  CompositeShape comp_shp;
  std::string shape_name;

  while (shape_name != "SCALE" && !std::cin.eof())
  {
    std::cin >> shape_name;
    Shape *shp = nullptr;
    try
    {
      shp = buildShape(std::cin, shape_name);
      try
      {
        comp_shp.push_back(shp);
      }
      catch (const std::logic_error &e)
      {
        delete shp;
        std::cerr << e.what() << '\n';
      }
    }
    catch (const std::logic_error &e)
    {
      std::cerr << e.what() << "\n";
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << e.what() << "\n";
      return 1;
    }
  }
  if (shape_name != "SCALE")
  {
    std::cerr << "ERROR: The input must end with the zoom command!\n";
    return 1;
  }
  if (comp_shp.empty())
  {
    std::cerr << "ERROR: Nothing to scale!\n";
    return 1;
  }

  double zoom_ctr_x = 0.0, zoom_ctr_y = 0.0, k = 0.0;
  std::cin >> zoom_ctr_x >> zoom_ctr_y >> k;
  std::cout << std::fixed << std::setprecision(1);
  outputCompShp(std::cout, comp_shp);
  try
  {
    isotropicScaling(comp_shp, zoom_ctr_x, zoom_ctr_y, k);
  }
  catch (const std::logic_error &e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  outputCompShp(std::cout, comp_shp);
  return 0;
}

void outputCompShp(std::ostream &out, sveshnikov::CompositeShape &comp_shp)
{
  out << comp_shp.getArea() << " ";
  sveshnikov::outputFrames(out, comp_shp);
  out << "\n";
}
