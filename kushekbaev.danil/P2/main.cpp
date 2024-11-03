#include <iomanip>
#include <cstring>
#include <iostream>
#include "sinh_taylor_calculator.hpp"

int main()
{
  double first_member = 0.0, last_member = 0.0;
  size_t max_members = 0;
  std::cin >> first_member >> last_member >> max_members;

  if (std::cin.fail())
  {
    std::cerr << "Input fail" << "\n";
    return 1;
  }

  if (std::cin.bad())
  {
    std::cerr << "Bad input" << "\n";
    return 1;
  }

  if (std::cin.eof())
  {
    std::cerr << "EOF" << "\n";
    return 1;
  }

  if (first_member > last_member)
  {
    std::cerr << "First member can`t be greater than last" << "\n";
    return 1;
  }

  constexpr double error = 0.001;
  constexpr double step = 0.05;
  constexpr const char * errormsg = "<MATH ERROR>";
  constexpr size_t second_column_width = std::strlen(errormsg);
  constexpr size_t others_columns = 10;
  constexpr size_t snd = second_column_width;
  constexpr size_t oth = others_columns;

  for (auto i = first_member; i < last_member; i += step)
  {
    kushekbaev::printWidth(std::cout, oth, i);
    std::cout << " ";
    kushekbaev::printResult(i, snd, oth, max_members, error);
    std::cout << "\n";
  }

  std::cout << std::setw(oth) << last_member;
  std::cout << " " << std::setw(snd) << kushekbaev::taylorCalc(last_member, max_members, error);
  std::cout << " " << std::setw(oth) << kushekbaev::sinhCalc(last_member);
  std::cout << "\n";
}
