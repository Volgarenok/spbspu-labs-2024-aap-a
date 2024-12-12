#ifndef REGULAR_HPP
#define REGULAR_HPP

#include "shape.hpp"

namespace kizhin {
  class Regular;
}

class kizhin::Regular : public Shape
{
public:
  Regular(const point_t&, const point_t&, const point_t&);

  double getArea() const override;
  rectangle_t getFrameRect() const override;

  void move(double, double) override;
  void move(const point_t&) override;
  void scale(double) override;

private:
  point_t center_;
  double innerRadius_;
  double outerRadius_;
  rectangle_t frameRect_;
  point_t vtx_;

  void updateFrameRect();
  double computeVerticesCount() const;
  void computeVerticesArray(point_t**, point_t**) const;
};

#endif
