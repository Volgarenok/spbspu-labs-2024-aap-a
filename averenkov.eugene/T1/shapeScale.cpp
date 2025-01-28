#include "shapeScale.hpp"

namespace averenkov
{
  void shapeScale(Shape* shap, point_t scale_center, double factor)
  {
    point_t pos = shap->getFrameRect().pos;
    double xplus = scale_center.x - pos.x;
    double yplus = scale_center.y - pos.y;
    xplus *= factor;
    yplus *= factor;
    point_t newpos =
    {
      scale_center.x + (pos.x - scale_center.x) * factor,
      scale_center.y + (pos.y - scale_center.y) * factor
    };
    shap->move(newpos);
  }
}
