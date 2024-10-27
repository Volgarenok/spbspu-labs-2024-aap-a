#ifndef TAYLOR_OUTPUT_HPP
#define TAYLOR_OUTPUT_HPP
#include <stdexcept>
#include <cstddef>
namespace nikonov
{
  void stringOutput(const double& x, const double& val, const double& stdval);
  void stringOutput(const double& x, const std::logic_error& e, const double& stdval);
}
#endif
