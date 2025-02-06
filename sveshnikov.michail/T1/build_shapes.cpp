#include "build_shapes.hpp"
#include <exception>
#include "rectangle.hpp"
#include "ring.hpp"
#include "ellipse.hpp"
#include "square.hpp"

namespace
{
  double *read_params(std::istream &in, size_t count);

  double *read_params(std::istream &in, size_t count)
  {
    double *params = new double[count];
    for (size_t i = 0; i < count; i++)
    {
      if (!(in >> params[i]))
      {
        delete[] params;
        throw std::logic_error("ERROR: Incorrect shape parameters");
      }
    }
    return params;
  }
}

void sveshnikov::build_rectangle(std::istream &in, CompositeShape &comp_shp)
{
  double *params = read_params(in, 4);
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
  double *params = read_params(in, 4);
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
  double *params = read_params(in, 4);
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
  double *params = read_params(in, 3);
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
