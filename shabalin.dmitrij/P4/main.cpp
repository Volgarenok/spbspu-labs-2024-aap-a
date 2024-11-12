/*
#include <cstdio>
#include <iostream>

bool checkSymbol(char symbol)
{
  const char *list = "aeiouAEIOU";
  bool f = true;
  while (*list != '\0')
  {
    if (symbol == *list)
    {
      f = false;
      break;
    }
    ++list;
  }
  return f;
}

char* removeVowels(char *string)
{
  char *begin = string;
  char *result = string;
  while (*string != '\0')
  {
    if (checkSymbol(*string))
    {
      *result = *string;
      ++result;
    }
    ++string;
  }
  return begin;
}

char *inputOfString(std::istream &input, size_t &sizeOfString)
{
  char someCharacter = 0;
  size_t index = 0;
  char *initialString = reinterpret_cast< char* >(malloc(sizeof(char) * sizeOfString));
  //char *initialString = new char[sizeOfString];
  input >> std::noskipws;

  while (input >> someCharacter)
  {
    if (!input)
    {
      free(initialString);
      throw std::logic_error("Input error");
    }
    if (index == sizeOfString - 1)
    {
      try
      {
        sizeOfString *= 2;
        char *intermediateString = reinterpret_cast< char* >(malloc(sizeof(char) * sizeOfString));
        for (size_t i = 0; i < index; ++i)
        {
          intermediateString[i] = initialString[i];
        }
        free(initialString);
        initialString = intermediateString;
      }
      catch (std::bad_alloc &e)
      {
        free(initialString);
        throw;
      }
    }
    initialString[index] = someCharacter;
    index++;
  }
  return initialString;
}

int main()
{
  char *inputString = nullptr;
  size_t stringSize = 10;
  try
  {
    inputString = inputOfString(std::cin, stringSize);
    if (inputString[0] == '\0')
    {
      free(inputString);
      std::cerr << "Error" << "\n";
      return 1;
    }
  }
  catch (const std::logic_error &e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  removeVowels(inputString);
  std::cout << inputString << "\n";
  free(inputString);
  return 0;
}
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <stdexcept>

bool checkSymbol(char symbol)
{
  const char *list = "aeiouAEIOU";
  while (*list != '\0')
  {
    if (symbol == *list)
    {
      return false;
    }
    ++list;
  }
  return true;
}

char *removeVowels(char *string)
{
  char *result = string;
  // Проходим по оригинальной строке
  for (char *current = string; *current != '\0'; ++current)
  {
    if (checkSymbol(*current))
    {
      *result++ = *current; // сохраняем только нерегулярные символы
    }
  }
  *result = '\0'; // завершаем строку
  return string;  // Возвращаем указатель на начало строки
}

char *inputOfString(std::istream &input, size_t &sizeOfString)
{
  char someCharacter = 0;
  size_t index = 0;
  char *initialString = reinterpret_cast<char *>(malloc(sizeof(char) * sizeOfString));

  if (!initialString)
  {
    throw std::bad_alloc(); // Обрабатываем ошибку выделения памяти
  }

  input >> std::noskipws;

  while (input >> someCharacter)
  {
    if (index == sizeOfString - 1)
    { // Проверяем необходимость увеличения размера
      sizeOfString *= 2;
      char *intermediateString = reinterpret_cast<char *>(realloc(initialString, sizeof(char) * sizeOfString));
      if (!intermediateString)
      {
        free(initialString);    // Освобождаем память в случае ошибки
        throw std::bad_alloc(); // Обрабатываем ошибку выделения памяти
      }
      initialString = intermediateString; // Обновляем указатель
    }
    initialString[index++] = someCharacter;
  }
  initialString[index] = '\0'; // Завершаем строку
  return initialString;
}

int main()
{
  char *inputString = nullptr;
  size_t stringSize = 10;

  try
  {
    inputString = inputOfString(std::cin, stringSize);
    if (inputString[0] == '\0')
    {
      free(inputString);
      std::cerr << "Error: Empty input\n";
      return 1;
    }
  }
  catch (const std::logic_error &e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Error: Memory allocation failed\n";
    return 1;
  }

  // Удаляем гласные из строки
  removeVowels(inputString);
  std::cout << inputString << "\n";

  free(inputString); // Освобождаем выделенную память
  return 0;
}