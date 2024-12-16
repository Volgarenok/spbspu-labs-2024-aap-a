#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include "rectangle.h"
#include "square.h"
#include "parallelogram.h"

constexpr size_t maxShapes = 10000;

int main()
{
    cherkasov::Shape* shapes[maxShapes] = {nullptr};
    size_t shapeCount = 0;
    bool rectangleImplemented = false;
    bool squareImplemented = false;
    bool parallelogramImplemented = false;

    std::string inputCommand;

    while (std::cin >> inputCommand)
    {
        if (shapeCount >= maxShapes)
        {
            std::cerr << "Error: Shape limit exceeded\n";
            break;
        }

        try
        {
            if (inputCommand == "RECTANGLE")
            {
                double x1, y1, x2, y2;
                if (std::cin >> x1 >> y1 >> x2 >> y2 && x1 < x2 && y1 < y2)
                {
                    shapes[shapeCount++] = new cherkasov::Rectangle({x1, y1}, {x2, y2});
                    rectangleImplemented = true;
                }
                else
                {
                    std::cerr << "Error: Invalid RECTANGLE parameters\n";
                }
            }
            else if (inputCommand == "SQUARE")
            {
                double x, y, length;
                if (std::cin >> x >> y >> length && length > 0)
                {
                    shapes[shapeCount++] = new cherkasov::Square({x, y}, length);
                    squareImplemented = true;
                }
                else
                {
                    std::cerr << "Error: Invalid input for SQUARE\n";
                }
            }
            else if (inputCommand == "PARALLELOGRAM")
            {
                double x1, y1, x2, y2, x3, y3;
                if (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 && (x1 != x2 || y1 != y2))
                {
                    shapes[shapeCount++] = new cherkasov::Parallelogram({x1, y1}, {x2, y2}, {x3, y3});
                    parallelogramImplemented = true;
                }
                else
                {
                    std::cerr << "Error: Invalid PARALLELOGRAM parameters\n";
                }
            }
            else if (inputCommand == "SCALE")
            {
                double scaleX, scaleY, factor;
                if (std::cin >> scaleX >> scaleY >> factor && factor > 0)
                {
                    for (size_t i = 0; i < shapeCount; ++i)
                    {
                        shapes[i]->scale(factor);
                    }
                }
                else
                {
                    std::cerr << "Error: Invalid SCALE parameters\n";
                }
            }
            else
            {
                std::cerr << "Error: Unsupported shape " << inputCommand << "\n";
                std::string remainingInput;
                std::getline(std::cin, remainingInput); // Пропускаем оставшиеся данные
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    if (!rectangleImplemented || !squareImplemented || !parallelogramImplemented)
    {
        std::cerr << "Rectangle and at least two additional shapes must be implemented\n";
        for (size_t i = 0; i < shapeCount; ++i)
        {
            delete shapes[i];
        }
        return 1;
    }

    std::cout << std::fixed << std::setprecision(1);
    double totalArea = 0.0;

    for (size_t i = 0; i < shapeCount; ++i)
    {
        if (shapes[i])
        {
            try
            {
                double area = shapes[i]->getArea();
                totalArea += area;
                std::cout << "Shape " << i + 1 << " Area: " << area << "\n";
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error: Failed to calculate area for shape " << i + 1 << ": " << e.what() << "\n";
            }
            delete shapes[i];
        }
    }

    std::cout << "Total area of all shapes: " << totalArea << "\n";
    return 0;
}
