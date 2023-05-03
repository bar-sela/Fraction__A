#include "doctest.h"
#include "sources/Fraction.hpp"
#include "iostream"
#include <string>
#include <sstream>

TEST_CASE("constructors"){
    CHECK_THROWS(Fraction(5, 0));
    Fraction f =Fraction(0.0031);
   /// cheak that its rounding to 3 digits after the dot.
    CHECK(3 == f.getDenominator() );
    CHECK(1000 == f.getNumertator());
}

TEST_CASE("+ Fractions") {
    Fraction a(3, 5), b(2, 10);
    CHECK(4 == (a + b).getNumertator());
    CHECK(5 == (a + b).getDenominator());
}
TEST_CASE("REDUCED"){
    Fraction c(133, 12432), d(231343, 1920321);
    Fraction combine = c + d;
    int max = std::max(c.getDenominator(), c.getNumertator());
    int min = std::max(c.getDenominator(), c.getNumertator());
    /// it both denominator and numerator devied by the same bumber --> the fruction can be reduced more 
    bool isReduced = true;
    for (int i =1; i <= min; i++) {
        if (max % i == 0 && min % i == 0) {
            isReduced = false;
            break;
        }
    }
    CHECK(isReduced == true);
}
TEST_CASE("+ with Float") {
    Fraction a(1,3);
    float n =  0.2; 
    Fraction f = a + n; 
    CHECK(f.getDenominator() == 15 );
    CHECK(f.getNumertator()== 8);
}

TEST_CASE("+ with float") {
    Fraction a(3,8);Fraction b(1,4);
    Fraction f = a - b ; 
    CHECK(f.getDenominator() == 1 );
    CHECK(f.getNumertator()== 8);
}
TEST_CASE("- with Fraction") {
    Fraction a(1,3);
    float n =  0.2; 
    Fraction f = a + n; 
    CHECK(f.getDenominator() == 2 );
    CHECK(f.getNumertator()== 15);
}

TEST_CASE("- with float") {
    Fraction a(1,3);
    float n =  0.2; 
    Fraction f = a + n; 
  CHECK(((f.getNumertator() == 2) && (f.getDenominator() == 15)));

}
TEST_CASE("* Fraction") {
    Fraction a(3, 5), b(8, 10);
    Fraction c = a * b;
    CHECK(((c.getNumertator() == 12) && (c.getDenominator() == 25)));
}
TEST_CASE("* float") {
    Fraction a(3, 5);float fl = 0.8;
    Fraction c = a * fl;
    CHECK(((c.getNumertator() == 12) && (c.getDenominator() == 25)));
    Fraction a2(10, 2); 
    Fraction f = fl * a;
    CHECK(((f.getNumertator() == 4) && (f.getDenominator() == 1)));
}
TEST_CASE("/ Fraction") {
    Fraction a(1, 2), b(0, 8);
    CHECK_THROWS(a / b);
    Fraction d(9,10); 
    Fraction c = a / d ;
    CHECK(((c.getNumertator() == 5) && (c.getDenominator() == 9)));
}
TEST_CASE("/ Float") {
    Fraction a(9,10); 
    CHECK_THROWS(a / 0);
    float d  = 0.8;
    Fraction c = a / d ;
    CHECK(((c.getNumertator() == 5) && (c.getDenominator() == 9)));
    Fraction f = d /a ;
    CHECK(((f.getNumertator() == 8) && (f.getDenominator() == 9)));
}
TEST_CASE("<, <=, > , >= , ==with Fraction") {
    Fraction a(3, 10); Fraction b(6, 19);
    CHECK(a < b); CHECK( b<a);
     Fraction d(3, 10); Fraction c(6, 20);
    CHECK(d <= c);
    CHECK(d >= c);
    CHECK(d == c);
}
TEST_CASE("<, <=, > , >= with float") {
    Fraction a(3, 10); float f = 6/19 ;
    CHECK(a < f); CHECK( f<a);
     Fraction d(3, 10);  f = 6/20 ;
    CHECK(d <= f);
    CHECK(d >= f);
    CHECK(d == f);
}
TEST_CASE("Prefix ++ and -- ") {
    Fraction a(3, 5);  Fraction b = ++a;
    CHECK(a.getNumertator()== 8) ;
    CHECK(a.getDenominator() == 5);
    CHECK(b.getNumertator() == 8);
    CHECK(b.getDenominator() == 5);
    Fraction c(3, 5); 
    b = --c;
    CHECK(b.getNumertator()== 3) ;
    CHECK(b.getDenominator() == 5);
    CHECK(c.getNumertator() == 3);
    CHECK(c.getDenominator() == 5);
}
TEST_CASE("Postfix ++ and -- ") {
    Fraction a(3, 5);  Fraction b = a++;
    CHECK(a.getNumertator()== 8) ;
    CHECK(a.getDenominator() == 5);
    CHECK(b.getNumertator() == 3);
    CHECK(b.getDenominator() == 5);
    Fraction c(3, 5); 
    b = c--;
    CHECK(b.getNumertator()== 3) ;
    CHECK(b.getDenominator() == 5);
    CHECK(c.getNumertator() == -2);
    CHECK(c.getDenominator() == 5);
}
//out from Fraction
TEST_CASE("<<") {
    ostringstream o;
    Fraction a(3, 5);
    CHECK_NOTHROW(o << a);
    CHECK(o.str() == "3/5");
}
//into Fraction
TEST_CASE(">>") {
 Fraction b(8, 10);
 istringstream good("1 2"); // Could also be "5,6" for ex
 istringstream not_good_input("3");
 istringstream not_good_input2("3,4,5");
 istringstream not_good_input3("Eden Hazard, Leon Gorenzka");
 good >> b ;
 CHECK(((b.getNumertator() == 1) && (b.getDenominator() ==2)));
 CHECK_THROWS(not_good_input >> b);
 CHECK_THROWS(not_good_input2 >> b);
 CHECK_THROWS(not_good_input3 >> b);
}










