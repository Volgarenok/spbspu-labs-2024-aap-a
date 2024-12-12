#include "input.hpp"
#include "shape.hpp"
#include "count_point.hpp"
#include <iostream>
#include <string>
#include <limits>
namespace karnauhova
{
  void eat_trash(std::istream & in);
}
void karnauhova::eat_trash(std::istream & in)
{
  in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
bool karnauhova::input(std::istream &in, double* t, std::string* names, size_t i)
{
  std::string name;
  double x1 = 0, x2 = 0;
  char n = 0;
//  for (size_t i = 0; in >> name; i++)
  //{
    in >> name;
    if (in.eof())
    {
      return false;
    }
    if (!karnauhova::count_point(name))
    {
      karnauhova::eat_trash(in);
      return false;
    }
    names[i] = name;
    for (int j = 0; j < (karnauhova::count_point(name)*2); j+=2)
    {
      in >> x1;
      {
        karnauhova::eat_trash(in);
        return false;
      }
      in >> x2;
      if (!in)
      {
        karnauhova::eat_trash(in);
        return false;
      }
      t[j+i] = x1;
      t[j+i+1] = x2;
    }
    in >> n;
    if (n != '\n' && !in.eof())
    {
      karnauhova::eat_trash(in);
      return false;
    }
  //}
  return true;
}

