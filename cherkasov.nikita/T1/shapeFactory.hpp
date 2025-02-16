#ifndef SHAPEFACTORY_HPP
#define SHAPEFACTORY_HPP
#include <string>
#include <istream>
#include "shape.hpp"

namespace cherkasov
{
  Shape* createShape(const std::string& inputCommand, std::istream& input);
}
#endif
