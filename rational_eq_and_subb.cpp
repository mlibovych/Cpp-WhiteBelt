#include <iostream>
#include <string>
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

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int common = lcm(lhs.Denominator(), rhs.Denominator());
    int lpoint = common / lhs.Denominator();
    int rpoint = common / rhs.Denominator();
    
    return Rational(lhs.Numerator() * lpoint + rhs.Numerator() * rpoint, common);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    int common = lcm(lhs.Denominator(), rhs.Denominator());
    int lpoint = common / lhs.Denominator();
    int rpoint = common / rhs.Denominator();
    
    return Rational(lhs.Numerator() * lpoint - rhs.Numerator() * rpoint, common);
}

// int main() {
//     {
//         Rational r1(4, 6);
//         Rational r2(2, 3);
//         bool equal = r1 == r2;
//         if (!equal) {
//             cout << "4/6 != 2/3" << endl;
//             return 1;
//         }
//     }

//     {
//         Rational a(2, 3);
//         Rational b(4, 3);
//         Rational c = a + b;
//         bool equal = c == Rational(2, 1);
//         if (!equal) {
//             cout << "2/3 + 4/3 != 2" << endl;
//             return 2;
//         }
//     }

//     {
//         Rational a(5, 7);
//         Rational b(2, 9);
//         Rational c = a - b;
//         bool equal = c == Rational(31, 63);
//         if (!equal) {
//             cout << "5/7 - 2/9 != 31/63" << endl;
//             return 3;
//         }
//     }

//     cout << "OK" << endl;
//     return 0;
// }