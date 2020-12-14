#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    int Q;
    string command;
    map<string, vector<string>> buses;
    vector<string> bus_id;

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> command;
        if (command == "ALL_BUSES") {
            if (buses.empty())
                cout << "No buses" << endl;
            else {
                for (const auto& [key, value] : buses) {
                    cout << "Bus " << key << ":";
                    for (const auto& s : value) {
                        cout << " " << s;
                    }
                    cout << endl;
                }
            }
        }
        else if (command == "NEW_BUS") {
            string bus;
            int stop_count;

            cin >> bus >> stop_count;
            bus_id.push_back(bus);
            for (int j = 0; j < stop_count; j++) {
                string stop;

                cin >> stop;
                buses[bus].push_back(stop);
            }
        }
        else if (command == "BUSES_FOR_STOP") {
            string stop;
            vector<string> buses_f_stop;
            int count;

            count = 0;
            cin >> stop;
            for (const auto& bus : bus_id) {
                for (int i = 0; i < buses[bus].size(); i++) {
                    if (buses[bus][i] == stop) {
                        count++;
                        buses_f_stop.push_back(bus);
                    }
                }
            }
            if (count == 0) {
                cout << "No stop";
            }
            else {
                for (int i = 0; i < buses_f_stop.size(); i++) {
                    cout << buses_f_stop[i];
                    if (i < buses_f_stop.size() - 1) {
                        cout << " ";
                    }
                }
            }
            cout << endl;
        }
        else if (command == "STOPS_FOR_BUS") {
            string bus;

            cin >> bus;
            if (!buses.count(bus)) {
                cout << "No bus" << endl;
            }
            else {
                for (const auto& stop : buses[bus]) {
                    vector<string> buses_f_stop1;

                    for (const auto& bus : bus_id) {
                        for (int i = 0; i < buses[bus].size(); i++) {
                            if (buses[bus][i] == stop) {
                                buses_f_stop1.push_back(bus);
                                break;
                            }
                        }
                    }
                    if (!buses_f_stop1.empty()) {
                        cout << "Stop " << stop << ":";
                        if (buses_f_stop1.size() == 1) {
                            cout << " no interchange";
                        }
                        else {
                            for (const auto& s : buses_f_stop1) {
                                if (s != bus)
                                    cout << " " << s;
                            }
                        }
                    }
                    cout << endl;
                }
            }
        }
    }

    return 0;
}



