#include "build_shapes.hpp"
#include <exception>
#include "rectangle.hpp"
#include "ring.hpp"
#include "ellipse.hpp"
#include "square.hpp"

namespace
{
  void read_params(std::istream &in, const size_t num_params, double* params);
  
  void read_params(std::istream &in, const size_t num_params, double* params)
  {
    for (size_t i = 0; i < num_params; i++)
    {
      in >> params[i];
    }
  }
}

void sveshnikov::build_rectangle(std::istream &in, CompositeShape &comp_shp)
{
  constexpr size_t num_params = 4;
  double params[num_params] = {}; 
  read_params(std::cin, num_params, params);
  comp_shp.push_back(new Rectangle({params[0], params[1]}, {params[2], params[3]}));
}

void sveshnikov::build_ring(std::istream &in, CompositeShape &comp_shp)
{
  constexpr size_t num_params = 4;
  double params[num_params] = {}; 
  read_params(std::cin, num_params, params);
  comp_shp.push_back(new Ring({params[0], params[1]}, params[2], params[3]));
}

void sveshnikov::build_ellipse(std::istream &in, CompositeShape &comp_shp)
{
  constexpr size_t num_params = 4;
  double params[num_params] = {}; 
  read_params(std::cin, num_params, params);
  comp_shp.push_back(new Ellipse({params[0], params[1]}, params[2], params[3]));
}

void sveshnikov::build_square(std::istream &in, CompositeShape &comp_shp)
{
  constexpr size_t num_params = 3;
  double params[num_params] = {}; 
  read_params(std::cin, num_params, params);
  comp_shp.push_back(new Square({params[0], params[1]}, params[2]));
}
