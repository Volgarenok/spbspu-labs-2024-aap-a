#ifndef SPEC_DEF_HPP
#define SPEC_DEF_HPP
namespace evstyunichev
{
  constexpr double prec = 0.0000001;
  constexpr double pi_v = 3.141592653589793238462643;

  bool is_equal(double, double, double p = prec);
  bool is_int(double);
}
#endif
