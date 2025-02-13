#include "io_data.hpp"
#include <iomanip>
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

  double * extra_elements(const double * array, size_t size, size_t expansion)
  {
    size_t new_size = (size + expansion) * sizeof(double);
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

double * zakirov::get_parameters_series(std::istream & in)
{
  constexpr size_t step = 1;
  size_t start = 0;
  size_t finish = 0;
  size_t real_size = 1;
  double size_built_in = 0.0;
  double * parameters = static_cast< double * >(malloc(real_size * sizeof(double)));
  if (!parameters)
  {
    throw std::logic_error("Error! Not enought memory.");
  }

  parameters[0] = size_built_in;
  char * workline = zakirov::get_to_symbol(in, step, '\n');
  while (workline[start] != '\0')
  {
    double * expanded_parameters = extra_elements(parameters, real_size, step);
    free(parameters);
    if (!expanded_parameters)
    {
      throw std::logic_error("Error! Not enought memory.");
    }

    parameters = expanded_parameters;
    while (workline[finish] != ' ' && workline[finish] != '\0')
    {
      ++finish;
    }

    parameters[real_size++] = std::stod(workline);
    while (start < finish)
    {
      workline[start] = ' ';
      ++start;
    }
    start = finish;
    ++finish;
    parameters[0] = ++size_built_in;
  }

  free(workline);
  return parameters;
}

char * zakirov::get_to_symbol(std::istream & in, size_t step, char interrupt_symbol)
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

  char last_symbol = interrupt_symbol;
  in >> last_symbol >> std::noskipws;
  line[0] = last_symbol;
  while (last_symbol != interrupt_symbol && last_symbol != '\0')
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
      get_part(in, expanded_line, start, finish, interrupt_symbol);
    }
    catch (const std::exception &)
    {
      free(expanded_line);
      free(line);
      throw;
    }

    free(line);
    line = expanded_line;
    for (size_t i = start; i < finish; ++i)
    {
      if (line[i] == interrupt_symbol || line[i] == '\0')
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

void zakirov::get_parameters(std::istream & in, double * array, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    double parameter = 0.0;
    in >> parameter;
    array[i] = parameter;
  }

  if (!in)
  {
    throw std::logic_error("Error in getting arguments");
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

void zakirov::full_output(std::ostream & out, CompositeShape & shapes)
{
  out << std::fixed << std::setprecision(1);
  out << shapes.getArea();
  for (size_t id = 0; id < shapes.size(); ++id)
  {
    std::cout << ' ';
    output_frame(out, shapes, id);
  }
}
