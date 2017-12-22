#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <iostream>

#include "Figure.h"

class Rhombus : public Figure{
public:
    Rhombus();
    Rhombus(std::istream &is);
    Rhombus(int side, int angle);
    Rhombus(const Rhombus& orig);

    friend bool operator==(const Rhombus& fst, const Rhombus& snd);
    friend std::ostream& operator<<(std::ostream& os, const Rhombus& obj);
    friend std::istream& operator>>(std::istream& is, Rhombus& obj);
    Rhombus& operator=(const Rhombus& obj);
    
    double Square() override;
    void Print() override;
    
    virtual ~Rhombus();
private:
    int side;
    int angle;
};

#endif /*RHOMBUS_H */

