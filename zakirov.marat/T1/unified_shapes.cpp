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