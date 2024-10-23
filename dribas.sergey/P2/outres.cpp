#include <iomanip>
#include <cmath>
#include <iostream>
#include <cstddef>
#include "outres.hpp"
#include "taylor.hpp"

void dribas::outline(double x, size_t koll,double error){
  double value = dribas::taylor(x,koll,error);
  double cmathvalue = dribas::uno_div_cube(x);
  double absError = abs(value-cmathvalue);
  try{
    std::cout << std::setw(10) << x;
    std::cout << std::setw(20) << value;
    std::cout << std::setw(20) << cmathvalue;
    std::cout << std::setw(20) << absError;
    std::cout << "\n";
  }catch(std::logic_error & e){
    std::cerr << e.what();
  }
}

void dribas::outall(double left, double right, double step,size_t koll, double error)
{
  std::cout << std::setw(10) << "x";
  std::cout << std::setw(20) << "MyTylorValue";
  std::cout << std::setw(20) << "CmathTaylorValue";
  std::cout << std::setw(20) << "AbsError\n";
  for (auto i=left; i<right; i+=step){
   outline(i,koll,error);
  }
  outline(right,koll,error);
}
