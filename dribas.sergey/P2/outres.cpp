#include "outres.hpp"
#include "taylor.hpp"
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <cstddef>
#include <cstring>

void dribas::outline(double x, size_t koll, double error, int sizeclm)
{
  double cmathvalue = dribas::getCmathValue(x);
  try{
    double value = dribas::getTaylor(x, koll, error);
    std::cout << std::setw(sizeclm) << std::setprecision(2) << std::fixed << x;
    std::cout << std::setw(sizeclm) << std::setprecision(6) << std::fixed << value;
    std::cout << std::setw(sizeclm) << std::setprecision(6) << std::fixed << cmathvalue;
  }catch (const std::exception & e){
    std::cerr << std::setw(sizeclm) << std::setprecision(2) << std::fixed << x;
    std::cerr << std::setw(sizeclm) << e.what();
    std::cerr << std::setw(sizeclm) << std::setprecision(6) << std::fixed << cmathvalue;
  }
}

void dribas::outall(double left, double right, double step, size_t koll, double error)
{
  const char * xmsg = "X";
  const char * mytaylormsg = "MyTaylorValue";
  const char * cmathmsg = "CmathTaylorValue";
  const size_t space = 2;

  int frstclm = std::strlen(xmsg) + space;
  int scndclm = std::strlen(mytaylormsg) + space;
  int thrdclm = std::strlen(cmathmsg) + space;
  int sizeclm = 0;

  frstclm = std::max(10, frstclm);
  scndclm = std::max(frstclm, scndclm);
  sizeclm = std::max(scndclm, thrdclm);

  std::cout << std::setw(sizeclm) << xmsg;
  std::cout << std::setw(sizeclm) << mytaylormsg;
  std::cout << std::setw(sizeclm) << cmathmsg;
  std::cout << "\n";

  for (auto i = left; i < right; i += step){
    outline(i, koll, error, sizeclm);
    std::cout << "\n";
  }
  outline(right, koll, error, sizeclm);
  std::cout << "\n";
}
