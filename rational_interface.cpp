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

// int main() {
//     {
//         const Rational r(3, 10);
//         if (r.Numerator() != 3 || r.Denominator() != 10) {
//             cout << "Rational(3, 10) != 3/10" << endl;
//             return 1;
//         }
//     }

//     {
//         const Rational r(8, 12);
//         if (r.Numerator() != 2 || r.Denominator() != 3) {
//             cout << "Rational(8, 12) != 2/3" << endl;
//             return 2;
//         }
//     }

//     {
//         const Rational r(-4, 6);
//         if (r.Numerator() != -2 || r.Denominator() != 3) {
//             cout << "Rational(-4, 6) != -2/3" << endl;
//             return 3;
//         }
//     }

//     {
//         const Rational r(4, -6);
//         if (r.Numerator() != -2 || r.Denominator() != 3) {
//             cout << "Rational(4, -6) != -2/3" << endl;
//             return 3;
//         }
//     }

//     {
//         const Rational r(-2, -3);
//         if (r.Numerator() != 2 || r.Denominator() != 3) {
//             cout << "Rational(-2, -3) != 2/3" << endl;
//             return 4;
//         }
//     }

//     {
//         const Rational defaultConstructed;
//         if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
//             cout << "Rational() != 0/1" << endl;
//             return 5;
//         }
//     }

//     cout << "OK" << endl;
//     return 0;
// }

