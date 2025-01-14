#include "build_shapes.hpp"
#include <exception>
#include "rectangle.hpp"
#include "ring.hpp"
#include "ellipse.hpp"
#include "square.hpp"

void sveshnikov::build_rectangle(std::istream &in, CompositeShape &comp_shp)
{
  double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
  in >> x1 >> y1 >> x2 >> y2;
  comp_shp.push_back(new Rectangle({x1, y1}, {x2, y2}));
}

void sveshnikov::build_ring(std::istream &in, CompositeShape &comp_shp)
{
  double ctr_x = 0.0, ctr_y = 0.0, radius1 = 0.0, radius2 = 0.0;
  in >> ctr_x >> ctr_y >> radius1 >> radius2;
  comp_shp.push_back(new Ring({ctr_x, ctr_y}, radius1, radius2));
}

void sveshnikov::build_ellipse(std::istream &in, CompositeShape &comp_shp)
{
  double ctr_x = 0.0, ctr_y = 0.0, vert_radius = 0.0, horiz_radius = 0.0;
  in >> ctr_x >> ctr_y >> vert_radius >> horiz_radius;
  comp_shp.push_back(new Ellipse({ctr_x, ctr_y}, vert_radius, horiz_radius));
}

void sveshnikov::build_square(std::istream &in, CompositeShape &comp_shp)
{
  double low_left_x = 0.0, low_left_y = 0.0, side = 0.0;
  in >> low_left_x >> low_left_y >> side;
  comp_shp.push_back(new Square({low_left_x, low_left_y}, side));
}
