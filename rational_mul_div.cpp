#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <numeric>
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

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(),
                    lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator(),
                    lhs.Denominator() * rhs.Numerator());
}


int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}