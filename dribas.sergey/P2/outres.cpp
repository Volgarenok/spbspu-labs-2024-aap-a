#include <stdexcept>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <cstddef>
#include "outres.hpp"
#include "taylor.hpp"
#include <cstring>

void dribas::outline(double x, size_t koll,double error,
  size_t frstclm, size_t scndclm, size_t thrdclm, size_t frclm)
{

  double roundedX=round(x * 100000) / 100000;
  double cmathvalue = round(dribas::uno_div_cube(roundedX) * 100000) / 100000;

  try{
    double value = round(dribas::taylor(roundedX, koll, error) * 100000) / 100000;
    double absError = round(std::abs(value - cmathvalue) * 10000) / 10000;

    std::cout << std::setw(frstclm) << roundedX;
    std::cout << std::setw(scndclm) << value;
    std::cout << std::setw(thrdclm) << cmathvalue;
    std::cout << std::setw(frclm) << absError;
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
  const char * xmsg = "x";
  const char * mytaylormsg = "MyTaylorValue";
  const char * cmathmsg = "CmathTaylorValue";
  const char * absmsg = "AbsError";
  const size_t space = 2;

  size_t frstclm = std::strlen(xmsg) + space;
  size_t scndclm = std::strlen(mytaylormsg) + space;
  size_t thrdclm = std::strlen(cmathmsg) + space;
  size_t frclm = std::strlen(absmsg) + space;

  if (frstclm < 10){
    std::cout << std::setw(10) << "x";
    frstclm = 10;
  }else{
    std::cout << std::setw(frstclm)<< "x";
  }
  if (scndclm < 10){
    std::cout << std::setw(10) << "MyTaylorValue";
    scndclm = 10;
  }else{
    std::cout << std::setw(scndclm) << "MyTaylorValue";
  }
  if (thrdclm < 10){
    std::cout << std::setw(10) << "CmathTaylorValue";
    thrdclm = 10;
  }else{
    std::cout << std::setw(thrdclm) << "CmathTaylorValue";
  }
  if (frclm < 10){
    std::cout << std::setw(10) << "AbsError\n";
    frclm = 10;
  }else{
    std::cout << std::setw(frclm) << "AbsError\n";
  }

  for (auto i=left; i<right; i+=step){
   outline(i,koll,error,frstclm,scndclm,thrdclm,frclm);
  }
  outline(right,koll,error,frstclm,scndclm,thrdclm,frclm);
}
