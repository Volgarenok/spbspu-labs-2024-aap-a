#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <input_cstring.hpp>
#include "shape.hpp"
#include "base-types.hpp"
#include "clear_memory.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "concave.hpp"
#include "scale_isotropically_and_output_data.hpp"
int main()
{
  const char * ERROR_MSG = "ERROR: Invalid data somewhere";
  const char RECTANGLE[10] = "RECTANGLE";
  const char TRIANGLE[9] = "TRIANGLE";
  const char SCALE[6] = "SCALE";
  const char CONCAVE[8] = "CONCAVE";
  petrov::Shape * shapes_massive[10000] = {};
  size_t count = 0;
  size_t count_errors = 0;
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
      stream_massive = petrov::inputCString(std::cin, capacity);
      if (std::cin.eof())
      {
        delete[] stream_massive;
        for (size_t i = 0; i < count; i++)
        {
          delete shapes_massive[i];
        }
        std::cerr << "End of file\n";
        return 2;
      }
      else if (!std::cin || stream_massive[0] == '\n')
      {
        delete[] stream_massive;
        continue;
      }
      size_t length_of_word = 0;
      while (stream_massive[length_of_word] != ' ')
      {
        length_of_word++;
      }
      length_of_word++;
      type_of_shape = new char[length_of_word];
      description = new char * [number_of_doubles];
      for (size_t i = 0; i < number_of_doubles; i++)
      {
        description[i] = new char[capacity];
        created++;
      }
    }
    catch (const std::bad_alloc & e)
    {
      petrov::clearMemory(stream_massive, type_of_shape, description, created);
      std::cerr << "ERROR: Out of memory\n";
      return 1;
    }
    for (size_t i = 0; i < number_of_doubles; i++)
    {
      for (size_t j = 0; j < capacity; j++)
      {
        description[i][j] = '0';
      }
    }
    size_t i = 0;
    while (stream_massive[i] != ' ')
    {
      type_of_shape[i] = stream_massive[i];
      i++;
    }
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
    description[j][k] = '\0';
    if (!strcmp(type_of_shape, RECTANGLE))
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
        petrov::clearMemory(stream_massive, type_of_shape, description, created);
        std::cerr << "ERROR: Out of memory\n";
        return 1;
      }
      catch (const char * error)
      {
        count_errors++;
        petrov::clearMemory(stream_massive, type_of_shape, description, created);
        continue;
      }
      shapes_massive[count++] = ptr_rectangle;
      petrov::clearMemory(stream_massive, type_of_shape, description, created);
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
        petrov::clearMemory(stream_massive, type_of_shape, description, created);
        std::cerr << "ERROR: Out of memory\n";
        return 1;
      }
      catch (const char * error)
      {
        count_errors++;
        petrov::clearMemory(stream_massive, type_of_shape, description, created);
        continue;
      }
      shapes_massive[count++] = ptr_triangle;
      petrov::clearMemory(stream_massive, type_of_shape, description, created);
    }
    else if (!strcmp(type_of_shape, CONCAVE))
    {
      char ** p_end = nullptr;
      petrov::point_t p1 = { std::strtod(description[0], p_end), std::strtod(description[1], p_end) };
      petrov::point_t p2 = { std::strtod(description[2], p_end), std::strtod(description[3], p_end) };
      petrov::point_t p3 = { std::strtod(description[4], p_end), std::strtod(description[5], p_end) };
      petrov::point_t p4 = { std::strtod(description[6], p_end), std::strtod(description[7], p_end) };
      petrov::Concave * ptr_concave = nullptr;
      try
      {
        ptr_concave = new petrov::Concave(p1, p2, p3, p4);
      }
      catch (const std::bad_alloc & e)
      {
        petrov::clearMemory(stream_massive, type_of_shape, description, created);
        std::cerr << "ERROR: Out of memory\n";
        return 1;
      }
      catch (const char * error)
      {
        count_errors++;
        petrov::clearMemory(stream_massive, type_of_shape, description, created);
        continue;
      }
      shapes_massive[count++] = ptr_concave;
      petrov::clearMemory(stream_massive, type_of_shape, description, created);
    }
    else if (!strcmp(type_of_shape, SCALE))
    {
      if (count == 0)
      {
        petrov::clearMemory(stream_massive, type_of_shape, description, created);
        std::cerr << "ERROR: Nothing to scale\n";
        return 4;
      }
      char ** p_end = nullptr;
      scale_point = { std::strtod(description[0], p_end), std::strtod(description[1], p_end) };
      scale_value = std::strtod(description[2], p_end);
      if (scale_value <= 0)
      {
        petrov::clearMemory(stream_massive, type_of_shape, description, created);
        for (size_t i = 0; i < count; i++)
        {
          delete shapes_massive[i];
        }
        std::cerr << "ERROR: Invalid scale value\n";
        return 3;
      }
      petrov::clearMemory(stream_massive, type_of_shape, description, created);
      break;
    }
    else
    {
      petrov::clearMemory(stream_massive, type_of_shape, description, created);
    }
  }
  std::cout << std::fixed << std::setprecision(1);
  petrov::scaleIsotropicallyAndOutputData(scale_point, scale_value, shapes_massive, count);
  for (size_t i = 0; i < count; i++)
  {
    delete shapes_massive[i];
  }
  if (count_errors > 0)
  {
    std::cerr << ERROR_MSG << "\n";
  }
}
