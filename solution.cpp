#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <iterator>

#include <stdexcept>
using namespace std;

vector<string> SplitStringByChar(string str, char c) {
    vector<string> result;
    stringstream ss(str);
    string token;

    while (getline(ss, token, c)) {
        result.push_back(token);
    }
    return result;
}

class Date {
    int year, month, day;
public:
    Date (string str) {
        stringstream ss;
        istringstream input (str);

        if (!(input >> year)) {
            ss << "Wrong date format: " << str;
            throw runtime_error(ss.str());
        }
        if (input.peek() != '-') {
            ss << "Wrong date format: " << str;
            throw runtime_error(ss.str());
        }
        input.ignore(1);
        if (!(input >> month)) {
            ss << "Wrong date format: " << str;
            throw runtime_error(ss.str());
        }

        if (input.peek() != '-') {
            ss << "Wrong date format: " << str;
            throw runtime_error(ss.str());
        }
        input.ignore(1);
        if (!(input >> day)) {
            ss << "Wrong date format: " << str;
            throw runtime_error(ss.str());
        }
        if (input.peek() != EOF) {
            ss << "Wrong date format: " << str;
            throw runtime_error(ss.str());
        }
        if (month < 1 || month > 12) {
            ss << "Month value is invalid: " << month;
            throw runtime_error(ss.str());
        }
        if (day < 1 || day > 31) {
            ss << "Day value is invalid: " << day;
            throw runtime_error(ss.str());
        }
    }
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
};

bool operator<(const Date& lhs, const Date& rhs) {
    int ltime, rtime;

    ltime = lhs.GetYear() * 365 + lhs.GetMonth() * 31 + lhs.GetDay();
    rtime = rhs.GetYear() * 365 + rhs.GetMonth() * 31 + rhs.GetDay();
    return ltime < rtime;
}

class Database {
    map <Date, set<string>> events;
public:
    void AddEvent(const Date& date, const string& event) {
        events[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        if (events.count(date)) {
            if (events.at(date).count(event)) {
                events[date].erase(event);
                return 1;
            }
        }
        return 0;
    }
    int  DeleteDate(const Date& date) {
        int res = 0;

        if (events.count(date)) {
            res += events[date].size();
            events.erase(date);
        }
        return res;
    }
    void Find(const Date& date) const {
        if(events.count(date)) {
            for (const auto& event : events.at(date)) {
                cout << event << endl;
            }
        }
    }
    void Print() const {
        for (const auto& [key , value] : events) {
            for (const auto& event : value) {
                cout << setw(4) << setfill('0') << key.GetYear() 
                << '-' << setw(2) << setfill('0') << key.GetMonth() 
                << '-' << setw(2) << setfill('0') << key.GetDay() 
                << " " << event << endl;
            }
        }
    }
    map <Date, set<string>> GetData() const {
        return events;
    }
};

int main() {
    Database db;
    string command;

    while (getline(cin, command)) {
        vector<string> parts = SplitStringByChar(command, ' ');

        if (!parts.size()) {
            continue;
        }
        try {
            if (parts[0] == "Add") {
                string event = parts[2];
                Date date(parts[1]);

                db.AddEvent(date, event);
            }
            else if (parts[0] == "Del") {
                Date date(parts[1]);

                if (parts.size() == 3) {
                    string event = parts[2];

                    if (db.DeleteEvent(date, event)) {
                        cout << "Deleted successfully";
                    }
                    else {
                        cout << "Event not found";
                    }
                    cout << endl;
                }
                else {
                    cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
                }
            }
            else if (parts[0] == "Find") {
                Date date(parts[1]);

                db.Find(date);
            }
            else if (parts[0] == "Print") {
                db.Print();
            }
            else {
                cout << "Unknown command: " << parts[0] << endl;
                break;
            }
        } catch (exception& ex) {
            cout << ex.what() << endl;
            break;
        }

    }
    return 0;
}
