#include "unified_shapes.hpp"
#include <cstddef>
#include <cstring>
#include <iomanip>
#include <memory>
#include <stdexcept>
#include <resize_line.hpp>
#include "composite-shape.hpp"

namespace
{
  void get_part(std::istream & in, char * line, size_t start, size_t finish, char interrupt_el)
  {
    for (; start < finish; ++start)
    {
      if (!in)
      {
        throw std::logic_error("The stream is broken");
      }

      in >> line[start];
      if (in.eof() || (line[start] == interrupt_el))
      {
        line[start] = '\0';
        break;
      }
    }
  }

  char * get_string(std::istream & in, size_t step, char interrupt_el)
  {
    size_t start = 1, finish = 1;
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
        throw std::bad_alloc();
      }

      try
      {
        get_part(in, expanded_line, start, finish, interrupt_el);
      }
      catch (const std::logic_error &)
      {
        free(expanded_line);
        free(line);
        throw;
      }

      free(line);
      line = expanded_line;
      for (size_t i = start; i < finish; ++i)
      {
        if (line[i] == interrupt_el || line[i] == '\0')
        {
          last_symbol = line[i];
          break;
        }
      }

      last_symbol = line[finish - 1];
      start += step;
    }

    in >> std::skipws;
    return line;
  }

  double * extra_element(const double * array, size_t size)
  {
    size_t new_size = size * sizeof(double) + sizeof(double);
    double * new_array = static_cast< double * >(malloc(new_size));
    if (new_array == nullptr)
    {
      return new_array;
    }

    for (size_t i = 0; i < size; ++i)
    {
      new_array[i] = array[i];
    }

    return new_array;
  }
}

/*
double * zakirov::get_data(std::istream & in)
{
  constexpr char rectangle[] = "RECTANGLE";
  constexpr char circle[] = "CIRCLE";
  constexpr char ring[] = "RING";
  constexpr char scale[] = "SCALE";
  constexpr char polygon[] = "POLYGON";

  constexpr size_t step = 1;
  size_t real_size = 2;
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
  else if (!std::strcmp(shape, rectangle))
  {
    data[0] = 2.0;
  }
  else if (!std::strcmp(shape, circle))
  {
    data[0] = 3.0;
  }
  else if (!std::strcmp(shape, ring))
  {
    data[0] = 4.0;
  }
  else if (!std::strcmp(shape, polygon))
  {
    data[0] = 5.0;
  }
  else if (!std::strcmp(shape, scale))
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
  size_t start  = 0;
  size_t finish = 0;
  size_t location = 2;
  double counter = 0.0;
  char * workline = get_string(in, step, '\n');
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
*/

void zakirov::check_scale_full_composition(CompositeShape & shapes, const point_t & target, double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect coefficient");
  }

  scale_full_composition(shapes, target, k);
}

void zakirov::scale_full_composition(CompositeShape & shapes, const point_t & target, double k)
{
  for (size_t i = 0; i < shapes.size(); ++i)
  {
    point_t nailed_p1 = shapes[i]->getFrameRect().pos;
    shapes[i]->move(target);
    point_t nailed_p2 = shapes[i]->getFrameRect().pos;
    point_t bias{(nailed_p2.x - nailed_p1.x) * k, (nailed_p2.y - nailed_p1.y) * k};
    shapes[i]->scale(k);
    shapes[i]->move(-bias.x, -bias.y);
  }
}

void zakirov::output_frame(std::ostream & out, CompositeShape & shapes, size_t id)
{
  rectangle_t frame = shapes[id]->getFrameRect();
  point_t frame_bottom_left{frame.pos.x - frame.width / 2, frame.pos.y - frame.height / 2};
  point_t frame_top_right{frame.pos.x + frame.width / 2, frame.pos.y + frame.height / 2};
  out << frame_bottom_left.x << ' ' << frame_bottom_left.y << ' ';
  out << frame_top_right.x << ' ' << frame_top_right.y;
}

void zakirov::clear_shapes(Shape ** shapes, size_t quantity)
{
  for (size_t i = 0; i < quantity; ++i)
  {
    shapes[i]->~Shape();
    free(shapes[i]);
  }
}

void zakirov::full_output(std::ostream & out, CompositeShape & shapes)
{
  out << std::fixed << std::setprecision(1);
  out << shapes.getArea();
  for (size_t id = 0; id < shapes.size(); ++id)
  {
    std::cout << ' ';
    output_frame(out, shapes, id);
  }

  std::cout << '\n';
}
