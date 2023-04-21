//
// Created by beni on 4/20/23.
//
#include "Fraction.hpp"

ariel::Fraction::Fraction(int numerator, int denominator) {
}

ariel::Fraction::Fraction() {
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










