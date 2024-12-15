#include <iostream>
#include <iomanip>
#include <string>
#include "rectangle.h"
#include "square.h"
#include "parallelogram.h"

const size_t max = 10000;
int main()
{
  cherkasov::Shape *figures[max];
  size_t count = 0;
  std::string command;
  while (std::cin >> command && command != "SCALE")
  {
    if (count >= max)
    {
      std::cerr << "Too many figures, skipping input." << std::endl;
      break;
    }
    try
    {
      if (command == "RECTANGLE")
      {
        double x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        figures[count++] = new cherkasov::Rectangle({x1, y1}, {x2, y2});
      }
      else if (command == "SQUARE")
      {
        double x, y, side;
        std::cin >> x >> y >> side;
        figures[count++] = new cherkasov::Square({x, y}, side);
      }
      else if (command == "PARALLELOGRAM")
      {
        double x1, y1, x2, y2, x3, y3;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        figures[count++] = new cherkasov::Parallelogram({x1, y1}, {x2, y2}, {x3, y3});
      }
      else
      {
        std::cerr << "Unsupported figure type: " << command << std::endl;
        std::string skip_line;
        std::getline(std::cin, skip_line);
      }
    }
    catch (const std::exception &e)
    {
      std::cerr << "Error processing input: " << e.what() << std::endl;
    }
  }
  double centerX, centerY, scaleFactor;
  std::cin >> centerX >> centerY >> scaleFactor;
  if (scaleFactor <= 0)
  {
    std::cerr << "Invalid scale factor." << std::endl;
    return 1;
  }
  double totalAreaBefore = 0.0;
  double totalAreaAfter = 0.0;
  std::cout << std::fixed << std::setprecision(1);
  for (size_t i = 0; i < count; ++i)
  {
    totalAreaBefore += figures[i]->getArea();
    cherkasov::rectangle_t frame = figures[i]->getFrameRect();
    std::cout << frame.pos.x - frame.width / 2 << " ";
    std::cout << frame.pos.y - frame.height / 2 << " ";
    std::cout << frame.pos.x + frame.width / 2 << " ";
    std::cout << frame.pos.y + frame.height / 2 << "\n";
    figures[i]->scale(scaleFactor);
    figures[i]->move(centerX - frame.pos.x, centerY - frame.pos.y);
    totalAreaAfter += figures[i]->getArea();
  }
  std::cout << totalAreaBefore << "\n";
  for (size_t i = 0; i < count; ++i)
  {
    cherkasov::rectangle_t frame = figures[i]->getFrameRect();
    std::cout << frame.pos.x - frame.width / 2 << " ";
    std::cout << frame.pos.y - frame.height / 2 << " ";
    std::cout << frame.pos.x + frame.width / 2 << " ";
    std::cout << frame.pos.y + frame.height / 2 << "\n";
  }
  std::cout << totalAreaAfter << "\n";
  for (size_t i = 0; i < count; ++i)
  {
    delete figures[i];
  }
  return 0;
}
