#ifndef BESHIMOW_OUTPUT_HPP
#define BESHIMOW_OUTPUT_HPP

namespace beshimow {
  void print_header();
  void print_footer();
  void print_line(double x, double taylor, double exact, bool error);
}

#endif
