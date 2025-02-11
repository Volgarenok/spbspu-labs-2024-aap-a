#include "shape_factory.hpp"
#include <cstring>
#include <istream>
#include <stdexcept>
#include "io_data.hpp"

namespace
{
  zakirov::point_t * convert_polygon(const double * original_data, size_t size)
  {
    using zakirov::point_t;
    size_t points_size = static_cast< size_t >(size / 2);
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

zakirov::Rectangle * zakirov::make_rectangle(std::istream & in)
{
  constexpr size_t parameters_quantity = 4;
  double parameters[parameters_quantity];
  get_parameters(in, parameters, parameters_quantity);

  Rectangle * rectangle = static_cast< Rectangle * >(malloc(sizeof(Rectangle)));
  try
  {
    new (rectangle) Rectangle({parameters[0], parameters[1]}, {parameters[2], parameters[3]});
    return rectangle;
  }
  catch (const std::invalid_argument & e)
  {
    free(rectangle);
    throw;
  }
}

zakirov::Circle * zakirov::make_circle(std::istream & in)
{
  constexpr size_t parameters_quantity = 3;
  double parameters[parameters_quantity];
  get_parameters(in, parameters, parameters_quantity);

  Circle * circle = static_cast< Circle * >(malloc(sizeof(Circle)));
  try
  {
    new (circle) Circle({parameters[0], parameters[1]}, parameters[2]);
    return circle;
  }
  catch (const std::invalid_argument & e)
  {
    free(circle);
    throw;
  }
}

zakirov::Ring * zakirov::make_ring(std::istream & in)
{
  constexpr size_t parameters_quantity = 4;
  double parameters[parameters_quantity];
  get_parameters(in, parameters, parameters_quantity);

  Ring * ring = static_cast< Ring * >(malloc(sizeof(Ring)));
  try
  {
    new (ring) Ring({parameters[0], parameters[1]}, parameters[2], parameters[3]);
    return ring;
  }
  catch (const std::invalid_argument & e)
  {
    free(ring);
    throw;
  }
}

zakirov::Polygon * zakirov::make_polygon(std::istream & in)
{
  double * parameters = nullptr;
  size_t points_size = get_parameters_series(in, parameters);
  point_t * converted_data = convert_polygon(parameters, points_size);

  Polygon * polygon = static_cast< Polygon * >(malloc(sizeof(Polygon)));
  try
  {
    new (polygon) Polygon(points_size, converted_data);
    return polygon;
  }
  catch (const std::invalid_argument & e)
  {
    free(polygon);
    throw;
  }
}

zakirov::Shape * zakirov::make_shape(std::istream & in, char * shape_name)
{
  if (!std::strcmp(shape_name, "RECTANGLE"))
  {
    return make_rectangle(in);
  }
  else if (!std::strcmp(shape_name, "CIRCLE"))
  {
    return make_circle(in);
  }
  else if (!std::strcmp(shape_name, "RING"))
  {
    return make_ring(in);
  }
  else if (!std::strcmp(shape_name, "POLYGON"))
  {
    return make_polygon(in);
  }
  else
  {
    throw std::invalid_argument("Shapes not defined");
  }
}

