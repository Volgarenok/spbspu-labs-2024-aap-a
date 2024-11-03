#include "cmd_parameters.h"
#include <istream>
#include <cstddef>
std::istream& alymova::input_size(std::istream& input, size_t& rows, size_t& cols)
{
  input >> rows >> cols;
  return input;
}
