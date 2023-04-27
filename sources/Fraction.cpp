//
// Created by beni on 4/20/23.
//
#include "Fraction.hpp"

using namespace ariel;

//constructors
Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::runtime_error("division by 0");
    }
    this->numerator_ = numerator;
    this->denominator_ = denominator;
    minimize();
}

Fraction::Fraction() {
    this->numerator_ = 0;
    this->denominator_ = 1;
}

Fraction::Fraction(float flo) {
    int number = (int) flo;
    int numerator = (int) (flo * 1000) - number * 1000;
    numerator += number * 1000;
    this->numerator_ = numerator;
    this->denominator_ = 1000;
    minimize();
}

Fraction::Fraction(const Fraction &other) {
    this->numerator_ = other.numerator_;
    this->denominator_ = other.denominator_;
}

//Help function
void Fraction::minimize() {
    int gcd_value = gcd(this->numerator_, this->denominator_);
    this->numerator_ /= gcd_value;
    this->denominator_ /= gcd_value;

}

//Help function(greatest common divisor)
int Fraction::gcd(int numerator, int denominator) {
    while (denominator != 0) {
        int temp = denominator;
        denominator = numerator % denominator;
        numerator = temp;
    }
    return numerator;
}

//+ operator
Fraction Fraction::operator+(const Fraction &other) const {
    //calculate the numerator(by Calculate the numerator of the sum)
    int numerator_result = (this->numerator_ * other.denominator_) + (this->denominator_ * other.numerator_);
    //calculate the denominator(by Calculate the denominator of the sum)
    int denominator_result = (this->denominator_ * other.denominator_);
    //Create new fraction called sum
    Fraction sum(numerator_result, denominator_result);
    //Reduce the value of the fraction
    sum.minimize();
    return sum;
}

Fraction Fraction::operator+(float flo) {
    Fraction floatFraction(flo);
    return (*this + floatFraction);
}

Fraction operator+(const Fraction &other, float flo) {
    Fraction floatFraction(flo);
    return (other + floatFraction);
}

//- operator
Fraction Fraction::operator-(const Fraction &other) const {
    // check if the fractions are equal
    bool equal = (this->numerator_ == other.numerator_) && (this->denominator_ == other.denominator_);
    // calculate the numerator and denominator of the result
    int numerator_result = (this->numerator_ * other.denominator_) - (other.numerator_ * this->denominator_);
    int denominator_result = (this->denominator_ * other.denominator_);
    // create a new Fraction called res(to hold the result)
    Fraction res(numerator_result, denominator_result);
    res.minimize();
    // if the fractions are equal, the result should be 0
    if (equal) {
        res = Fraction(0, 1);
    }
    return res;
}

Fraction Fraction::operator-(float flo) {
    Fraction floatFraction(flo);
    return (*this - floatFraction);
}

Fraction operator-(const Fraction &other, float flo) {
    Fraction floatFraction(flo);
    return (other - floatFraction);
}

// / operator
Fraction Fraction::operator/(const Fraction &other) const {
    //Multiply the numerator of the first fraction by the denominator of the second fraction
    int numerator_result = (this->numerator_ * other.denominator_);
    //Multiply the denominator of the first fraction by the numerator of the second fraction
    int denominator_result = (this->denominator_ * other.numerator_);
    // create a new Fraction called res(to hold the result)
    Fraction res(numerator_result, denominator_result);
    res.minimize();
    return res;
}

Fraction Fraction::operator/(float flo) const {
    Fraction floatFraction(flo);
    return (*this / floatFraction);
}

Fraction operator/(const Fraction &other, float flo) {
    Fraction floatFraction(flo);
    return (other / floatFraction);
}

// * operator
Fraction Fraction::operator*(const Fraction &other) const {
    //Multiply the numerator of the first fraction by the numerator of the second fraction
    int numerator_result = (this->numerator_ * other.numerator_);
    //Multiply the denominator of the first fraction by the denominator of the second fraction
    int denominator_result = (this->denominator_ * other.denominator_);
    // create a new Fraction called res(to hold the result)
    Fraction res(numerator_result, denominator_result);
    res.minimize();
    return res;
}

Fraction Fraction::operator*(float flo) const {
    Fraction floatFraction(flo);
    return (*this * floatFraction);
}

Fraction operator*(float flo, const Fraction &other) {
    Fraction floatFraction(flo);
    return (other * floatFraction);
}

//  ++ operator (prefix)
Fraction &Fraction::operator++() {
    //create a copy fraction using my copy constructor
    Fraction copyFraction(*this);
   //
   this->numerator_+= this->denominator_;
   minimize();
   //Return the original fraction before the increment
    return (*this);
}

//-- operator (prefix)
Fraction &Fraction::operator--() {
    return *this;
}

// operator ++ (postfix)
const Fraction Fraction::operator++(int) {
    return *this;
}

// operator -- (postfix)
const Fraction Fraction::operator--(int) {
    return *this;
}

bool Fraction::operator==(const Fraction &other) const {
    return false;
}

bool Fraction::operator==(float flo) const {
    return false;
}

bool operator==(float flo, const Fraction &other) {
    return false;
}

bool Fraction::operator>=(const Fraction &other) const {
    return false;
}

bool Fraction::operator>=(float flo) const {
    return false;
}

bool operator>=(float flo, const Fraction &other) {
    return false;
}

bool Fraction::operator<=(const Fraction &other) const {
    return false;
}

bool Fraction::operator<=(float flo) const {
    return false;
}

bool operator<=(float flo, const Fraction &other) {
    return false;
}

bool Fraction::operator>(const Fraction &other) const {
    return false;
}

bool Fraction::operator>(float flo) const {
    return false;
}

bool operator>(float flo, const Fraction &other) {
    return false;
}

bool Fraction::operator<(const Fraction &other) const {
    return false;
}

bool Fraction::operator<(float flo) const {
    return false;
}

bool operator<(float flo, const Fraction &other) {
    return false;
}

std::istream &operator>>(std::istream &inputs, Fraction &other) {
    return inputs;
}

std::ostream &operator<<(std::ostream &outputs, const Fraction &other) {
    return outputs;
}










