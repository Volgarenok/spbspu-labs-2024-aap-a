#include <iostream> //Заголовочный файл работы с вводом/выводом
#include <cmath> //Заголовочный файл работы с простыми мат. операциями
#include <iomanip> // Заголовочный файл работы с форматированием вывода
#include <stdexcept> // Заголовочный файл работы с обработкой ошибок
#include <sstream> // Заголовочный файл работы со строками
#include <string> // Заголовочный файл работы со строковыми классами/шаблонами
#include "taylor_functions.h" //Заголовочный файл работы с функциями лабораторной
int main() {
  try {
    std::cout << "Enter the interval boundaries (-0.5 and 0.5:)\n";
    std::string input; // Инициализация вспомогательного объекта
    std::getline(std::cin, input); // Чтение строки ввода
    std::istringstream iss(input); // Обработка строки как потока для работы с введёнными данными
    double start, end; // Инициализация start и end
    if (!(iss >> start)) { // Чтение первого числа
        std::cerr << "Incorrect interval start format\n";
        return 1;
    }
    if (!(iss >> end)) { // Чтение второго числа
        std::cerr << "incorrect interval end format\n";
        return 1;
    }
    if (iss >> start) { // Проверка коректности числа введённых аргументов
        std::cerr << "incorrect interval\n";
        return 1;
    }
    const double granInterval = 0.5;
    if (start < -granInterval || end > granInterval) { // Проверка допустимого интервала
      std::cerr << "Going beyond the allowed interval";
      return 1;
    }
    std::cout << std::left << std::setw(10) << "x" // Ввод имён столбцов таблицы
              << std::setw(15) << "Arcsin(Taylor)"
              << std::setw(15) << "Arctan(Taylor)"
              << std::setw(15) << "Sum"
              << std::setw(15) << "Arcsin(cmath)"
              << std::setw(15) << "Arctan(cmath)"
              << std::setw(15) << "Sum(cmath)\n";
    const size_t maxIter = 10; // Инициализация максимального числа результатов
    const double epsilon = 1e-6; // Инициализация точности вычисленийй
    for (double x = start; x <= end; x += 0.1) { // Вычисление результатов
      double arcsinT = arcsinTaylor(x, maxIter, epsilon);
      double arctanT = arctanTaylor(x, maxIter, epsilon);
      double arcsinC = std::asin(x);
      double arctanC = std::atan(x);
      double sumT = arcsinT + arctanT;
      double sumC = arcsinC + arctanC;
      std::cout << std::fixed << std::setprecision(6) << std::left << std::setw(10) << x // Вывод результатов
                << std::setw(15) << arcsinT
                << std::setw(15) << arctanT
                << std::setw(15) << sumT
                << std::setw(15) << arcsinC
                << std::setw(15) << arctanC
                << std::setw(15) << sumC << "\n";
    }
    return 0;
  } catch (const std::exception &e) { // Вывод ошибок
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
}
