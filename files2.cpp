#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    const string path = "output.txt";
    ofstream output (path/*, ios::app*/);
    ifstream input("input.txt");
    string str;

    if (input.is_open()) {
        while (getline(input, str)){
            output << str << endl;
        }
    }
    return 0;
}
