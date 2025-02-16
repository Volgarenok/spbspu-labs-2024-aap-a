#include "build_shapes.hpp"
#include <exception>
#include "rectangle.hpp"
#include "ring.hpp"
#include "ellipse.hpp"
#include "square.hpp"

namespace
{
  double *read_params(std::istream &in);
  void push_back(sveshnikov::Shape *shp, sveshnikov::CompositeShape &comp_shp);

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

  void push_back(sveshnikov::Shape *shp, sveshnikov::CompositeShape &comp_shp)
  {
    try
    {
      comp_shp.push_back(shp);
    }
    catch (const std::exception &e)
    {
      delete shp;
      throw;
    }
  }
}

void sveshnikov::build_rectangle(std::istream &in, CompositeShape &comp_shp)
{
  double *params = read_params(in);
  try
  {
    Rectangle *rectangle = new Rectangle({params[0], params[1]}, {params[2], params[3]});
    push_back(rectangle, comp_shp);
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
    Ring *ring = new Ring({params[0], params[1]}, params[2], params[3]);
    push_back(ring, comp_shp);
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
    Ellipse *ellipse = new Ellipse({params[0], params[1]}, params[2], params[3]);
    push_back(ellipse, comp_shp);
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
    Square *square = new Square({params[0], params[1]}, params[2]);
    push_back(square, comp_shp);
  }
  catch (const std::exception &e)
  {
    delete[] params;
    throw;
  }
  delete[] params;
}
