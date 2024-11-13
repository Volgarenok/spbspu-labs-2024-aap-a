#include <iostream>
#include <cstddef>
#include <ios>
#include <string.h>
//Написать функцию которая возвращает указатель на строку с выделением динамической памяти new/delete
//Прописать условия на выделение новой памяти
// обработка исключений
//перенести данные из старого массива
//удалить старый массив
//задание варианта
//со слишком маленькой строкой поработать
int main()
{
  try
  {
    constexpr std::size_t max = 10;
    char str[max + 1] = {};
    std::size_t size = 0;
    char c = '\0';
    std::noskipws(std::cin);
    while ((std::cin >> c) && (c != '\n') && (size < max))
    {
      str[size++] = c;
    }
      std::skipws(std::cin);

  if (std::cin.bad())
  {
    std::cerr << "Ошибка ввода данных\n";
    return 1;
  }

  if (size == 0)
  {
  std::cerr << "Ошибка: пустая строка\n";
  return 1;
  }

  if (size > max)
  {
    std::cerr << "Ошибка: строка превышает максимальный размер\n";
    return 1;
  }

  char * result = cherkasov::getString(str, size);
  if (result)
  {
    std::cout << result << "\n";
    delete[] result;
  }

 }
   catch (const std::exception & e)
   {
     std::cerr << "Произошло исключение: " << e.what() << "\n";
     return 1;
   }

    return 0;
}
