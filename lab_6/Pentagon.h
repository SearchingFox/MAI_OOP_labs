#ifndef PENTAGON_H
#define PENTAGON_H

#include <iostream>

#include "Figure.h"

class Pentagon : public Figure{
public:
    Pentagon();
    Pentagon(std::istream &is);
    Pentagon(const Pentagon& orig);
    Pentagon(int side);

    friend std::ostream& operator<<(std::ostream& os, const Pentagon& obj);
    friend std::istream& operator>>(std::istream& is, Pentagon& obj);
    
    friend bool operator==(const Pentagon& obj) const;
    Pentagon& operator=(const Pentagon& obj);
    
    double Square() override;
    void Print() override;
    
    virtual ~Pentagon() {};
private:
    int side;
};

#endif /*PENTAGON_H */

