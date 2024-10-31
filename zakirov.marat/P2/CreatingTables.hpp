#ifndef CREATINGTABLES_HPP
#define CREATINGTABLES_HPP

namespace zakirov
{
  void tylor_string(double point, size_t addition_depth, const double &error);
  void tylor_table(double left, double right, size_t addition_depth,
      const double &kStep, const double &kError);
}

#endif
