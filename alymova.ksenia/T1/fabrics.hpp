#ifndef FABRICS_HPP
#define FABRICS_HPP
#include "shape.hpp"
#include "inputProcess.hpp"
namespace alymova
{
  struct Creator
  {
    virtual ~Creator() = default;
    virtual Shape* create(std::istream& in) = 0;
  };
  struct CreatorRectangle: public Creator
  {
    Shape* create(std::istream& in) override;
  };
  struct CreatorCircle: public Creator
  {
    Shape* create(std::istream& in) override;
  };
  struct CreatorRegular: public Creator
  {
    Shape* create(std::istream& in) override;
  };
}
#endif
