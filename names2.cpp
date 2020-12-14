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
    string GetFullNameWithHistory(int year) {
        string full_name, first_name, last_name;
        vector<string> first_names_history;
        vector<string> last_names_history;

        for (const auto& [key, value] : data) {
            if (key > year) {
                break;
            }
            else {
                if (value.count("first_name")) {
                    first_name = value.at("first_name");
                    if (first_names_history.empty()) {
                        first_names_history.push_back(first_name);
                    }
                    else if (first_names_history[first_names_history.size() - 1] != first_name) {
                        first_names_history.push_back(first_name);
                    }
                }
                if (value.count("last_name")) {
                    last_name = value.at("last_name");
                    if (last_names_history.empty()) {
                        last_names_history.push_back(last_name);
                    }
                    else if (last_names_history[last_names_history.size() - 1] != last_name) {
                        last_names_history.push_back(last_name);
                    }
                }
            }
        }
        if (last_names_history.size() > 1) {
            string history = " (";

            for (int i = last_names_history.size() - 2; i >= 0; i--) {
                if (i != last_names_history.size() - 2) {
                    history += ", ";
                }
                history += last_names_history[i];
            }
            history += ")";
            last_name += history;
        }
        if (first_names_history.size() > 1) {
            string history = " (";

            for (int i = first_names_history.size() - 2; i >= 0; i--) {
                if (i != first_names_history.size() - 2) {
                    history += ", ";
                }
                history += first_names_history[i];
            }
            history += ")";
            first_name += history;
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

