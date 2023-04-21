//
// Created by beni on 4/20/23.
//
#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("initialize two fractions and check results") {
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

TEST_CASE("denominator cant be zero") {
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





