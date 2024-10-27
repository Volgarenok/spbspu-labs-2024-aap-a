#ifndef KOLA_H
#define KOLA_H
#include <cstddef>
namespace komarova
{
  double Teilor(double x, const size_t  k, const double error);
  double ln_Teilor(double x);
  void matherr(double x, double y);
  void output(double x, double value, double y);
}
#endif
