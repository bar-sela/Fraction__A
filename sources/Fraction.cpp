    #include "Fraction.hpp"
#include "iostream"
#include "algorithm"

Fraction operator+(Fraction x1, Fraction x2) {
  return Fraction(0,1);
}

Fraction Fraction::operator+(float x) {
     return Fraction(0,1);
}

Fraction operator-(Fraction& plus, Fraction& minus) {
  return Fraction(0,1);
}

Fraction Fraction::operator-(float x) {
     return Fraction(0,1);
}

Fraction operator-(float x, Fraction frac) {
     return Fraction(0,1);
}

Fraction operator*(Fraction &f1, Fraction &f2) {
 return Fraction(0,1);
}



Fraction operator*(float x,Fraction f) {
  return Fraction(0,1);
}

Fraction operator*(Fraction f, float x) {
     return Fraction(0,1);
}
/// divied
Fraction Fraction::operator/(Fraction &other) const {
  return Fraction(0,1);
}
Fraction operator/(float x, Fraction f ) {
 return Fraction(0,1);
}

Fraction operator/(Fraction f, float x ) {
    return Fraction(0,1);
}
/// < , <= , >= , >
bool Fraction::operator<(Fraction const &other) const {
    return false;
}
bool Fraction::operator>=(const Fraction &other) const {
   return true;
}

bool operator<(float x, const Fraction &f) {
   return true;
}

bool operator>=(float x,  const Fraction& f) {
    return true;
}

bool Fraction::operator<=(const Fraction &other) const {
   return true;
}

bool Fraction::operator>(const Fraction &other) const {
    return true;
}




bool operator>(float x, const Fraction& f) {
    return true;
}

bool operator<=(float x, const Fraction& f) {
    return true;
}
 /// important : when i compare in the tests float and Fraction :
 /// eventhough i dont have  bool operator==(float , const Fraction & f2) func , the compiler convert the float to
 /// Fraction by himself and then enter to this function !
 bool operator==(const Fraction &f1, const Fraction & f2) {
        return true;
}

Fraction& Fraction::operator++() {
      return *this;
}

Fraction Fraction::operator++(int) {
   return Fraction(0,0);
}

Fraction &Fraction::operator--() {
     return *this;
}

Fraction Fraction::operator--(int) {
    return Fraction(0,0);
}

ostream &operator<<(ostream &ostream, Fraction f) {
    return ostream;
}

void operator>>(istream &in, Fraction f) {
         
}





















