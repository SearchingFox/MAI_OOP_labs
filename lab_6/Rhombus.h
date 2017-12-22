#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <iostream>

#include "Figure.h"

class Rhombus : public Figure{
public:
    Rhombus();
    Rhombus(std::istream &is);
    Rhombus(const Rhombus& orig);
    Rhombus(int side, int angle);

    friend std::ostream& operator<<(std::ostream& os, const Rhombus& obj);
    friend std::istream& operator>>(std::istream& is, Rhombus& obj);

    friend bool operator==(const Rhombus &obj) const;
    Rhombus& operator=(const Rhombus& obj);
    
    double Square() override;
    void Print() override;
    
    virtual ~Rhombus() {};
private:
    int side;
    int angle;
};

#endif /*RHOMBUS_H */
