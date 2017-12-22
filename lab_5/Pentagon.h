#ifndef PENTAGON_H
#define PENTAGON_H

#include <iostream>

#include "Figure.h"

class Pentagon : public Figure{
public:
    Pentagon();
    Pentagon(std::istream &is);
    Pentagon(int side);
    Pentagon(const Pentagon& orig);

    friend bool operator==(const Pentagon& fst, const Pentagon& snd);
    friend std::ostream& operator<<(std::ostream& os, const Pentagon& obj);
    friend std::istream& operator>>(std::istream& is, Pentagon& obj);
    Pentagon& operator=(const Pentagon& obj);
    
    double Square() override;
    void Print() override;
    
    virtual ~Pentagon();
private:
    int side;
};

#endif /*PENTAGON_H */

