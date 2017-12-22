#include <iostream>
#include <cmath>

#include "Rhombus.h"

const double PI = 3.14159265;

Rhombus::Rhombus() : Rhombus(0, 0) {}

Rhombus::Rhombus(std::istream &is) {
    std::cout << "Enter a side and the smaller angle of the rhombus:" << std::endl;
    is >> side >> angle;
    if(side < 0) {
        std::cerr << "Error: side should be greater than 0." << std::endl;
    }
    if(angle < 0 || angle > 180) {
        std::cerr << "Error: angle should be greater than 0 and smaller than 180." << std::endl;
    }
}

Rhombus::Rhombus(const Rhombus& orig) {
    side = orig.side;
    angle = orig.angle;
}

Rhombus::Rhombus(int a, int ang) : side(a), angle(ang) {}

std::ostream& operator <<(std::ostream &os, const Rhombus &obj)
{
    os << "Side = " << obj.side << ", angle = " << obj.angle << ", Square = " << this->Square() << std::endl;
    return os;
}

std::istream& operator >>(std::istream &is, Rhombus &obj)
{
    std::cout << "Enter side: ";
    is >> obj.side;
    std::cout << "Enter smaller angle: ";
    is >> obj.smaller_angle;
    return is;
}

bool Rhombus::operator==(const Rhombus &obj) const
{
    return angle == obj.angle && side == obj.side;
}


Rhombus Rhombus::operator=(const Rhombus &obj)
{
    if (&obj == this) {
        return *this;
    }

    angle = obj.angle;
    side = obj.side;

    return *this;
}

double Rhombus::Square() {
    return (double)(side * side * (double)sin(angle * (PI / 180)));
}

void Rhombus::Print() {
    std::cout << "Side = " << obj.side << ", angle = " << obj.angle << ", Square = " << this->Square() << std::endl;
}
