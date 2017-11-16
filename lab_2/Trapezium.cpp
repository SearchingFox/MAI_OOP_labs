#include <iostream>
#include <cmath>

#include "Trapezium.h"

Trapezium::Trapezium() : Trapezium(0, 0, 0, 0) {
}

Trapezium::Trapezium(size_t sb, size_t lb, size_t ls, size_t rs) : sm_base(sb), lg_base(lb), lf_side(ls), rt_side(rs) {
}

Trapezium::Trapezium(const Trapezium& orig) {   
    sm_base = orig.sm_base;
    lg_base = orig.lg_base;
    lf_side = orig.lf_side;
    rt_side = orig.rt_side;
}

Trapezium::Trapezium(std::istream &is) {
    is >> sm_base;
    is >> lg_base;
    is >> lf_side;
    is >> rt_side;
    
    if(sm_base < 0 || lg_base < 0 || lf_side < 0 || rt_side < 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
}

bool operator==(const Trapezium& fst, const Trapezium& snd) {
    if (fst.lf_side == snd.lf_side &&
        fst.lg_base == snd.lg_base &&
        fst.rt_side == snd.rt_side &&
        fst.sm_base == snd.sm_base) {
            return true;
    } else {
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Trapezium& obj) {
    os << "a=" << obj.sm_base << ", b=" << obj.lg_base << ", c=" << obj.rt_side << std::endl;
    return os;
}

double Trapezium::Square() {
    if (lg_base > sm_base) {
    return (double)(((sm_base + lg_base) / 2) * sqrt(lf_side * lf_side - 1 / 4 * 
            pow((lf_side * lf_side - rt_side * rt_side) / (lg_base - sm_base) + lg_base - sm_base, 2)));
    } else {
        std::cerr << "Error: bigger base < smaller base" << std::endl;
    }
    return 0.0;
}

void Trapezium::Print() {
    std::cout << "Smaller base = " << sm_base << ", larger base = " << lg_base << ", left side = " <<  lf_side << ", right side = " << rt_side << std::endl;
}

Trapezium::~Trapezium() {
}

