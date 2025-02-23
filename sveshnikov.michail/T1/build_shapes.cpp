#include "build_shapes.hpp"
#include <exception>
#include "rectangle.hpp"
#include "ring.hpp"
#include "ellipse.hpp"
#include "square.hpp"

namespace
{
  sveshnikov::Rectangle *buildRectangle(std::istream &in);
  sveshnikov::Ring *buildRing(std::istream &in);
  sveshnikov::Ellipse *buildEllipse(std::istream &in);
  sveshnikov::Square *buildSquare(std::istream &in);
  double *readParams(std::istream &in);

  sveshnikov::Rectangle *buildRectangle(std::istream &in)
  {
    double *params = readParams(in);
    sveshnikov::Rectangle *rectangle = nullptr;
    try
    {
      rectangle = new sveshnikov::Rectangle({params[0], params[1]}, {params[2], params[3]});
      delete[] params;
      return rectangle;
    }
    catch (const std::exception &e)
    {
      delete[] params;
      throw;
    }
  }

  sveshnikov::Ring *buildRing(std::istream &in)
  {
    double *params = readParams(in);
    sveshnikov::Ring *ring = nullptr;
    try
    {
      ring = new sveshnikov::Ring({params[0], params[1]}, params[2], params[3]);
      delete[] params;
      return ring;
    }
    catch (const std::exception &e)
    {
      delete[] params;
      throw;
    }
  }

  sveshnikov::Ellipse *buildEllipse(std::istream &in)
  {
    double *params = readParams(in);
    sveshnikov::Ellipse *ellipse = nullptr;
    try
    {
      ellipse = new sveshnikov::Ellipse({params[0], params[1]}, params[2], params[3]);
      delete[] params;
      return ellipse;
    }
    catch (const std::exception &e)
    {
      delete[] params;
      throw;
    }
  }

  sveshnikov::Square *buildSquare(std::istream &in)
  {
    double *params = readParams(in);
    sveshnikov::Square *square = nullptr;
    try
    {
      square = new sveshnikov::Square({params[0], params[1]}, params[2]);
      delete[] params;
      return square;
    }
    catch (const std::exception &e)
    {
      delete[] params;
      throw;
    }
  }

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

sveshnikov::Shape *sveshnikov::buildShape(std::istream &in, std::string shape_name)
{
  if (shape_name == "RECTANGLE")
  {
    return buildRectangle(in);
  }
  else if (shape_name == "RING")
  {
    return buildRing(in);
  }
  else if (shape_name == "ELLIPSE")
  {
    return buildEllipse(in);
  }
  else if (shape_name == "SQUARE")
  {
    return buildSquare(in);
  }
  throw std::logic_error("Unknown name of the shape");
}
