#include <iostream>
#include <cstdlib>
#include <input_cstring.hpp>
#include "shape.hpp"
#include "base-types.hpp"
#include "rectangle.hpp"
int main()
{
  petrov::Shape shapes_massive[10000] = {};
  char * stream_massive = nullptr;
  size_t capacity = 1;
  char * type_of_shape = nullptr;
  char ** description = nullptr;
  size_t number_of_doubles = 4;
  size_t created = 0;
  try
  {
    stream_massive = petrov::inputCString(std::cin, capacity);
    type_of_shape = new char[capacity];
    description = new char * [number_of_doubles];
    for (size_t i = 0; i < number_of_doubles; i++)
    {
      description[number_of_doubles] = new char[capacity];
      created++;
    }
  }
  catch (const std::bad_alloc & e)
  {
    delete[] stream_massive;
    delete[] type_of_shape;
    for (size_t i = 0; i < created; i++)
    {
      delete[] description[i];
    }
    delete[] description;
    std::cerr << "ERROR: Out of memory\n";
    return 1;
  }
  size_t i = 0;
  while (stream_massive[i] != ' ')
  {
    type_of_shape[i] = stream_massive[i];
    i++;
  }
  size_t j = 0;
  size_t k = 0;
  while (stream_massive[i] != '\0')
  {
    if (stream_massive[i] == ' ')
    {
      description[j][k] = '\0';
      j++;
    }
    description[j][k] = stream_massive[i];
    i++;
    k++;
  }
  char ** p_end = nullptr;
  petrov::point_t p1 = { std::strtod(description[0], p_end), std::strtod(description[1], p_end) };
  petrov::point_t p2 = { std::strtod(description[2], p_end), std::strtod(description[3], p_end) };
  shapes_massive[0] = petrov::Rectangle(p1, p2);
  shapes_massive[0].getFrameRect();
  shapes_massive[0].getArea();
}
