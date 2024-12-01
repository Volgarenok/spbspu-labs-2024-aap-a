#ifndef ISEXPRESSION_HPP
#define ISEXPRESSION_HPP

namespace shramko
{
  bool isExpression(const char* str);
  bool has_zero_or_one(const char** str);
  bool has_unsigned(const char** str);
  bool has_x_y_or_z(const char** str);
  bool has_letter_ID(const char** str);
  bool has_plus_or_minus(const char** str);
  bool has_multiplier(const char** str);
  bool has_expression(const char** str);
}

#endif
