#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include <iostream>

#include "Figure.h"

class Trapezium : public Figure {
public:
    Trapezium();
    Trapezium(std::istream &is);
    Trapezium(const Trapezium& orig);
    Trapezium(int sm_base, int lg_base, int lf_side, int rt_side);

    friend std::ostream& operator<<(std::ostream& os, const Trapezium& obj);
    friend std::istream& operator>>(std::istream &is, Trapezium &obj);
    
    friend bool operator==(const Trapezium& obj) const;
    Trapezium& operator=(const Trapezium &obj);
    
    double Square() override;
    void Print() override;
    
    virtual ~Trapezium() {};
private:
    int sm_base;
    int lg_base;
    int lf_side;
    int rt_side;
};

#endif /*TRAPEZIUM_H */
