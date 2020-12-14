#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main() {
    ifstream input("input.txt");
    string str;

    cout << fixed << setprecision(3);
    if (input.is_open()) {
        while (getline(input, str)){
            cout << stod(str) << endl;
        }
    }
    return 0;
}
