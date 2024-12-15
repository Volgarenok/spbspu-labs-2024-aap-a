#include "input.hpp"
#include "output.hpp"
#include "shape.hpp"
#include "count_point.hpp"
#include <string>
#include <iostream>

int main()
{
  std::string names[5000] = {};
  double polygon[10000] = {};
  double* points = nullptr;
  size_t i = 0;
  size_t count_shape = 0;
  size_t count_error = 0;
  std::string name = "uwu";
  try
  {
    points = new double[10000];
  }
  catch (const std::bad_alloc & e)
  {
    delete[] points;
    std::cerr << "Out of memmory\n";
  }
  while (std::cin >> name)
  {
    if (!name.empty())
    {
      if (name == "RECTANGLE")
      {
        if (!karnauhova::input_rectangle(std::cin, points, i))
        {
          std::cin.clear();
          std::cerr << "LOL\n";
          count_error++;
        }
        else
        {
          i+=4;
          names[count_shape] = name;
          count_shape++;
        }
      }
      else if (name == "TRIANGLE")
      {
        if (!karnauhova::input_triangle(std::cin, points, i))
        {
          std::cerr << "LOL\n";
          count_error++;
        }
        else
        {
          i+=6;
          names[count_shape] = name;
          count_shape++;
        }
      }
      else if (name == "SCALE")
      {
        if (!karnauhova::input_scale(std::cin, points, i))
        {
          std::cerr << "LOL\n";
          count_error++;
        }
        else
        {
          i+=3;
          names[count_shape] = name;
          count_shape++;
        }
      }
      else
      {
        std::cerr << "Name bad\n";
        karnauhova::eat_trash(std::cin);
        count_error++;
      }
    }
  }
  if (names[count_shape-1] != "SCALE")
  {
    std::cerr << "Error: missing scale\n";
    delete[] points;
    return 1;
  }
  if (points[i] < 0)
  {
    std::cerr << "Error: missing scale\n";
    delete[] points;
    return 1;
  }
  if (count_error > 0)
  {
    std::cerr << "Error in the input\n";
  }
  for (size_t i = 0; i < 4; i++)
  {
    for (size_t j = 0; j < 4; j++)
    {
      std::cout << points[(i * 4) + j] << " ";
    }
    std::cout << names[i] << "\n";
  }
  karnauhova::output_all_shape(std::cout, points, polygon, names, i, count_shape);
}
