#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <stdexcept>
using namespace std;

class Rational {
int numerator, denominator;
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    };
    Rational(int new_numerator, int new_denominator) {
        if (new_denominator == 0) {
            throw invalid_argument("ff");
        }
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

ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << '/' << rational.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
    int a, b;

    if(stream) {
        stream >> a;
    }
    else {
        return stream;
    }
    stream.ignore(1);
    if(stream) {
        stream >> b;
        rational = Rational(a, b);
    }
    else {
        return stream;
    }
    return stream;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(),
                    lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("ff");
    }
    return Rational(lhs.Numerator() * rhs.Denominator(),
                    lhs.Denominator() * rhs.Numerator());
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

bool operator<(const Rational& lhs, const Rational& rhs) {
    int common = lcm(lhs.Denominator(), rhs.Denominator());
    int lpoint = common / lhs.Denominator();
    int rpoint = common / rhs.Denominator();

    if (lpoint * lhs.Numerator() < rpoint * rhs.Numerator())
        return 1;
    else
        return 0;
}

Rational ParseRational (const string &str) {
    int numerator, denominator;
    stringstream ss(str);

    ss >> numerator;
    if (ss.peek() != '/') {
        throw runtime_error("not /");
    }
    ss.ignore(1);
    ss >> denominator;
    return Rational(numerator, denominator);
}

void PrintRational(const Rational& rational) {
    cout << rational.Numerator() << "/" << rational.Denominator() << endl;
}

void DoOperation(const Rational& lhs, const Rational& rhs, string operation) {
    Rational result;

    if (operation == "+") {
        result = lhs + rhs;
    }
    else if (operation == "-") {
        result = lhs - rhs;
    }
    else if (operation == "/") {
        if (!rhs.Numerator()) {
            throw domain_error("zero");
        }
        result = lhs / rhs;
    }
    else if (operation == "*") {
        result = lhs * rhs;
    }
    PrintRational(result);
}

int main() {
    int numerator, denominator;
    string str, operation;
    Rational lhs, rhs;

    try {
        cin >> str;
        lhs = ParseRational(str);
        cin >> operation;
        cin >> str;
        rhs = ParseRational(str);
        try {
            DoOperation(lhs, rhs, operation);
        } catch (domain_error&){
            cout << "Division by zero" << endl;
        }
    } catch (invalid_argument&) {
        cout << "Invalid argument" << endl;
    }
    return 0;
}
