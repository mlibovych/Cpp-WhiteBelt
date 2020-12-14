#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        data[year]["first_name"] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        data[year]["last_name"] = last_name;
    }
    string GetFullName(int year) {
        string full_name, first_name, last_name;

        for (const auto& [key, value] : data) {
            if (key > year) {
                break;
            }
            else {
                if (value.count("first_name")) {
                    first_name = value.at("first_name");
                }
                if (value.count("last_name")) {
                    last_name = value.at("last_name");
                }
            }
        }
        if (!last_name.length() && !first_name.length()) {
            full_name =  "Incognito";
        }
        else if (!last_name.length()) {
            full_name = first_name + " with unknown last name";
        }
        else if (!first_name.length()) {
            full_name = last_name + " with unknown first name";
        }
        else {
            full_name = first_name + " " + last_name;
        }
        return full_name;
    }
private:
  map<int, map <string, string>> data;
};

// int main() {
//   Person person;
  
//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeLastName(1967, "Sergeeva");
//   for (int year : {1900, 1965, 1990}) {
//     cout << person.GetFullName(year) << endl;
//   }
  
//   person.ChangeFirstName(1970, "Appolinaria");
//   for (int year : {1969, 1970}) {
//     cout << person.GetFullName(year) << endl;
//   }
  
//   person.ChangeLastName(1968, "Volkova");
//   for (int year : {1969, 1970}) {
//     cout << person.GetFullName(year) << endl;
//   }
  
//   return 0;
// }
