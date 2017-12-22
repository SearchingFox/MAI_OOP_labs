#ifndef PENTAGON_H
#define PENTAGON_H

//#include <iostream>

#include "Figure.h"

class Pentagon : public Figure{
public:
    Pentagon();
    Pentagon(std::istream &is);
    Pentagon(const Pentagon& orig);
    Pentagon(int side);

    friend std::ostream& operator<<(std::ostream& os, const Pentagon& obj);
    friend std::istream& operator>>(std::istream& is, Pentagon& obj);
    
    bool operator==(const Pentagon&) const;
    Pentagon operator=(const Pentagon&);
    
    double getSquare() override;
    void Print() override;
    
    virtual ~Pentagon() {};
    int type() {return 3;}
private:
    int side;
};

#endif /*PENTAGON_H */

