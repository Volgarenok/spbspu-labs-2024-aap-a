#ifndef CHERKASOV_H
#define CHERKASOV_H
#include <cstddef>

namespace cherkasov 
{
  double Taylor(double x, size_t k, double error);
  double exp(double x);
  void exception();
  void table(double i, double Taylor_value, double exp_value, size_t col_width);
}

#endif

