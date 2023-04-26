//
// Created by beni on 4/20/23.
//
#include "Fraction.hpp"

using namespace ariel;

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

//Help function
void Fraction::minimize() {
    int gcd_value = gcd(this->numerator_, this->denominator_);
    this->numerator_ /= gcd_value;
    this->denominator_ /= gcd_value;

}

//Help function(the greatest common divisor)
int Fraction::gcd(int numerator, int denominator) {
    while (denominator != 0) {
        int temp = denominator;
        denominator = numerator % denominator;
    }
    return numerator;
}


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
    return *this;
}

Fraction operator+(const Fraction &other, float flo) {
    return other;
}

Fraction Fraction::operator-(const Fraction &other) const {
    return other;
}

Fraction Fraction::operator-(float flo) {
    return *this;
}

Fraction operator-(const Fraction &other, float flo) {
    return other;
}

Fraction Fraction::operator/(const Fraction &other) const {
    return other;
}

Fraction Fraction::operator/(float flo) const {
    return *this;
}

Fraction operator/(const Fraction &other, float flo) {
    return other;
}

Fraction Fraction::operator*(const Fraction &other) const {
    return other;
}

Fraction Fraction::operator*(float flo) const {
    return *this;
}

Fraction operator*(float flo, const Fraction &other) {
    return other;
}

Fraction &Fraction::operator++() {
    return *this;
}

Fraction &Fraction::operator--() {
    return *this;
}

const Fraction Fraction::operator++(int) {
    return *this;
}

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










