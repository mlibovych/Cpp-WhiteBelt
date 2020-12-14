#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    ifstream input("input.txt");
    string str;

    if (input.is_open()) {
        while (getline(input, str)){
            cout << str << endl;
        }
    }
    return 0;
}
