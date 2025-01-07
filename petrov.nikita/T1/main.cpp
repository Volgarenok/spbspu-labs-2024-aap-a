#include <iostream>
#include <iomanip>
#include <cstring>
#include "shape.hpp"
#include "make_shape.hpp"
#include "clear_memory.hpp"
#include "base-types.hpp"
#include "scale_isotropically_and_output_data.hpp"
int main()
{
  const char * NOTE_MSG = "NOTE: Scaling of some figures skipped due to their invalid description\n";
  petrov::Shape * shapes_massive[10000] = { 0 };
  size_t created = 0;
  bool is_description_error = false;
  do
  {
    shapes_massive[created] = nullptr;
    if (created == 0)
    {
      shapes_massive[created - 1] = nullptr;
    }
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
      is_description_error = true;
      continue;
    }
    catch(const std::logic_error & e)
    {
      continue;
    }
  }
  while ((shapes_massive[created - 1] != nullptr || created == 0) && !std::cin.eof() && std::cin);
  if (std::cin.eof())
  {
    petrov::clearMemory(shapes_massive, created);
    std::cerr << "End of file\n";
    return 1;
  }
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
    petrov::clearMemory(shapes_massive, created);
    std::cerr << "ERROR: Invalid scale value\n";
    return 3;
  }
  std::cout << std::fixed << std::setprecision(1);
  petrov::scaleIsotropicallyAndOutputData(scale_point, scale_value, shapes_massive, created);
  if (is_description_error)
  {
    std::cerr << NOTE_MSG;
  }
  petrov::clearMemory(shapes_massive, created);

}
