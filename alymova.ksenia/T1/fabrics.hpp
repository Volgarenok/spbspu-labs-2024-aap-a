#ifndef FABRICS_HPP
#define FABRICS_HPP
#include <iostream>
#include "shape.hpp"
namespace alymova
{
  struct Creator
  {
    virtual ~Creator() = default;
    virtual Shape* create(std::istream& in) = 0;
  };
  struct CreatorRectangle final: public Creator
  {
    Shape* create(std::istream& in) override;
  };
  struct CreatorCircle final: public Creator
  {
    Shape* create(std::istream& in) override;
  };
  struct CreatorRegular final: public Creator
  {
    Shape* create(std::istream& in) override;
  };

  void readParameters(std::istream& in, double* params, size_t size);
}
#endif
