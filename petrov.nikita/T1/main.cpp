#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <input_cstring.hpp>
#include "shape.hpp"
#include "base-types.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "scale_isotropically.hpp"
int main() // Valgrind will argue...
{
  const char RECTANGLE[10] = "RECTANGLE";
  const char TRIANGLE[9] = "TRIANGLE";
  const char SCALE[6] = "SCALE";
  petrov::Shape * shapes_massive[10000] = {};
  size_t count = 0;
  petrov::point_t scale_point = {};
  double scale_value = 0.0;
  char * stream_massive = nullptr;
  char * type_of_shape = nullptr;
  char ** description = nullptr;
  size_t number_of_doubles = 8;
  while (true)
  {
    size_t capacity = 1;
    size_t created = 0;
    try
    {
      stream_massive = petrov::inputCString(std::cin, capacity); // Can be added const ERROR_MSG for input type of errors
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
      delete[] stream_massive; // Warning! Clearing memory like this duplicates often in this code 
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
    if (!strcmp(type_of_shape, RECTANGLE)) // Maybe LeakDefinitelyLost
    {
      char ** p_end = nullptr;
      petrov::point_t p1 = { std::strtod(description[0], p_end), std::strtod(description[1], p_end) };
      petrov::point_t p2 = { std::strtod(description[2], p_end), std::strtod(description[3], p_end) };
      petrov::Rectangle * ptr_rectangle = nullptr;
      try
      {
        ptr_rectangle = new petrov::Rectangle(p1, p2);
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
      shapes_massive[count++] = ptr_rectangle;
      delete[] stream_massive;
      delete[] type_of_shape;
      for (size_t i = 0; i < created; i++)
      {
        delete[] description[i];
      }
      delete[] description;
      std::clog << "YAY!\n"; // RAD
    }
    else if (!strcmp(type_of_shape, TRIANGLE))
    {
      char ** p_end = nullptr;
      petrov::point_t p1 = { std::strtod(description[0], p_end), std::strtod(description[1], p_end) };
      petrov::point_t p2 = { std::strtod(description[2], p_end), std::strtod(description[3], p_end) };
      petrov::point_t p3 = { std::strtod(description[4], p_end), std::strtod(description[5], p_end) };
      petrov::Triangle * ptr_triangle = nullptr;
      try
      {
        ptr_triangle = new petrov::Triangle(p1, p2, p3);
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
      shapes_massive[count++] = ptr_triangle;
      delete[] stream_massive;
      delete[] type_of_shape;
      for (size_t i = 0; i < created; i++)
      {
        delete[] description[i];
      }
      delete[] description;
      std::clog << "YAY!TRIANGLE\n"; // RAD
    }
    else if (!strcmp(type_of_shape, SCALE))
    {
      char ** p_end = nullptr;
      scale_point = { std::strtod(description[0], p_end), std::strtod(description[1], p_end) };
      scale_value = std::strtod(description[2], p_end);
      delete[] stream_massive;
      delete[] type_of_shape;
      for (size_t i = 0; i < created; i++)
      {
        delete[] description[i];
      }
      delete[] description;
      std::clog << "YAY2!\n"; // RAD
      break;
    }
    else
    {
      delete[] stream_massive;
      delete[] type_of_shape;
      for (size_t i = 0; i < created; i++)
      {
        delete[] description[i];
      }
      delete[] description;
    }
  }
  std::cout << "Count: " << count << "\n"; // RAD
  for (size_t i = 0; i < count; i++)
  {
    std::cout << shapes_massive[i] << "\n"; // RAD
  }
  std::cout << std::fixed << std::setprecision(1);
  petrov::scaleIsotropicallyAndOutputData(scale_point, scale_value, shapes_massive, count);
}
