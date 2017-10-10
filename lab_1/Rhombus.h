#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <iostream>

#include "Figure.h"

class Rhombus : public Figure{
public:
    Rhombus();
    Rhombus(std::istream &is);
    Rhombus(size_t side, size_t angle);
    Rhombus(const Rhombus& orig);
    
    double Square() override;
    void Print() override;
    
    virtual ~Rhombus();
private:
    size_t side;
    size_t angle;
};

#endif /*RHOMBUS_H */

