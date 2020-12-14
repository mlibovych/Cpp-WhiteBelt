#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int Q, day, month_number = 0;
    string operation, description;
    vector<int> n_days = {31, 28, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31};
    vector <vector<string>> current(n_days[month_number]);

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> operation;
        if (operation == "ADD") {
            cin >> day >> description;
            current[day - 1].push_back(description);
        }
        else if (operation == "DUMP") {
            cin >> day;
            cout << current[day - 1].size() << " ";
            for (const string& s : current[day - 1])
                cout << s << " ";
            cout << endl;
        }
        else if (operation == "NEXT") {
            if (month_number == 11)
                month_number = 0;
            else
                month_number++;
            vector <vector<string>> next;
            next.insert(end(next), begin(current), end(current));
            next.resize(n_days[month_number]);
            if (next.size() < current.size()) {
                for (int i = next.size(); i < current.size(); i++) {
                    for (const string& str : current[i])
                        next[next.size() - 1].push_back(str);
                }
            }
            current.clear();
            current = next;
        }
    }
    return 0;
}
