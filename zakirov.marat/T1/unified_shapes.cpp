#include "unified_shapes.hpp"
#include <cstring>
#include <stdexcept>
#include <resize_line.hpp>
#include <cstddef>
#include <memory>

namespace
{
  bool compare_strings(const char * first_string, const char * second_string)
  {
    std::size_t location = 0;
    if (first_string == nullptr || second_string == nullptr)
    {
      return true;
    }

    while (first_string[location] != '\0' && second_string[location] != '\0')
    {
      if (first_string[location] != second_string[location])
      {
        return true;
      }

      ++location;
    }

    if (first_string[location] == second_string[location])
    {
      return false;
    }
    else
    {
      return true;
    }
  }

  void get_part(std::istream & in, char * line, std::size_t start, std::size_t finish, char interrupt_el)
  {
    for (; start < finish; ++start)
    {
      in >> line[start];
      if (in.eof() || (line[start] == interrupt_el))
      {
        line[start] = '\0';
        break;
      }
      else if (!in)
      {
        throw std::logic_error("The stream is broken");
      }
    }
  }

  char * get_string(std::istream & in, std::size_t step, char interrupt_el)
  {
    std::size_t start = 1, finish = 1;
    char * line = static_cast< char * >(malloc(sizeof(char)));
    if (line == nullptr)
    {
      return line;
    }
    else if (!in)
    {
      free(line);
      return nullptr;
    }

    char last_symbol = interrupt_el;
    in >> last_symbol >> std::noskipws;
    line[0] = last_symbol;
    while (last_symbol != interrupt_el && last_symbol != '\0')
    {
      char * expanded_line = zakirov::expand_line(line, finish, step);
      finish += step;
      if (expanded_line == nullptr)
      {
        free(line);
        return expanded_line;
      }

      try
      {
        get_part(in, expanded_line, start, finish, interrupt_el);
      }
      catch(const std::exception& e)
      {
        free(expanded_line);
        free(line);
        throw e;
      }

      free(line);
      line = expanded_line;
      for (std::size_t i = start; i < finish; ++i)
      {
        if (line[i] == interrupt_el || line[i] == '\0')
        {
          last_symbol = line[i];
          break;
        }
        else if (i == finish - 1)
        {
          last_symbol = line[i];
        }
      }

      start += step;
    }

    in >> std::skipws;
    return line;
  }

  double * extra_element(const double * array, std::size_t size)
  {
    std::size_t new_size = size * sizeof(double) + sizeof(double);
    double * new_array = static_cast< double * >(malloc(new_size));
    if (new_array == nullptr)
    {
      return new_array;
    }

    for (std::size_t i = 0; i < size; ++i)
    {
      new_array[i] = array[i];
    }

    return new_array;
  }

  zakirov::point_t * convert_polygon(const double * original_data)
  {
    std::size_t points_size = static_cast< std::size_t >(original_data[1] / 2);
    zakirov::point_t * converted_data = static_cast< zakirov::point_t * >(malloc(points_size * sizeof(zakirov::point_t)));
    std::size_t counter = 2;
    for (std::size_t i = 0; i < points_size; ++i)
    {
      zakirov::point_t point = {original_data[counter], original_data[counter + 1]};
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
  catch(const std::invalid_argument & e)
  {
    free(rectangle);
    throw e;
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
  catch(const std::invalid_argument & e)
  {
    free(circle);
    throw e;
  }
}

zakirov::Ring * zakirov::make_ring(double center_x, double center_y, double in_radius, double ex_radius)
{
  point_t center{center_x, center_y};
  Ring * ring = static_cast< Ring * >(malloc(sizeof(Ring)));
  try
  {
    new (ring) Ring(center, in_radius, ex_radius);
    return ring;
  }
  catch(const std::invalid_argument & e)
  {
    free(ring);
    throw e;
  }
}

zakirov::Polygon * zakirov::make_polygon(std::size_t points_num, point_t * points)
{
  Polygon * polygon = static_cast< Polygon * >(malloc(sizeof(Polygon)));
  try
  {
    new (polygon) Polygon(points_num, points);
    return polygon;
  }
  catch(const std::invalid_argument & e)
  {
    free(points);
    free(polygon);
    throw e;
  }

  return new (polygon) Polygon(points_num, points);
}

zakirov::Shape * zakirov::make_shape(const double * data)
{
  if (data[0] == 2.0 && data[1] == 4.0)
  {
    return make_rectangle(data[2], data[3], data[4], data[5]);
  }
  else if (data[0] == 3.0 && data[1] == 3.0)
  {
    return make_circle(data[2], data[3], data[4]);
  }
  else if (data[0] == 4.0 && data[1] == 4.0)
  {
    return make_ring(data[2], data[3], data[4], data[5]);
  }
  else if (data[0] == 5.0)
  {
    point_t * converted_data = convert_polygon(data);
    std::size_t points_size = static_cast< std::size_t >(data[1] / 2);
    Polygon * polygon = make_polygon(points_size, converted_data);
    return polygon;
  }
  else
  {
    return nullptr;
  }
}

double * zakirov::get_data(std::istream & in)
{
  constexpr char rectangle[] = "RECTANGLE";
  constexpr char circle[] = "CIRCLE";
  constexpr char ring[] = "RING";
  constexpr char scale[] = "SCALE";
  constexpr char polygon[] = "POLYGON";

  constexpr std::size_t step = 1;
  std::size_t real_size = 2;
  double * data = static_cast< double * >(malloc(real_size * sizeof(double)));
  if (data == nullptr)
  {
    return nullptr;
  }

  char * shape = get_string(in, step, ' ');
  if (shape == nullptr)
  {
    free(data);
    free(shape);
    return nullptr;
  }
  else if (!compare_strings(shape, rectangle))
  {
    data[0] = 2.0;
  }
  else if (!compare_strings(shape, circle))
  {
    data[0] = 3.0;
  }
  else if (!compare_strings(shape, ring))
  {
    data[0] = 4.0;
  }
  else if (!compare_strings(shape, polygon))
  {
    data[0] = 5.0;
  }
  else if (!compare_strings(shape, scale))
  {
    data[0] = 1.0;
  }
  else
  {
    data[0] = 0.0;
    char * rest_string = get_string(in, step, '\n');
    free(shape);
    free(rest_string);
    return data;
  }

  free(shape);
  std::size_t location = 2;
  double counter = 0.0;
  char * workline = get_string(in, step, '\n');
  std::size_t start  = 0, finish = 0;
  while (workline[start] != '\0')
  {
    double * expanded_data = extra_element(data, location);
    free(data);
    if (expanded_data != nullptr)
    {
      data = expanded_data;
    }
    else
    {
      return nullptr;
    }

    while (workline[finish] != ' ' && workline[finish] != '\0')
    {
      ++finish;
    }

    data[location++] = std::stod(workline);
    while (start < finish)
    {
      workline[start] = ' ';
      ++start;
    }
    start = finish;
    ++counter;
    ++finish;
  }

  free(workline);
  data[1] = counter;
  return data;
}

void zakirov::scale_from_point(Shape * mutable_shape, point_t target, double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect coefficient");
  }

  point_t nailed_p1 = mutable_shape->getFrameRect().pos;
  mutable_shape->move(target);
  point_t nailed_p2 = mutable_shape->getFrameRect().pos;
  point_t bias{(nailed_p2.x - nailed_p1.x) * k, (nailed_p2.y - nailed_p1.y) * k};
  mutable_shape->scale(k);
  mutable_shape->move(-bias.x, -bias.y);
}

void zakirov::output_frame(std::ostream & out, Shape ** shapes, std::size_t quantity)
{
  for (std::size_t i = 0; i < quantity; ++i)
  {
    zakirov::rectangle_t frame = shapes[i]->getFrameRect();
    zakirov::point_t frame_bottom_left{frame.pos.x - frame.width / 2, frame.pos.y - frame.height / 2};
    zakirov::point_t frame_top_right{frame.pos.x + frame.width / 2, frame.pos.y + frame.height / 2};
    out << frame_bottom_left.x << ' ' << frame_bottom_left.y << ' ';
    out << frame_top_right.x << ' ' << frame_top_right.y;
  }

  out << '\n';
}

void zakirov::clear_shapes(Shape ** shapes, std::size_t quantity)
{
  for (std::size_t i = 0; i < quantity; ++i)
  {
    shapes[i]->~Shape();
    free(shapes[i]);
  }
}

void zakirov::scale_all_shapes(Shape ** shapes, point_t target, double k, std::size_t size)
{
  for (std::size_t i = 0; i < size; ++i)
  {
    zakirov::scale_from_point(shapes[i], target, k);
  }
}

double zakirov::get_total_area(Shape ** shapes, std::size_t size)
{
  double total_area = 0.0;
  for (std::size_t i = 0; i < size; ++i)
  {
    total_area += shapes[i]->getArea();
  }

  return total_area;
}
