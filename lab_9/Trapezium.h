#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H
#include "Figure.h"

class Trapezium: public Figure {
 public:
  Trapezium();
  Trapezium(const Trapezium &obj);
  Trapezium(double i, double j, double k, double l);
  Trapezium(std::istream &is);
  void Print() override;
  double getSquare() override;
  void setParams(std::istream &is);
  bool operator==(const Trapezium&) const;
  Trapezium operator=(const Trapezium&);
  Trapezium operator++();
  friend std::istream& operator>>(std::istream &is, Trapezium &obj);
  friend std::ostream& operator<<(std::ostream&, const Trapezium&);
  ~Trapezium() {};
  int type() {return 2;}
 private:
  double side_a;
  double side_b;
  double side_c;
  double side_d;
};

#endif