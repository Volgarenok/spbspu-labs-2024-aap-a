#include <iostream>
#include <iomanip>
#include <cstring>
#include "composite-shape.hpp"
#include "shape.hpp"
#include "make_shape.hpp"
#include "base-types.hpp"
#include "scale_isotropically_and_output_data.hpp"

int main()
{
  using namespace petrov;
  const char * NOTE_MSG = "NOTE: Scaling of some figures skipped due to their invalid description";
  CompositeShape composite_shape = {};
  Shape * ptr_shape = nullptr;
  bool is_description_error = false;
  do
  {
    try
    {
      ptr_shape = makeShape(std::cin);
      if (ptr_shape)
      {
        composite_shape.push_back(ptr_shape);
      }
    }
    catch (const std::bad_alloc & e)
    {
      delete ptr_shape;
      std::cerr << "ERROR: Out of memory\n";
      return 2;
    }
    catch (const std::invalid_argument & e)
    {
      is_description_error = true;
      continue;
    }
    catch (const std::logic_error & e)
    {
      continue;
    }
  }
  while ((composite_shape.empty() || ptr_shape != nullptr) && !std::cin.eof() && std::cin);
  if (std::cin.eof())
  {
    std::cerr << "End of file\n";
    return 1;
  }
  if (composite_shape.empty())
  {
    std::cerr << "ERROR: Nothing to scale\n";
    return 4;
  }
  point_t scale_point = {};
  double scale_value = 0.0;
  std::cin >> scale_point.x >> scale_point.y >> scale_value;
  if (scale_value <= 0)
  {
    std::cerr << "ERROR: Invalid scale value\n";
    return 3;
  }
  std::cout << std::fixed << std::setprecision(1);
  scaleIsotropicallyAndOutputData(scale_point, scale_value, composite_shape);
  if (is_description_error)
  {
    std::cerr << NOTE_MSG << "\n";
  }
}
