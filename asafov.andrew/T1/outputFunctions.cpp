#include "outputFunctions.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "ring.hpp"
#include "ellipse.hpp"

// chto-to podobnoe na fabriku
Shape* asafov::ShapeFactory(unsigned long long hash, std::istream& in)
{
    if (hash == 'R' * 'E' * 'C' * 'T')
    {
        double temp = 0;
        point_t a = {};
        point_t b = {};
        in >> temp;
        a.x = temp;
        in >> temp;
        a.y = temp;
        in >> temp;
        b.x = temp;
        in >> temp;
        b.y = temp;
        Rectangle* rect = new Rectangle(a, b);
        return rect;
    }
    else if (hash == 'C' * 'I' * 'R' * 'C')
    {
        double temp = 0;
        point_t a = {};
        in >> temp;
        a.x = temp;
        in >> temp;
        a.y = temp;
        in >> temp;
        Circle* circ = new Circle(a, temp);
        return circ;
    }
    else if (hash == 'R' * 'I' * 'N' * 'G') {
        double temp = 0;
        point_t a = {};
        in >> temp;
        a.x = temp;
        in >> temp;
        a.y = temp;
        in >> temp;
        double temp2 = 0;
        in >> temp2;
        Ring* ring = new Ring(a, temp, temp2);
        return ring;
    }
    else if (hash == 'E' * 'L' * 'L' * 'I') {
        double temp = 0;
        point_t a = {};
        in >> temp;
        a.x = temp;
        in >> temp;
        a.y = temp;
        in >> temp;
        double temp2 = 0;
        in >> temp2;
        Ellipse* elli = new Ellipse(a, temp, temp2);
        return elli;
    }
    else if (hash == 'S' * 'Q' * 'U' * 'A') {
        
    }
    else if (hash == 'T' * 'R' * 'I' * 'A') {

    }
    else if (hash == 'P' * 'A' * 'R' * 'A') {

    }
    else if (hash == 'D' * 'I' * 'A' * 'M') {

    }
    else if (hash == 'R' * 'E' * 'G' * 'U') {

    }
    else if (hash == 'P' * 'O' * 'L' * 'Y') {

    }
    else if (hash == 'C' * 'O' * 'N' * 'C') {

    }
    else if (hash == 'C' * 'O' * 'M' * 'P') {

    }
}

// mnr tak udobno i tak rabotaet >_<
unsigned long asafov::getHash(std::istream& in)
{
    
    std::string str = {};
    in >> str;
    unsigned long hash = 1;
    for (unsigned long long i = 0; i < 4; i++)
    {
        hash = hash * str[i];
    }
    return hash;
}

// tut proishodit izotropnoe mashtabirovanie i vivod v konsol
void asafov::scaleShapes(Shape** shapes, unsigned long long count, point_t pos, double scale, std::ostream& out)
{
    rectangle_t rect = {};
    for (unsigned long long i = 0; i < count; i++)
    {
        rect = shapes[i][0].getFrameRect();
        out << '\n' << "Area:" << shapes[i][0].getArea() << "; Frame rectangle: " << '(' << rect.pos.x << ", " << rect.pos.y << ") " << rect.width << ' ' << rect.height << '\n';

        shapes[i][0].scale(pos, scale);
        rect = shapes[i][0].getFrameRect();
        out << "Area:" << shapes[i][0].getArea() << "; Frame rectangle: " << '(' << rect.pos.x << ", " << rect.pos.y << ") " << rect.width << ' ' << rect.height << '\n';

    }
}