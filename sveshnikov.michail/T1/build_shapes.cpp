#include "build_shapes.hpp"
#include <exception>
#include "rectangle.hpp"
#include "ring.hpp"
#include "ellipse.hpp"
#include "square.hpp"

namespace
{
  double *read_params(std::istream &in);

  double *read_params(std::istream &in)
  {
    size_t size = 5;
    double *params = new double[size];
    size_t i = 0;
    while (in >> params[i])
    {
      i++;
      if (i == size)
      {
        size_t new_size = size + 5;
        double *new_params = new double[new_size];
        for (size_t j = 0; j < size; j++)
        {
          new_params[j] = params[j];
        }
        delete[] params;
        params = new_params;
      }
    }
    if (in.fail() && !in.eof())
    {
      in.clear();
    }
    return params;
  }
}

void sveshnikov::build_rectangle(std::istream &in, CompositeShape &comp_shp)
{
  double *params = read_params(in);
  try
  {
    comp_shp.push_back(new Rectangle({params[0], params[1]}, {params[2], params[3]}));
  }
  catch (const std::exception &e)
  {
    delete[] params;
    throw;
  }
  delete[] params;
}

void sveshnikov::build_ring(std::istream &in, CompositeShape &comp_shp)
{
  double *params = read_params(in);
  try
  {
    comp_shp.push_back(new Ring({params[0], params[1]}, params[2], params[3]));
  }
  catch (const std::exception &e)
  {
    delete[] params;
    throw;
  }
  delete[] params;
}

void sveshnikov::build_ellipse(std::istream &in, CompositeShape &comp_shp)
{
  double *params = read_params(in);
  try
  {
    comp_shp.push_back(new Ellipse({params[0], params[1]}, params[2], params[3]));
  }
  catch (const std::exception &e)
  {
    delete[] params;
    throw;
  }
  delete[] params;
}

void sveshnikov::build_square(std::istream &in, CompositeShape &comp_shp)
{
  double *params = read_params(in);
  try
  {
    comp_shp.push_back(new Square({params[0], params[1]}, params[2]));
  }
  catch (const std::exception &e)
  {
    delete[] params;
    throw;
  }
  delete[] params;
}
