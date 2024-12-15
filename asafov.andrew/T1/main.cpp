#include <string>
#include <iostream>
#include "base-types.hpp"
#include "outputFunctions.hpp"

using asafov::getHash;
using asafov::ShapeFactory;
using asafov::scaleShapes;

int main()
{
    Shape** shapes = new Shape*[10000];
    unsigned long long count = 0;

    // эти формы...
    unsigned long long hash = 0;
    while (true)
    {
        hash = getHash(std::cin);
        if (hash == 'S' * 'C' * 'A' * 'L')
        {
            break;
        }
        else if (hash == 0)
        {
            
        }
        else {
            shapes[count] = ShapeFactory(hash, std::cin);
            count++;
        }
    }

    // масштабирование
    point_t pos;
    double scale = 0;
    std::cin >> pos.x >> pos.y >> scale;
    scaleShapes(shapes, count, pos, scale, std::cout);
    return 0;
}
