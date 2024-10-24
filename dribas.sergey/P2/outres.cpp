#include <stdexcept>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <cstddef>
#include "outres.hpp"
#include "taylor.hpp"
#include <cstring>

void dribas::outline(double x, size_t koll,double error,
  size_t frstclm, size_t scndclm, size_t thrdclm)
{

  double roundedX=round(x * 100000) / 100000;
  double cmathvalue = round(dribas::uno_div_cube(roundedX) * 100000) / 100000;

  try{
    double value = round(dribas::taylor(roundedX, koll, error) * 100000) / 100000;

    std::cout << std::setw(frstclm) << roundedX;
    std::cout << std::setw(scndclm) << value;
    std::cout << std::setw(thrdclm) << cmathvalue;
    std::cout << "\n";
  }catch(const std::exception & e){
    std::cerr << std::setw(frstclm) << roundedX;
    std::cerr << std::setw(scndclm) << e.what();
    std::cerr << std::setw(thrdclm) << cmathvalue;
    std::cerr << "\n";
   }
}

void dribas::outall(double left, double right,
  double step,size_t koll, double error)
{
  const char * xmsg = "X";
  const char * mytaylormsg = "MyTaylorValue";
  const char * cmathmsg = "CmathTaylorValue";
  const size_t space = 2;

  size_t frstclm = std::strlen(xmsg) + space;
  size_t scndclm = std::strlen(mytaylormsg) + space;
  size_t thrdclm = std::strlen(cmathmsg) + space;

  if (frstclm < 10){
    std::cout << std::setw(10) << xmsg;
    frstclm = 10;
  }else{
    std::cout << std::setw(frstclm) << xmsg;
  }
  if (scndclm < 10){
    std::cout << std::setw(10) << mytaylormsg;
    scndclm = 10;
  }else{
    std::cout << std::setw(scndclm) << mytaylormsg;
  }
  if (thrdclm < 10){
    std::cout << std::setw(10) << cmathmsg;
    thrdclm = 10;
  }else{
    std::cout << std::setw(thrdclm) << cmathmsg;
    std::cout << "\n";
  }

  for (auto i=left; i<right; i+=step){
   outline(i,koll,error,frstclm,scndclm,thrdclm);
  }
  outline(right,koll,error,frstclm,scndclm,thrdclm);
}
