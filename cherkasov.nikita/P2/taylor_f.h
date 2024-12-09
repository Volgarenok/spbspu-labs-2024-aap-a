#ifndef TAYLOR_F_H
#define TAYLOR_F_H

#include <cstddef>

namespace cherkasov
{
  double getTaylor(double x, size_t k, double error);
  double getExp(double x);
  void generatingException();
  void getTable(double x, double taylor_value, double exp_value, size_t column_width, size_t others_columns);
  void processValue(double x, size_t k, double error, size_t column_width, size_t other_columns);
}

#endif
