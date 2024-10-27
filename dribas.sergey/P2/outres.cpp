#include <stdexcept>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <cstddef>
#include "outres.hpp"
#include "taylor.hpp"
#include <cstring>

void dribas::outline(double x, size_t koll, double error, int sizeclm)
{
  double roundedX=round(x * 100000) / 100000;
  double cmathvalue = round(dribas::getCmathValue(roundedX) * 100000) / 100000;
  try
  {
   double value = round(dribas::getTaylor(roundedX, koll, error) * 100000) / 100000;

   std::cout << std::setw(sizeclm) << roundedX;
   std::cout << std::setw(sizeclm) << value;
   std::cout << std::setw(sizeclm) << cmathvalue;
   std::cout << "\n";
  }
  catch (const std::exception & e)
  {
   std::cerr << std::setw(sizeclm) << roundedX;
   std::cerr << std::setw(sizeclm) << e.what();
   std::cerr << std::setw(sizeclm) << cmathvalue;
   std::cerr << "\n";
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

  for (auto i=left; i<right; i+=step)
  {
   outline(i, koll, error, sizeclm);
  }
  outline(right, koll, error, sizeclm);
}
