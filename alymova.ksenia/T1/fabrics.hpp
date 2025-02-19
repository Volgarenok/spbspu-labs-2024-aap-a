#ifndef FABRICS_HPP
#define FABRICS_HPP
#include <iostream>
#include "shape.hpp"
namespace alymova
{
  struct AbstractCreator;

  struct Creator
  {
    Creator();
    ~Creator();
    Shape* create(const std::string& name, std::istream& in);
  private:
    AbstractCreator** fabrics_;

    void clear() noexcept;
  };

  struct AbstractCreator
  {
    virtual ~AbstractCreator() = default;
    virtual Shape* create(std::istream& in) = 0;
  };
  struct CreatorRectangle final: public AbstractCreator
  {
    Shape* create(std::istream& in) override;
  };
  struct CreatorCircle final: public AbstractCreator
  {
    Shape* create(std::istream& in) override;
  };
  struct CreatorRegular final: public AbstractCreator
  {
    Shape* create(std::istream& in) override;
  };

  void readParameters(std::istream& in, double* params, size_t size);
}
#endif
