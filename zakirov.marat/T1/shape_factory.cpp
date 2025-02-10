#include "shape_factory.hpp"
#include <stdexcept>

namespace
{
  zakirov::point_t * convert_polygon(const double * original_data)
  {
    using zakirov::point_t;
    size_t points_size = static_cast< size_t >((original_data)[1] / 2);
    point_t * converted_data = static_cast< point_t * >(malloc(points_size * sizeof(point_t)));
    size_t counter = 2;
    for (size_t i = 0; i < points_size; ++i)
    {
      point_t point = {(original_data)[counter], (original_data)[counter + 1]};
      converted_data[i] = point;
      counter += 2;
    }

    return converted_data;
  }
}

zakirov::Rectangle * zakirov::make_rectangle(double bottom_x, double bottom_y, double top_x, double top_y)
{
  point_t bottom_left{bottom_x, bottom_y};
  point_t top_right{top_x, top_y};
  Rectangle * rectangle = static_cast< Rectangle * >(malloc(sizeof(Rectangle)));
  try
  {
    new (rectangle) Rectangle(bottom_left, top_right);
    return rectangle;
  }
  catch (const std::invalid_argument & e)
  {
    free(rectangle);
    throw;
  }
}

zakirov::Circle * zakirov::make_circle(double center_x, double center_y, double radius)
{
  point_t center{center_x, center_y};
  Circle * circle = static_cast< Circle * >(malloc(sizeof(Circle)));
  try
  {
    new (circle) Circle(center, radius);
    return circle;
  }
  catch (const std::invalid_argument & e)
  {
    free(circle);
    throw;
  }
}

zakirov::Ring * zakirov::make_ring(double center_x, double center_y, double ex_radius, double in_radius)
{
  point_t center{center_x, center_y};
  Ring * ring = static_cast< Ring * >(malloc(sizeof(Ring)));
  try
  {
    new (ring) Ring(center, ex_radius, in_radius);
    return ring;
  }
  catch (const std::invalid_argument & e)
  {
    free(ring);
    throw;
  }
}

zakirov::Polygon * zakirov::make_polygon(size_t points_num, point_t * points)
{
  Polygon * polygon = static_cast< Polygon * >(malloc(sizeof(Polygon)));
  try
  {
    new (polygon) Polygon(points_num, points);
    return polygon;
  }
  catch (const std::invalid_argument & e)
  {
    free(polygon);
    throw;
  }

  return new (polygon) Polygon(points_num, points);
}

zakirov::Shape * zakirov::make_shape(double * data)
{
  if (data[0] == 5.0)
  {
    point_t * converted_data = convert_polygon(data);
    size_t points_size = static_cast< size_t >(data[1] / 2);
    Polygon * polygon = nullptr;
    try
    {
      Polygon * polygon = make_polygon(points_size, converted_data);
    }
    catch(const std::exception &)
    {
      free(converted_data);
    }

    return polygon;
  }
  else if (data[0] == 4.0 && data[1] == 4.0)
  {
    return make_ring(data[2], data[3], data[4], data[5]);
  }
  else if (data[0] == 3.0 && data[1] == 3.0)
  {
    return make_circle(data[2], data[3], data[4]);
  }
  else if (data[0] == 2.0 && data[1] == 4.0)
  {
    return make_rectangle(data[2], data[3], data[4], data[5]);
  }
  else
  {
    throw std::invalid_argument("Shapes not defined");
  }
}
