#include <iostream>
#include <cmath>

#include "Pentagon.h"

const double PI = 3.14159265;

Pentagon::Pentagon() : Pentagon(0) {}

Pentagon::Pentagon(std::istream &is) {
    std::cout << "Enter a side of the Pentagon:" << std::endl;
    is >> side;
    if(side < 0) {
        std::cerr << "Error: sides should be greater than 0." << std::endl;
    }
}

Pentagon::Pentagon(const Pentagon& orig) {
    side = orig.side;
}

Pentagon::Pentagon(int a) : side(a) {}

std::ostream& operator<<(std::ostream& os, const Pentagon& obj) {
    os << "Sides = " << side << ", Square = " << this->Square() << std::endl;
    return os;
}

std::istream& operator>>(std::istream &is, Pentagon &obj)
{
    std::cout << "Enter side: ";
    is >> obj.side;
    return is;
}

bool Pentagon::operator==(const Pentagon &obj) const
{
    return side == obj.side;
}

Pentagon Pentagon::operator=(const Pentagon &obj)
{
    if (&obj == this) {
        return *this;
    }
    side = obj.side;
    return *this;
}

double Pentagon::Square() {
    return (double)(5 * side * side / (4 * (double)tan(36.0 * (PI / 180.0))));
}

void Pentagon::Print() {
    std::cout << "Sides = " << side << ", Square = " << this->Square() << std::endl;
}
