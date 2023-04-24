//
// Created by beni on 4/20/23.
//
#include "Fraction.hpp"

ariel::Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::runtime_error("division by 0");
    }
    this->numerator_ = numerator;
    this->denominator_ = denominator;
    minimize();
}

ariel::Fraction::Fraction() {
    this->numerator_ = 0;
    this->denominator_ = 1;
}

//Help function
void ariel::Fraction::minimize() {
    int gcd_value = gcd(this->numerator_, this->denominator_);
    this->numerator_ /= gcd_value;
    this->denominator_ /= gcd_value;

}

//Help function(the greatest common divisor)
int ariel::Fraction::gcd(int numerator, int denominator) {
    while (denominator != 0) {
        int temp = denominator;
        denominator = numerator % denominator;
    }
    return numerator;
}


ariel::Fraction ariel::Fraction::operator+(const ariel::Fraction &other) const {
    return other;
}

ariel::Fraction ariel::Fraction::operator+(float flo) {
    return *this;
}

ariel::Fraction ariel::operator+(const ariel::Fraction &other, float flo) {
    return other;
}

ariel::Fraction ariel::Fraction::operator-(const ariel::Fraction &other) const {
    return other;
}

ariel::Fraction ariel::Fraction::operator-(float flo) {
    return *this;
}

ariel::Fraction ariel::operator-(const ariel::Fraction &other, float flo) {
    return other;
}

ariel::Fraction ariel::Fraction::operator/(const ariel::Fraction &other) const {
    return other;
}

ariel::Fraction ariel::Fraction::operator/(float flo) const {
    return *this;
}

ariel::Fraction ariel::operator/(const ariel::Fraction &other, float flo) {
    return other;
}

ariel::Fraction ariel::Fraction::operator*(const ariel::Fraction &other) const {
    return other;
}

ariel::Fraction ariel::Fraction::operator*(float flo) const {
    return *this;
}

ariel::Fraction ariel::operator*(float flo, const ariel::Fraction &other) {
    return other;
}

ariel::Fraction &ariel::Fraction::operator++() {
    return *this;
}

ariel::Fraction &ariel::Fraction::operator--() {
    return *this;
}

const ariel::Fraction ariel::Fraction::operator++(int) {
    return *this;
}

const ariel::Fraction ariel::Fraction::operator--(int) {
    return *this;
}

bool ariel::Fraction::operator==(const ariel::Fraction &other) const {
    return false;
}

bool ariel::Fraction::operator==(float flo) const {
    return false;
}

bool ariel::operator==(float flo, const ariel::Fraction &other) {
    return false;
}

bool ariel::Fraction::operator>=(const ariel::Fraction &other) const {
    return false;
}

bool ariel::Fraction::operator>=(float flo) const {
    return false;
}

bool ariel::operator>=(float flo, const ariel::Fraction &other) {
    return false;
}

bool ariel::Fraction::operator<=(const ariel::Fraction &other) const {
    return false;
}

bool ariel::Fraction::operator<=(float flo) const {
    return false;
}

bool ariel::operator<=(float flo, const ariel::Fraction &other) {
    return false;
}

bool ariel::Fraction::operator>(const ariel::Fraction &other) const {
    return false;
}

bool ariel::Fraction::operator>(float flo) const {
    return false;
}

bool ariel::operator>(float flo, const ariel::Fraction &other) {
    return false;
}

bool ariel::Fraction::operator<(const ariel::Fraction &other) const {
    return false;
}

bool ariel::Fraction::operator<(float flo) const {
    return false;
}

bool ariel::operator<(float flo, const ariel::Fraction &other) {
    return false;
}

std::istream &ariel::operator>>(std::istream &inputs, ariel::Fraction &other) {
    return inputs;
}

std::ostream &ariel::operator<<(std::ostream &outputs, const ariel::Fraction &other) {
    return outputs;
}










