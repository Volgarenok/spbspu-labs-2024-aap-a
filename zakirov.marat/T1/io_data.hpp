#ifndef IO_DATA_HPP
#define IO_DATA_HPP
#include <istream>
#include "composite-shape.hpp"

namespace zakirov
{
  double * get_parameters_series(std::istream & in);
  void get_parameters(std::istream & in, double * array, size_t size);
  void output_frame(std::ostream & out, const CompositeShape & shapes, size_t id);
  void full_output(std::ostream & out, const CompositeShape & shapes);
}

#endif
