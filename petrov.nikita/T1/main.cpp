#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <input_cstring.hpp>
#include "shape.hpp"
#include "make_shape.hpp"
#include "clear_memory.hpp"
#include "base-types.hpp"
#include "scale_isotropically_and_output_data.hpp"
int main()
{
  const char * NOTE_MSG = "NOTE: Scaling of some figures skipped due to their invalid description\n";
  petrov::Shape * shapes_massive[10000] = {};
  size_t created = 0;
  size_t count_descr_errors = 0;
  do
  {
    try
    {
      shapes_massive[created] = petrov::makeShape(std::cin);
      created++;
    }
    catch(const std::bad_alloc & e)
    {
      petrov::clearMemory(shapes_massive, created);
      std::cerr << "ERROR: Out of memory\n";
      return 2;
    }
    catch(const std::invalid_argument & e)
    {
      count_descr_errors++;
      continue;
    }
    catch(const std::logic_error & e)
    {
      continue;
    }
  }
  while (shapes_massive[created - 1]);
  created--;
  if (created == 0)
  {
    std::cerr << "ERROR: Nothing to scale\n";
    return 4;
  }
  petrov::point_t scale_point = {};
  double scale_value = 0.0;
  std::cin >> scale_point.x >> scale_point.y >> scale_value;
  if (scale_value <= 0)
  {
    std::cerr << "ERROR: Invalid scale value\n";
    return 3;
  }
  std::cout << std::fixed << std::setprecision(1);
  petrov::scaleIsotropicallyAndOutputData(scale_point, scale_value, shapes_massive, created);
  if (count_descr_errors > 0)
  {
    std::cerr << NOTE_MSG;
  }
}