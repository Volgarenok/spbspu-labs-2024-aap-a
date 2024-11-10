#include <iostream>
#include <ios>

int main()
{
  std::size_t len = 100;
  char * str = new char[len+1];
  char * new_str = nullptr;
  std::size_t size = 0;
  char c = '\0';
  std::noskipws(std::cin);
  while ((std::cin >> c) && (c != '\n'))
  {
    if (size == len)
    {
      //выделить новую память большего объёма
      // - может генерироваться исключение
      // перенести данные из старого массива
      // удалить старый массив
    }
    str[size++] = c;
  }
  new_str = sveshnikov::rep_sym_hpp(std::cin, c)
  // задание варианта

  std::skipws(std::cin);

}

std::istream &sveshnikov::read_str(std::istream &in, char *matrix)
{
  for (size_t i = 0; std::cin != '\n'; i++)
  {
    in >> matrix[read];
    read++;
  }
  return in;
}