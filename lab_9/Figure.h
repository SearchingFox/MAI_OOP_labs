#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>

class Figure {
 public:
  virtual double getSquare() = 0;
  virtual void Print() = 0;
  virtual ~Figure() {};
  virtual int type() = 0;
};

#endif