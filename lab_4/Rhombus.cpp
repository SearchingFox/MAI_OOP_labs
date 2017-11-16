#include <iostream>
#include <cmath>

#include "Rhombus.h"

#define PI 3.14159265

Rhombus::Rhombus() : Rhombus(0, 0) {
    //std::cout << "Rhombus created: default." << std::endl;
}

Rhombus::Rhombus(int a, int ang) : side(a), angle(ang) {
    //std::cout << "Rhombus created: " << side << ", " << angle << std::endl;
}

Rhombus::Rhombus(std::istream &is) {
    std::cout << "Enter a side and the smaller angle of the rhombus:\n";
    is >> side >> angle;
    if(side < 0) {
        std::cerr << "Error: side should be greater than 0." << std::endl;
    }
    if(angle < 0 || angle > 180) {
        std::cerr << "Error: angle should be greater than 0 and smaller than 180." << std::endl;
    }
}

Rhombus::Rhombus(const Rhombus& orig) {
    //std::cout << "Rhombus copy created." << std::endl;
    side = orig.side;
    angle = orig.angle;
}

double Rhombus::Square() {
    return (double)(side * side * (double)sin(angle * (PI / 180)));
}

void Rhombus::Print() {
    std::cout << "Side = " << side << ", angle = " << angle << std::endl;
}

Rhombus::~Rhombus() {
    //std::cout << "Rhombus deleted." << std::endl;
}

