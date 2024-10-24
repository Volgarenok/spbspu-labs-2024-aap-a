#include <iomanip>
#include <cstring>
#include <iostream>
#include "header.hpp"

int main()
{
  double first_member = 0.0, last_member = 0.0;
  size_t max_members = 0;
  std::cin >> first_member >> last_member >> max_members;

  if (std::cin.fail()) {
    std::cerr << "Input fail" << "\n";
    return 1;
  }

  if (std::cin.bad()) {
    std::cerr << "Bad input" << "\n";
    return 1;
  }

  if (std::cin.eof()) {
    std::cerr << "EOF" << "\n";
    return 1;
  }

  if (first_member > last_member)
  {
    std::cerr << "First member can`t be greater than last";
    return 1;
  }

  const double error = 0.001;
  const double step = 0.05;
  const char * errormsg = "<MATH ERROR>";
  const size_t second_column_width = std::strlen(errormsg);
  const size_t others_columns = 10;
  size_t oth = others_columns;
  size_t snd = second_column_width;

  for (auto i = first_member ; i < last_member; i += step)
  {
    size_t oth = others_columns;
    std::cout << std::setw(oth) << i;
    std::cout << " ";
    size_t snd = second_column_width;
    try
    {
      std::cout << std::setw(snd) << kushekbaev::f(i, max_members, error);
    }
    catch (const std::logic_error & e)
    {
      std::cout << std::setw(snd) << errormsg;
    }
    std::cout << " " << std::setw(oth) << kushekbaev::stdf(i);
    std::cout << "\n";
  }
  std::cout << std::setw(oth)  << last_member;
  try
  {
    std::cout << " " << std::setw(snd) << kushekbaev::f(last_member, max_members, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << errormsg;
  }

  std::cout << std::setw(snd-1) << kushekbaev::stdf(last_member) << "\n";
}
