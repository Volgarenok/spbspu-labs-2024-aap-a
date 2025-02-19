#include "build_shapes.hpp"
#include <exception>
#include "rectangle.hpp"
#include "ring.hpp"
#include "ellipse.hpp"
#include "square.hpp"

namespace
{
  double *readParams(std::istream &in);

  double *readParams(std::istream &in)
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

sveshnikov::Shape *sveshnikov::buildRectangle(std::istream &in)
{
  double *params = readParams(in);
  try
  {
    Rectangle *rectangle = new Rectangle({params[0], params[1]}, {params[2], params[3]});
    delete[] params;
    return rectangle;
  }
  catch (const std::exception &e)
  {
    delete[] params;
    throw;
  }
}

sveshnikov::Shape *sveshnikov::buildRing(std::istream &in)
{
  double *params = readParams(in);
  try
  {
    Ring *ring = new Ring({params[0], params[1]}, params[2], params[3]);
    delete[] params;
    return ring;
  }
  catch (const std::exception &e)
  {
    delete[] params;
    throw;
  }
}

sveshnikov::Shape *sveshnikov::buildEllipse(std::istream &in)
{
  double *params = readParams(in);
  try
  {
    Ellipse *ellipse = new Ellipse({params[0], params[1]}, params[2], params[3]);
    delete[] params;
    return ellipse;
  }
  catch (const std::exception &e)
  {
    delete[] params;
    throw;
  }
}

sveshnikov::Shape *sveshnikov::buildSquare(std::istream &in)
{
  double *params = readParams(in);
  try
  {
    Square *square = new Square({params[0], params[1]}, params[2]);
    delete[] params;
    return square;
  }
  catch (const std::exception &e)
  {
    delete[] params;
    throw;
  }
}
