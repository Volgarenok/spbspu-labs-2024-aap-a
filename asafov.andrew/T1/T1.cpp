#include <string>
#include <iostream>
#include <fstream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.h"

Shape ShapeFactory(unsigned long long hash, std::istream& in)
{
    if(hash == 'R'*'E'*'C'*'T')
    {
        double temp = 0;
        point_t a(0, 0);
        point_t b(0, 0);
        in>>temp;
        a.x = temp;
        in>>temp;
        a.y = temp;
        in>>temp;
        b.x = temp;
        in>>temp;
        b.y = temp;        
        Rectangle rect(a, b);
        return rect;
    }
}


int main()
{
    std::string str;
    std::cin>>str;
    unsigned long hash = 1;
    Shape* shapes = new Shape[10000];
    unsigned long long count = 0;
    // мне лень по букавам сравнивать я делаю так и меня не мучает совесть >_<
    for(unsigned long long i = 0;i<4;i++)
    {
        hash = hash*str[i];
    }
    // эти формы...
    while(hash!='S'*'C'*'A'*'L')
    {
        shapes[count] = ShapeFactory(hash, std::cin);       

        count++;
        for(unsigned long long i = 0;i<4;i++)
        {
            hash = hash*str[i];
        }
    }
    // масштабирование
    for(unsigned long long i = 0;i<count;i++)
    {
        std::cout << shapes[i].getArea() << '\n';
        shapes[i].getFrameRect();
        double scale = 0;
        std::cin >> scale;
        shapes[i].scale(scale);
        std::cout << shapes[i].getArea() << '\n';
        shapes[i].getFrameRect();
    }
    delete[] shapes;    
    return 0;
}
