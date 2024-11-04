#ifndef TAYLOR_FUN_H
#define TAYLOR_FUN_H

#include <cstddef>

namespace cherkasov
{
  double getTaylor(double x, size_t k, double error);
  double get_exp(double x);
  void generating_exception();
  void get_table(double x, double getTaylor_value, double exp_value, size_t col_width, size_t others_columns);
  void processValue(double x, size_t k, double error, size_t col_width, size_t other_columns);
}

#endif
