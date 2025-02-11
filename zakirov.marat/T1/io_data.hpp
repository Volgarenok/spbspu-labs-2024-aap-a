#ifndef IO_DATA_HPP
#define IO_DATA_HPP
#include <istream>
#include "composite-shape.hpp"

namespace zakirov
{
  char * get_to_symbol(std::istream & in, size_t step, char interrupt_symbol);
  size_t get_parameters_series(std::istream & in, double * parameters);
  void get_parameters(std::istream & in, double * array, size_t size);
  void output_frame(std::ostream & out, CompositeShape & shapes, size_t id);
  void full_output(std::ostream & out, CompositeShape & shapes);
}

#endif
