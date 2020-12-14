#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <set>
#include <map>
using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    };
    Rational(int new_numerator, int new_denominator) {
        if (!new_numerator) {
            numerator = 0;
            denominator = 1;
        }
        else {
            int common = gcd(new_numerator, new_denominator);

            numerator = new_numerator / common;
            denominator = new_denominator / common;

            if (numerator < 0  ^ denominator < 0) {
                numerator = abs(numerator) * (-1);
                denominator = abs(denominator);
            }
            else {
                numerator = abs(numerator);
                denominator = abs(denominator);
            }
        }
    };

    int Numerator() const {
        return numerator;
    };
    int Denominator() const {
        return denominator;
    };
private:
int numerator, denominator;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    if (lhs.Numerator() == rhs.Numerator() &&
        lhs.Denominator() == rhs.Denominator()) {
        return 1;
    }
    else {
        return 0;
    }   
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    int common = lcm(lhs.Denominator(), rhs.Denominator());
    int lpoint = common / lhs.Denominator();
    int rpoint = common / rhs.Denominator();

    if (lpoint * lhs.Numerator() < rpoint * rhs.Numerator())
        return 1;
    else
        return 0;
}