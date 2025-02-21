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
    point_t * converted_data = static_cast< point_t * >(malloc(size * sizeof(point_t)));
    if (!converted_data)
    {
      throw std::bad_alloc();
    }

    size_t counter = 1;
    for (size_t i = 0; i < size; ++i)
    {
      point_t point = {original_data[counter], original_data[counter + 1]};
      converted_data[i] = point;
      counter += 2;
    }

    return converted_data;
  }
}

zakirov::Rectangle * zakirov::make_rectangle(std::istream & in)
{
  constexpr size_t parameters_quantity = 4;
  double parameters[parameters_quantity] = {};
  get_parameters(in, parameters, parameters_quantity);

  Rectangle * rectangle = static_cast< Rectangle * >(malloc(sizeof(Rectangle)));
  if (!rectangle)
  {
    throw std::bad_alloc();
  }

  try
  {
    new (rectangle) Rectangle({parameters[0], parameters[1]}, {parameters[2], parameters[3]});
    return rectangle;
  }
  catch (const std::invalid_argument &)
  {
    free(rectangle);
    throw;
  }
}

zakirov::Circle * zakirov::make_circle(std::istream & in)
{
  constexpr size_t parameters_quantity = 3;
  double parameters[parameters_quantity] = {};
  get_parameters(in, parameters, parameters_quantity);

  Circle * circle = static_cast< Circle * >(malloc(sizeof(Circle)));
  if (!circle)
  {
    throw std::bad_alloc();
  }

  try
  {
    new (circle) Circle({parameters[0], parameters[1]}, parameters[2]);
    return circle;
  }
  catch (const std::invalid_argument &)
  {
    free(circle);
    throw;
  }
}

zakirov::Ring * zakirov::make_ring(std::istream & in)
{
  constexpr size_t parameters_quantity = 4;
  double parameters[parameters_quantity] = {};
  get_parameters(in, parameters, parameters_quantity);

  Ring * ring = static_cast< Ring * >(malloc(sizeof(Ring)));
  if (!ring)
  {
    throw std::bad_alloc();
  }

  try
  {
    new (ring) Ring({parameters[0], parameters[1]}, parameters[2], parameters[3]);
    return ring;
  }
  catch (const std::invalid_argument &)
  {
    free(ring);
    throw;
  }
}

zakirov::Polygon * zakirov::make_polygon(std::istream & in)
{
  double * parameters = get_parameters_series(in);
  size_t points_size = static_cast< size_t >(parameters[0] / 2.0);
  point_t * converted_data = convert_polygon(parameters, points_size);

  Polygon * polygon = static_cast< Polygon * >(malloc(sizeof(Polygon)));
  if (!polygon)
  {
    throw std::bad_alloc();
  }

  try
  {
    new (polygon) Polygon(points_size, converted_data);
    free(parameters);
    return polygon;
  }
  catch (const std::invalid_argument &)
  {
    free(parameters);
    free(converted_data);
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

  throw std::invalid_argument("Shapes not defined");
}
