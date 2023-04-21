//
// Created by beni on 4/20/23.
//

#ifndef FRACTION_A_FRACTION_H
#define FRACTION_A_FRACTION_H

#endif //FRACTION_A_FRACTION_H
#pragma once

#include <iostream>
#include <cmath>

namespace ariel {
    class Fraction {
    private:
        int numerator_;
        int denominator_;

    public:
        Fraction();

        Fraction(int numerator, int denominator);

        // overload plus+ operator
        Fraction operator+(const Fraction &other) const;

        Fraction operator+(float f);

        friend Fraction operator+(const Fraction &f1, float f);

        // overload minus- operator
        Fraction operator-(const Fraction &other) const;

        Fraction operator-(float f);

        friend Fraction operator-(const Fraction &f1, float f);

        // overload div/ operator
        Fraction operator/(const Fraction &other) const;

        Fraction operator/(float f) const;

        friend Fraction operator/(const Fraction &f1, float f);

        // overload mul* operator
        Fraction operator*(const Fraction &other) const;

        Fraction operator*(float f) const;

        friend Fraction operator*(float f, const Fraction &f1);

        // overload ++operator and --operator (prefix)
        Fraction &operator++();

        Fraction &operator--();

        // overload operator++ and operator--(postfix)
        const ariel::Fraction operator++(int);

        const ariel::Fraction operator--(int);

        // overload operator ==
        bool operator==(const Fraction &other) const;

        bool operator==(float f) const;

        friend bool operator==(float f, const Fraction &f1);

        // overload operator >=
        bool operator>=(const Fraction &other) const;

        bool operator>=(float f) const;

        friend bool operator>=(float f, const Fraction &f1);

        // overload operator <=
        bool operator<=(const Fraction &other) const;

        bool operator<=(float f) const;

        friend bool operator<=(float f, const Fraction &f1);


        // overload operator >
        bool operator>(const Fraction &other) const;

        bool operator>(float f) const;

        friend bool operator>(float f, const Fraction &f1);

        // overload operator <
        bool operator<(const Fraction &other) const;

        bool operator<(float f) const;

        friend bool operator<(float f, const Fraction &f1);

        // overload operator >>
        friend std::istream &operator>>(std::istream &inputs, Fraction &f1);

        // overload operator <<
        friend std::ostream &operator<<(std::ostream &outputs, const Fraction &f1);
    };

}