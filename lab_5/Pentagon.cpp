#include <iostream>
#include <cmath>

#include "Pentagon.h"

const double PI = 3.14159265;

Pentagon::Pentagon() : Pentagon(0) {
    //std::cout << "Pentagon created: default." << std::endl;
}

Pentagon::Pentagon(int a) : side(a) {
    //std::cout << "Pentagon created: " << side << std::endl;
}

Pentagon::Pentagon(std::istream &is) {
    std::cout << "Enter a side of the Pentagon:\n";
    is >> side;
    if(side < 0) {
        std::cerr << "Error: sides should be greater than 0." << std::endl;
    }
}

Pentagon::Pentagon(const Pentagon& orig) {
    //std::cout << "Pentagon copy created." << std::endl;
    side = orig.side;
}

std::ostream& operator<<(std::ostream& os, const Pentagon& obj) {
    os << "Sides = " << obj.side << std::endl;
    return os;
}

double Pentagon::Square() {
    return (double)(5 * side * side / (4 * (double)tan(36.0 * (PI / 180.0))));
}

void Pentagon::Print() {
    std::cout << "Sides = " << side << std::endl;
}

Pentagon::~Pentagon() {
    //std::cout << "Pentagon deleted." << std::endl;
}

