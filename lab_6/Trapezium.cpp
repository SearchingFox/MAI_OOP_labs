#include <iostream>
#include <cmath>

#include "Trapezium.h"

Trapezium::Trapezium() : Trapezium(0, 0, 0, 0) {}

Trapezium::Trapezium(std::istream &is) {
    std::cout << "Enter the sides of the Trapezium:" << std::endl;
    is >> sm_base >> lg_base >> lf_side >> rt_side;
    
    if(sm_base < 0 || lg_base < 0 || lf_side < 0 || rt_side < 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
}

Trapezium::Trapezium(const Trapezium& orig) {   
    sm_base = orig.sm_base;
    lg_base = orig.lg_base;
    lf_side = orig.lf_side;
    rt_side = orig.rt_side;
}

Trapezium::Trapezium(int sb, int lb, int ls, int rs) : sm_base(sb), lg_base(lb), lf_side(ls), rt_side(rs) {}

std::ostream& operator<<(std::ostream& os, const Trapezium& obj) {
    os << "Smaller base = " << sm_base << ", larger base = " << lg_base << ", left side = " <<  lf_side << ", right side = " << rt_side << ", Square = " << this->Square() << std::endl;
    return os;
}

std::istream& operator >>(std::istream &is, Trapezium &obj)
{
    std::cout << "Enter the sides of the Trapezium:" << std::endl;
    is >> sm_base >> lg_base >> lf_side >> rt_side;
    
    if(sm_base < 0 || lg_base < 0 || lf_side < 0 || rt_side < 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
    return is;
}

bool operator==(const Trapezium& obj) {
    return lf_side == obj.lf_side &&
           lg_base == obj.lg_base &&
           rt_side == obj.rt_side &&
           sm_base == obj.sm_base;
}

Trapezium Trapezium::operator =(const Trapezium &obj)
{
    if (&obj == this) {
        return *this;
    }

    sm_base = obj.sm_base;
    lg_base = obj.lg_base;
    lf_side = obj.lf_side;
    rt_side = obj.rt_side;

    return *this;
}

double Trapezium::Square() {
    double h = std::sqrt(lf_side * lf_side - 0.25 * std::pow((lf_side * lf_side - rt_side * rt_side)
        / (lg_base - sm_base) + lg_base - sm_base, 2.0));
    return (lg_base + sm_base) / 2 + h;
}

void Trapezium::Print() {
    std::cout << "Smaller base = " << sm_base << ", larger base = " << lg_base << ", left side = " <<  lf_side << ", right side = " << rt_side << std::endl;
}
