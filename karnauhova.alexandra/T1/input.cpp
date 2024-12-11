#include "input.hpp"
#include "shape.hpp"
#include "count_point.hpp"
#include <iostream>
#include <string>
bool karnauhova::input(std::istream &in, double* t, std::string* names)
{
  std::string name;
  double x1 = 0, x2 = 0;
  char n = 0;
  for (size_t i = 0; true; i++)
  {
    in >> name;
    if (!in.eof())
    {
      return false;
    }
    if (!karnauhova::count_point(name))
    {
      return false;
    }
    names[i] = name;
    for (int j = 0; j < (karnauhova::count_point(name)*2); j+=2)
    {
      in >> x1;
      in >> x2;
      if (!in)
      {
        return false;
      }
      t[j+i] = x1;
      t[j+i+1] = x2;
    }
    std::cin >> n;
    if (n != '\n' && in.eof())
    {
      return false;
    }
  }
  return true;
}
