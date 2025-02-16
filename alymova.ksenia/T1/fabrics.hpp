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
    /*Shape* create(std::string name, std::istream& in);
    virtual Shape* createRectangle(std::istream& in) = 0;
    virtual Shape* createCircle(std::istream& in) = 0;
    virtual Shape* createRegular(std::istream& in) = 0;*/
  };
  /*struct CreatorSpecial: public Creator
  {
    Shape* createRectangle(std::istream& in) override;
    Shape* createCircle(std::istream& in) override;
    Shape* createRegular(std::istream& in) override;
  };*/
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
