#ifdef FUNCTIONS_HPP
#define FUNCTIONS_HPP
namespace gavrilova{
  double v_taylor (double x, size_t k, double error);
  double v_cmath (double x);
  void output_str(size_t num, double v_taylor, double v_cmath);
  void output_str(size_t num, const char *, double v_cmath);
}
#endif

