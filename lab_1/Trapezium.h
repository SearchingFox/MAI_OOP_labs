#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include <iostream>

#include "Figure.h"

class Trapezium : public Figure {
public:
    Trapezium();
    Trapezium(std::istream &is);
    Trapezium(size_t sm_base, size_t lg_base, size_t lf_side, size_t rt_side);
    Trapezium(const Trapezium& orig);
    
    double Square() override;
    void Print() override;
    
    virtual ~Trapezium();
private:
    size_t sm_base;
    size_t lg_base;
    size_t lf_side;
    size_t rt_side;
};

#endif /*TRAPEZIUM_H */

