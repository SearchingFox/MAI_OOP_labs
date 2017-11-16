#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include <iostream>

#include "Figure.h"

class Trapezium : public Figure {
public:
    Trapezium();
    Trapezium(std::istream &is);
    Trapezium(const Trapezium& orig);
    Trapezium(size_t sm_base, size_t lg_base, size_t lf_side, size_t rt_side);
    
    friend bool operator==(const Trapezium& fst, const Trapezium& snd);
    friend std::ostream& operator<<(std::ostream& os, const Trapezium& obj);
    friend std::istream& operator>>(std::istream &is, Trapezium &obj);
    Trapezium& operator=(const Trapezium &obj);
    
    double Square() override;
    void Print() override;
    
    virtual ~Trapezium() {};
private:
    size_t sm_base;
    size_t lg_base;
    size_t lf_side;
    size_t rt_side;
};

#endif /*TRAPEZIUM_H */

