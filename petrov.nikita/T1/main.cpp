#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <input_cstring.hpp>
#include "shape.hpp"
#include "base-types.hpp"
#include "rectangle.hpp"
#include "scale_isotropically.hpp"
int main()
{
  petrov::Shape * shapes_massive[10000] = {};
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
      description[i] = new char[capacity];
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
  i++;
  type_of_shape[i] = '\0';
  size_t j = 0;
  size_t k = 0;
  while (stream_massive[i] != '\0')
  {
    description[j][k] = stream_massive[i];
    i++;
    k++;
    if (stream_massive[i] == ' ')
    {
      description[j][k] = '\0';
      i++;
      j++;
      k = 0;
    }
  }
  char ** p_end = nullptr;
  petrov::point_t p1 = { std::strtod(description[0], p_end), std::strtod(description[1], p_end) };
  petrov::point_t p2 = { std::strtod(description[2], p_end), std::strtod(description[3], p_end) };
  petrov::Rectangle rectangle(p1, p2);
  rectangle.getFrameRect();
  rectangle.getArea();
  std::cout << std::fixed << std::setprecision(1);
  std::cout << rectangle.area_ << " " << p1.x_ << " " <<  p1.y_ << " " << p2.x_ << " " << p2.y_ << "\n";
  shapes_massive[0] = &rectangle;
  petrov::point_t scale_point = { -1.0 , 2.0 };
  double b = 3.0;
  petrov::scaleIsotropically(scale_point, b, shapes_massive[0]);
  std::cout << std::fixed << std::setprecision(1);
  std::cout << rectangle.area_ << " " << rectangle.p1_.x_ << " " <<  rectangle.p1_.y_ << " " << rectangle.p3_.x_ << " " << rectangle.p3_.y_ << "\n";
}
