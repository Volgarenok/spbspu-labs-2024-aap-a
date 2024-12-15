#ifndef CHECK_HPP
#define CHECK_HPP
#include <string>
namespace karnauhova
{
  bool it_polygon(double* polygon, size_t max_count, size_t count);
  bool it_triangle(double* points, size_t c_points);
  bool dubl_rectangle(double* points, std::string* names, size_t c_names, size_t c_points);
  bool dubl_triangle(double* points, std::string* names, size_t c_names, size_t c_points);
  bool dubl_pol(double* polygon, size_t end_pol, std::string* names, size_t c_names, size_t c_points, double* points);
}
#endif
