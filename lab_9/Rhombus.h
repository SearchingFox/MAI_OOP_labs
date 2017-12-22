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

    bool operator==(const Rhombus &) const;
    Rhombus operator=(const Rhombus&);
    
    double getSquare() override;
    void Print() override;
    
    virtual ~Rhombus() {};
    int type() {return 1;}
private:
    int side;
    int angle;
};

#endif /*RHOMBUS_H */
