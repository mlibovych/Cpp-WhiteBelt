#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Student {
    string first_name, last_name;
    int day, month, year;
};

int main() {
    int n, m, day, month, year, num;
    string first_name, last_name, command;
    Student student;
    vector<Student> students;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> first_name >> last_name >> day >> month >> year;
        students.push_back({first_name, last_name, day, month, year});
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> command >> num;
        if (num > students.size() || num <= 0) {
            cout << "bad request";
        }
        else {
            student = students[num - 1];
            if (command == "name" ) {
                cout << student.first_name << " " << student.last_name;
            }
            else if (command == "date") {
                cout << student.day << "." << student.month << "." << student.year;
            }
            else {
                cout << "bad request";
            }
        }
        cout << endl;
    }
  return 0;
}
