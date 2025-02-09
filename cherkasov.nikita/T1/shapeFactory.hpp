#ifndef SHAPE_FACTORY_HPP
#define SHAPE_FACTORY_HPP
#include <string>
#include <istream>
#include "shape.hpp"

namespace cherkasov
{
  class ShapeFactory
  {
    public:
    static Shape* createShape(std::string& inputCommand, std::istream& input);
    private:
    static Shape* getRectangle(std::istream& input);
    static Shape* getSquare(std::istream& input);
    static Shape* getParallelogram(std::istream& input);
    static Shape* getDiamond(std::istream& input);
  };
}
#endif
