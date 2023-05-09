//
// Created by beni on 4/20/23.
//
#include <limits>
#include "Fraction.hpp"

namespace ariel {

//constructors
//- parameterized constructor
    Fraction::Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("division by 0");
        }
        this->numerator_ = numerator;
        this->denominator_ = denominator;
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        minimize();
    }

//- default constructor
    Fraction::Fraction() {
        this->numerator_ = 0;
        this->denominator_ = 1;
    }

//- conversion constructor
    Fraction::Fraction(float flo) {
        int number = (int) flo;
        int numerator = (int) (flo * 1000) - number * 1000;
        numerator += number * 1000;
        this->numerator_ = numerator;
        this->denominator_ = 1000;
        minimize();
    }

//- copy constructor
    Fraction::Fraction(const Fraction &other) {
        this->numerator_ = other.numerator_;
        this->denominator_ = other.denominator_;
    }

//- move constructor
    Fraction::Fraction(Fraction &&other) noexcept
            : numerator_(other.numerator_), denominator_(other.denominator_) {
        other.numerator_ = 0;
        other.denominator_ = 1;
    }

//- destructor
    Fraction::~Fraction() = default;


//Helper functions
    void Fraction::minimize() {
        // Calculate the GCD of the numerator and denominator using the gcd() function
        int gcd_value = gcd(abs(numerator_), (denominator_));

        // Divide both the numerator and denominator by the gcd_value
        numerator_ = numerator_ / gcd_value;
        denominator_ = denominator_ / gcd_value;
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
        long numerator_result = (static_cast<long>(this->numerator_ * other.denominator_)) +
                                (static_cast<long>(this->denominator_ * other.numerator_));
        //calculate the denominator(by Calculate the denominator of the sum)
        long denominator_result = ((this->denominator_ * other.denominator_));
        // Check for overflow
        if (numerator_result > std::numeric_limits<int>::max() ||
            numerator_result < std::numeric_limits<int>::min() ||
            denominator_result > std::numeric_limits<int>::max() ||
            denominator_result < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Addition operation resulted in an overflow");
        }
        //Create new fraction called sum
        Fraction sum(static_cast<int>(numerator_result), static_cast<int>(denominator_result));
        //Reduce the value of the fraction
        return sum;
    }

    Fraction Fraction::operator+(float flo) {
        Fraction floatFraction(flo);
        return (*this + floatFraction);
    }

    Fraction operator+(float flo, const Fraction &other) {
        Fraction floatFraction(flo);
        return (other + floatFraction);
    }

//- operator
    Fraction Fraction::operator-(const Fraction &other) const {
        // check if the fractions are equal
        bool equal = (this->numerator_ == other.numerator_) && (this->denominator_ == other.denominator_);
        // Calculate the numerator and denominator of the result
        long numerator_result = static_cast<long>(this->numerator_) * other.denominator_ -
                                static_cast<long>(this->denominator_) * other.numerator_;
        long denominator_result = (static_cast<long>(this->denominator_ * other.denominator_));
        // Check for overflow
        if (numerator_result > std::numeric_limits<int>::max() || numerator_result < std::numeric_limits<int>::min() ||
            denominator_result > std::numeric_limits<int>::max() ||
            denominator_result < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Subtraction operation resulted in an overflow");
        }
        Fraction res(static_cast<int>(numerator_result), static_cast<int>(denominator_result));
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

    Fraction operator-(float flo, const Fraction &other) {
        Fraction floatFraction(flo);
        return (floatFraction - other);
    }

// / operator
    Fraction Fraction::operator/(const Fraction &other) const {
        if (other.numerator_ == 0) {
            throw std::runtime_error("division by 0");
        }
        //Multiply the numerator of the first fraction by the denominator of the second fraction
        long numerator_result = static_cast<long>(this->numerator_) * other.denominator_;
        //Multiply the denominator of the first fraction by the numerator of the second fraction
        long denominator_result = static_cast<long>(this->denominator_) * other.numerator_;
        // Check for overflow
        if (numerator_result > std::numeric_limits<int>::max() ||
            numerator_result < std::numeric_limits<int>::min() ||
            denominator_result > std::numeric_limits<int>::max() ||
            denominator_result < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Division operation resulted in an overflow");
        }
        // create a new Fraction called res(to hold the result)
        Fraction res(static_cast<int>(numerator_result), static_cast<int>(denominator_result));
        return res;
    }

    Fraction Fraction::operator/(float flo) const {
        Fraction floatFraction(flo);
        return (*this / floatFraction);
    }

    Fraction operator/(float flo, const Fraction &other) {
        Fraction floatFraction(flo);
        return (floatFraction / other);
    }

// * operator
    Fraction Fraction::operator*(const Fraction &other) const {
        //Multiply the numerator of the first fraction by the numerator of the second fraction
        long numerator_result = (static_cast<long>(this->numerator_) * other.numerator_);
        //Multiply the denominator of the first fraction by the denominator of the second fraction
        long denominator_result = (static_cast<long>(this->denominator_) * other.denominator_);
        // Check for overflow
        if (numerator_result > std::numeric_limits<int>::max() ||
            numerator_result < std::numeric_limits<int>::min() ||
            denominator_result > std::numeric_limits<int>::max() ||
            denominator_result < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Multiplication operation resulted in an overflow");
        }
        // create a new Fraction called res(to hold the result)
        Fraction res(static_cast<int>(numerator_result), static_cast<int>(denominator_result));
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
        this->numerator_ += this->denominator_;
        minimize();
        //Return the original fraction before the increment
        return (*this);
    }

//-- operator (prefix)
    Fraction &Fraction::operator--() {
        //create a copy fraction using my copy constructor
        Fraction copyFraction(*this);
        this->numerator_ -= this->denominator_;
        minimize();
        // Return the original fraction before the decrement
        return (*this);
    }

// operator ++ (postfix)
    const Fraction Fraction::operator++(int) {
        //create a copy fraction using my copy constructor
        Fraction copyFraction(*this);
        this->numerator_ += this->denominator_;
        minimize();
        // Return the copy of the original fraction before the increment
        return copyFraction;
    }


// operator -- (postfix)
    const Fraction Fraction::operator--(int) {
        //create a copy fraction using my copy constructor
        Fraction copyFraction(*this);
        this->numerator_ -= this->denominator_;
        minimize();
        // Return the copy of the original fraction before the increment
        return copyFraction;
    }

//== operator
    bool Fraction::operator==(const Fraction &other) const {
        // Define the epsilon value for comparison
        float epsilon = 0.001;

        float difference = std::abs(static_cast<float>(this->numerator_) / static_cast<float> (this->denominator_) -
                                    static_cast<float>(other.numerator_) / static_cast<float>(other.denominator_));
        // Compare the calculated difference with the given tolerance (epsilon)
        // If the difference is less than epsilon, the fractions are considered equal
        return difference < epsilon;
    }

    bool Fraction::operator==(float flo) const {
        Fraction floatFraction(flo);
        return (*this == floatFraction);
    }

    bool operator==(float flo, const Fraction &other) {
        Fraction floatFraction(flo);
        return (other == floatFraction);
    }

// Move assignment operator
    Fraction &Fraction::operator=(Fraction &&other) noexcept {
        numerator_ = other.numerator_;
        denominator_ = other.denominator_;
        other.numerator_ = 0;
        other.denominator_ = 1;
        return *this;
    }

// Copy assignment operator
    Fraction &Fraction::operator=(const Fraction &other) {
        if (this != &other) {
            numerator_ = other.numerator_;
            denominator_ = other.denominator_;
        }
        return *this;
    }

//> operator
    bool Fraction::operator>(const Fraction &other) const {
        int l_fraction = this->numerator_ * other.denominator_;
        int r_fraction = other.numerator_ * this->denominator_;
        //By compare this cross-multiplied values we can determine whether the current fraction is greater than the other fraction.
        //if l_fraction > r_fraction the function return true otherwise false
        return (l_fraction > r_fraction);
    }

    bool Fraction::operator>(float flo) const {
        Fraction floatFraction(flo);
        return (*this > floatFraction);
    }

    bool operator>(float flo, const Fraction &other) {
        Fraction floatFraction(flo);
        return (floatFraction > other);
    }

//>= operator
    bool Fraction::operator>=(const Fraction &other) const {
        // Use the existing '>' operator to check if the current fraction is greater than the other fraction
        bool greater = (*this) > other;
        // Use the existing '==' operator to check if the current fraction is equal to the other fraction
        bool equal = (this->numerator_ * other.denominator_) == (other.numerator_ * this->denominator_);
        return (greater || equal);
    }

    bool Fraction::operator>=(float flo) const {
        Fraction floatFraction(flo);
        bool greater = (*this) > floatFraction;
        bool equal =
                (this->numerator_ * floatFraction.denominator_) == (floatFraction.numerator_ * this->denominator_);
        return (greater || equal);
    }

    bool operator>=(float flo, const Fraction &other) {
        Fraction floatFraction(flo);
        // Use the existing '>=' operator to check if the floatFraction is greater than or equal to the other fraction
        return (floatFraction >= other);
    }

//< operator
    bool Fraction::operator<(const Fraction &other) const {
        int l_fraction = this->numerator_ * other.denominator_;
        int r_fraction = other.numerator_ * this->denominator_;
        //By compare this cross-multiplied values we can determine whether the current fraction is smaller than the other fraction.
        //if l_fraction < r_fraction the function return true otherwise false
        return (l_fraction < r_fraction);
    }

    bool Fraction::operator<(float flo) const {
        Fraction floatFraction(flo);
        return (*this < floatFraction);
    }

    bool operator<(float flo, const Fraction &other) {
        Fraction floatFraction(flo);
        return (floatFraction < other);
    }

//<= operator
    bool Fraction::operator<=(const Fraction &other) const {
        // Use the existing '<' operator to check if the current fraction is smaller than the other fraction
        bool smaller = (*this) < other;
        // Use the existing '==' operator to check if the current fraction is equal to the other fraction
        bool equal = (this->numerator_ * other.denominator_) == (other.numerator_ * this->denominator_);
        return (smaller || equal);
    }

    bool Fraction::operator<=(float flo) const {
        Fraction floatFraction(flo);
        bool smaller = (*this) < floatFraction;
        bool equal =
                (this->numerator_ * floatFraction.denominator_) == (floatFraction.numerator_ * this->denominator_);
        return (smaller || equal);
    }

    bool operator<=(float flo, const Fraction &other) {
        Fraction floatFraction(flo);
        // Use the existing '<=' operator to check if the floatFraction is smaller than or equal to the other fraction
        return (floatFraction <= other);
    }


    std::istream &operator>>(std::istream &inputs, Fraction &other) {
        int numerator, denominator;
        // Read the numerator and denominator from the input stream.
        inputs >> numerator >> denominator;
        if (denominator == 0) {
            throw std::runtime_error("Invalid fraction input.");
        }
        if (inputs.fail()) {
            throw std::runtime_error("Not a valid input");
        }
        // If the denominator is negative, change the signs of both the numerator and denominator.
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        other = Fraction(numerator, denominator);
        return inputs;
    }

    std::ostream &operator<<(std::ostream &outputs, const Fraction &other) {
        Fraction temp(other);
        if (temp.denominator_ < 0) {
            temp.numerator_ = -temp.numerator_;
            temp.denominator_ = -temp.denominator_;
        }
        return outputs << temp.numerator_ << "/" << temp.denominator_;
    }


    int Fraction::getNumerator() const {
        return numerator_;
    }

    int Fraction::getDenominator() const {
        return denominator_;
    }


}








