#include <iostream> //Заголовочный файл работы с вводом/выводом
#include <cmath> //Заголовочный файл работы с простыми мат. операциями
#include <iomanip> // Заголовочный файл работы с форматированием вывода
#include <stdexcept> // Заголовочный файл работы с обработкой ошибок
#include <sstream> // Заголовочный файл работы со строками
#include <string> // Заголовочный файл работы со строковыми классами/шаблонами
#include "taylor_functions.h" //Заголовочный файл работы с функциями лабораторной
int main() {
  try {
    std::cout << "Enter the interval boundaries (-0.5 and 0.5) and max number of sum value:\n";
    std::string input; // Инициализация вспомогательного объекта
    std::getline(std::cin, input); // Чтение строки ввода
    std::istringstream iss(input); // Обработка строки как потока для работы с введёнными данными
    double start, end; // Инициализация start и end
    size_t maxNumber_of_iter; // Инициализация максимального числа слагаемых
    if (!(iss >> start) || !(iss >> end) || !(iss >> maxNumber_of_iter)) { // Проверка соответствия типов введённых значений
      std::cerr << "Incorrect value format\n";
      return 1;
    }
    if (iss >> start) { // Проверка корректнсти числа введённых значений
      std::cerr << "A lot of value\n";
      return 1;
    }
    const size_t maxIter = 10; // Границы допустимых интеррвалов
    const double minGranInterval = -0.5;
    const double maxGranInterval = 0.5;
    if (start < minGranInterval || end > maxGranInterval || maxNumber_of_iter > maxIter) { // Проверка допустимых интервалов
      std::cerr << "Going beyond the allowed interval";
      return 1;
    }
    std::cout << std::left << std::setw(15) << "x" // Ввод имён столбцов таблицы
              << std::setw(15) << "Arcsin(Taylor)"
              << std::setw(15) << "Arctan(Taylor)"
              << std::setw(15) << "Sum"
              << std::setw(15) << "Arcsin(cmath)"
              << std::setw(15) << "Arctan(cmath)"
              << std::setw(15) << "Sum(cmath)\n";
    const double epsilon = 1e-6; // Инициализация точности вычисленийй
    for (double x = start; x <= end; x += 0.1) { // Вычисление результатов
      double arcsinT = arcsinTaylor(x, maxNumber_of_iter, epsilon);
      double arctanT = arctanTaylor(x, maxNumber_of_iter, epsilon);
      double arcsinC = std::asin(x);
      double arctanC = std::atan(x);
      double sumT = arcsinT + arctanT;
      double sumC = arcsinC + arctanC;
      if (arcsinT == 100.0 && arctanT == 100.0) {
        std::cout << std::fixed << std::setprecision(6) << std::left << std::setw(15) << x // Вывод результатов с учётом не соответсвия точности
                << std::setw(15) << "<MATH ERROR>"
                << std::setw(15) << "<MATH ERROR>"
                << std::setw(15) << "<MATH ERROR>"
                << std::setw(15) << arcsinC
                << std::setw(15) << arctanC
                << std::setw(15) << sumC << "\n";
      }
      else if (arctanT == 100.0) {
        std::cout << std::fixed << std::setprecision(6) << std::left << std::setw(15) << x
                << std::setw(15) << arcsinT
                << std::setw(15) << "<MATH ERROR>"
                << std::setw(15) << "<MATH ERROR>"
                << std::setw(15) << arcsinC
                << std::setw(15) << arctanC
                << std::setw(15) << sumC << "\n";
      }
      else if (arcsinT == 100.0) {
        std::cout << std::fixed << std::setprecision(6) << std::left << std::setw(15) << x // Вывод результатов в случие не соответсвии точност>                << std::setw(15) << arcsinT
                << std::setw(15) << "<MATH ERROR>"
                << std::setw(15) << arctanT
                << std::setw(15) << "<MATH ERROR>"
                << std::setw(15) << arcsinC
                << std::setw(15) << arctanC
                << std::setw(15) << sumC << "\n";
      }
      else {
        std::cout << std::fixed << std::setprecision(6) << std::left << std::setw(15) << x // Вывод результатов
                  << std::setw(15) << arcsinT
                  << std::setw(15) << arctanT
                  << std::setw(15) << sumT
                  << std::setw(15) << arcsinC
                  << std::setw(15) << arctanC
                  << std::setw(15) << sumC << "\n";
      }
    }
    return 0;
  } catch (const std::exception &e) { // Вывод ошибок
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
}
