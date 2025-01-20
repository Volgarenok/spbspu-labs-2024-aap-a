#include <string>
#include <iostream>
#include "shape.hpp"

namespace demehin
{
  void createShape(std::istream& in, const std::string& shp_name, Shape** shapes, size_t& shp_cnt);
}
