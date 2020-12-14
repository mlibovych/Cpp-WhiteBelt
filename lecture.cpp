#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Week {
    string value;
    explicit Week (const string& str) {
        value = str;
    }
};

struct Course {
    string value;
    explicit Course (const string& str) {
        value = str;
    }
};

struct Specialization {
    string value;
    explicit Specialization (const string& str) {
        value = str;
    }
};

struct LectureTitle {
  string specialization;
  string course;
  string week;
  LectureTitle (const Specialization& s, const Course& c, const Week& w) {
      specialization = s.value;
      course = c.value;
      week = w.value;
  }
};


// int main() {
//     LectureTitle title(
//         Specialization("C++"),
//         Course("White belt"),
//         Week("4th")
//     );
// }