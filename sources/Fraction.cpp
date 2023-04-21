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

ariel::Fraction ariel::Fraction::operator+(float f) {
    return *this;
}

ariel::Fraction ariel::operator+(const ariel::Fraction &f1, float f) {
    return f1;
}

ariel::Fraction ariel::Fraction::operator-(const ariel::Fraction &other) const {
    return other;
}

ariel::Fraction ariel::Fraction::operator-(float f) {
    return *this;
}

ariel::Fraction ariel::operator-(const ariel::Fraction &f1, float f) {
    return f1;
}

ariel::Fraction ariel::Fraction::operator/(const ariel::Fraction &other) const {
    return other;
}

ariel::Fraction ariel::Fraction::operator/(float f) const {
    return *this;
}

ariel::Fraction ariel::operator/(const ariel::Fraction &f1, float f) {
    return f1;
}

ariel::Fraction ariel::Fraction::operator*(const ariel::Fraction &other) const {
    return other;
}

ariel::Fraction ariel::Fraction::operator*(float f) const {
    return *this;
}

ariel::Fraction ariel::operator*(float f, const ariel::Fraction &f1) {
    return f1;
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

bool ariel::Fraction::operator==(float f) const {
    return false;
}

bool ariel::operator==(float f, const ariel::Fraction &f1) {
    return false;
}

bool ariel::Fraction::operator>=(const ariel::Fraction &other) const {
    return false;
}

bool ariel::Fraction::operator>=(float f) const {
    return false;
}

bool ariel::operator>=(float f, const ariel::Fraction &f1) {
    return false;
}

bool ariel::Fraction::operator<=(const ariel::Fraction &other) const {
    return false;
}

bool ariel::Fraction::operator<=(float f) const {
    return false;
}

bool ariel::operator<=(float f, const ariel::Fraction &f1) {
    return false;
}

bool ariel::Fraction::operator>(const ariel::Fraction &other) const {
    return false;
}

bool ariel::Fraction::operator>(float f) const {
    return false;
}

bool ariel::operator>(float f, const ariel::Fraction &f1) {
    return false;
}

bool ariel::Fraction::operator<(const ariel::Fraction &other) const {
    return false;
}

bool ariel::Fraction::operator<(float f) const {
    return false;
}

bool ariel::operator<(float f, const ariel::Fraction &f1) {
    return false;
}

std::istream &ariel::operator>>(std::istream &inputs, ariel::Fraction &f1) {
    return inputs;
}

std::ostream &ariel::operator<<(std::ostream &outputs, const ariel::Fraction &f1) {
    return outputs;
}










