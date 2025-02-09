#ifndef SHAPE_FACTORY_HPP
#define SHAPE_FACTORY_HPP
#include <istream>
#include "shape.hpp"

namespace cherkasov
{
  class ShapeFactory
  {
    public:
    static Shape* createShape(const std::string& shapeType, std::istream& input);
  };
}
#endif
