//
// Created by Nachshon on 4/16/2023.
//
#include <iostream>

#include <iostream>
#include <cmath>



using namespace std;
#ifndef FRACTION_A_FRACTION_H
#define FRACTION_A_FRACTION_H

namespace ariel{} 

using namespace std;
class Fraction {

private:
    int numerator;
    int denominator;
public:
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    }

    //cout <<   << endl ;
    Fraction(float number) {

        number  = roundf(number * 1000) / 1000;  /// round to 3 strong digits
        this->numerator = number * 1000;
        this->denominator = 1000;
    }
    ///plus
    Fraction operator+(float x);
    friend Fraction operator+(Fraction x1, Fraction x2);
    /// minus
    friend Fraction operator-(Fraction& plus, Fraction& minus);
    Fraction operator-(float x);
    friend  Fraction operator-(float  x , Fraction frac);
    ///mul
    friend Fraction operator*(Fraction& f1, Fraction& f2);
    friend Fraction operator *(float , Fraction );
    friend Fraction operator *(Fraction , float );
   ///divide
    Fraction operator/(Fraction& other) const;
    friend Fraction operator /(float , Fraction );
    friend Fraction operator /(Fraction , float );
    /// < , <=  , > , >=
    ///<=
    bool operator <= (Fraction const & other) const;
    friend bool operator<=(float x , Fraction const& f);
    /// >
    bool operator > (Fraction const &other ) const;
    friend bool operator>(float x , Fraction const& f);
    /// <
    bool operator<(Fraction const &other) const;
    friend bool operator<(float x , Fraction const& f);
    /// >=
    friend bool operator>=(float x , Fraction const& f);
    bool operator >= (Fraction const& other) const;
    /// ==
    friend bool operator == (Fraction const&  f1, Fraction const& other) ;
    /// ++ --f
    Fraction& operator ++ ();
    Fraction& operator --();
    Fraction operator ++ (int);
    Fraction operator --(int);
    /// <<
    friend ostream& operator << (ostream& o , Fraction f);
    /// >>
    friend void operator >> (istream & o , Fraction f);

    int getDenominator() const {
        return this->denominator;
    }

    int getNumertator() const {
        return this->numerator;
    }


};
int __gcd(int a, int b);

#endif //FRACTION_A_FRACTION_H
