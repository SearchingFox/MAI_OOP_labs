#include "Trapezium.h"

Trapezium::Trapezium() : Trapezium(-1.0, -1.0, -1.0, -1.0) {}
Trapezium::Trapezium(const Trapezium &obj) {
  side_a = obj.side_a;
  side_b = obj.side_b;
  side_c = obj.side_c;
  side_d = obj.side_d;
}

Trapezium::Trapezium(double i, double j, double k, double l) {
  this->side_a = i;
  this->side_b = j;
  this->side_c = k;
  this->side_d = l;
}

Trapezium::Trapezium(std::istream &is) {
  is >> this->side_a;
  is >> this->side_b;
  is >> this->side_c;
  is >> this->side_d;
}

void Trapezium::setParams(std::istream &is) {
  is >> this->side_a;
  is >> this->side_b;
  is >> this->side_c;
  is >> this->side_d;
}

std::istream& operator >>(std::istream &is, Trapezium &obj)
{
    std::cout << "Enter the sides of the Trapezium:" << std::endl;
    is >> obj.side_a >> obj.side_b >> obj.side_c >> obj.side_d;
    
    if(obj.side_a < 0 || obj.side_b < 0 || obj.side_c < 0 || obj.side_d < 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
    return is;
}


void Trapezium::Print() {
  std::cout
            << "a = " << this->side_a
            << ", b = " << this->side_b 
            << ", c = " << this->side_c 
            << ", d = " << this->side_d
            << ", Square = " << this->getSquare() << std::endl;
}

bool Trapezium::operator==(const Trapezium& obj) const 
{
  return ((this->side_a == obj.side_a) && (this->side_b == obj.side_b)
          && (this->side_c == obj.side_c) && (this->side_d == obj.side_d));
}

Trapezium Trapezium::operator=(const Trapezium& obj) {
    if (this == &obj) return *this;

  side_a = obj.side_a;
  side_b = obj.side_b;
  side_c = obj.side_c;
  side_d = obj.side_d;
  
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Trapezium& obj) {
  if (obj == Trapezium())
    return os;
  
  os << "Length of trapezium is "
     << obj.side_a << " " << obj.side_b
     << " " << obj.side_c << " "
     << obj.side_d << std::endl;
  
  return os;
}


double Trapezium::getSquare() {
  double h = std::sqrt(this->side_c * this->side_c - 0.25 *
                        std::pow((this->side_c * this->side_c - this->side_d * this->side_d)
                                  /(this->side_b - this->side_a) + this->side_b - this->side_a
                                    , 2.0));
  return (this->side_a + this->side_b)/2 + h;
}