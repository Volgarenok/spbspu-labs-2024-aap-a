#ifndef KOLA_H
#define KOLA_H
namespace komarova
{
  double Teilor(double x, const size_t  k, const double error);
  double ln_Teilor(double x);
  void output(double x, double value, double ln_Teilor(double x));
}
#endif
