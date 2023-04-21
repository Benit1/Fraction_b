//
// Created by beni on 4/20/23.
//
#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Initialize two fractions and check results") {
    // Create two fractions
    ariel::Fraction f1(5, 6);
    ariel::Fraction f2(3, 4);
    CHECK((f1 + f2 == 1.5833));
    CHECK((f1 - f2 == 0.8333));
    CHECK((f1 * f2 == 0.625));
    CHECK((f1 / f2 == 1.1111));
    CHECK((f1++ == 0.8333));
    CHECK((++f2 == 1.75));
    CHECK((f1-- == 0.8333));
    CHECK((--f2 == 0.375));
    CHECK((f1 > f2));
    CHECK((f2 < f1));
}

TEST_CASE("Denominator cant be zero") {
    CHECK_THROWS(ariel::Fraction(4, 0));

}

TEST_CASE("== operator works correctly with float at left") {
    ariel::Fraction a(4, 1);
    CHECK((4.0 == a));
}

TEST_CASE("== operator works correctly with float at right") {
    ariel::Fraction a(4, 1);
    CHECK((a == 4.0));
}

TEST_CASE("Fraction cannot be divided by zero") {
    ariel::Fraction a(4, 1);
    ariel::Fraction b(0, 0);
    CHECK_THROWS(a / b);
    CHECK_THROWS(b / a);
    CHECK_THROWS_AS(a / ariel::Fraction(0, 1), std::invalid_argument);

}

TEST_CASE("Fraction addition and subtraction work correctly") {
    ariel::Fraction a(3, 4);
    ariel::Fraction b(1, 4);
    ariel::Fraction c(1, 3);
    CHECK(a + b == ariel::Fraction(1, 1));
    CHECK(a - b == c);
    CHECK(a + ariel::Fraction(0, 1) == a);
    CHECK(a + b + c == 1.3333);
}


