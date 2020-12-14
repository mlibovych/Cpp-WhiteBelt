#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    int Q;
    map<int, vector<string>> buses;

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int flag;
        int n_stops;
        vector<string> stops;

        flag = 0;
        cin >> n_stops;
        for (int j = 0; j < n_stops; j++) {
            string stop;

            cin >> stop;
            stops.push_back(stop);
        }
        for (const auto& [key, value] : buses) {
            if (value == stops) {
                cout << "Already exists for " << key << endl;
                flag++;
                break;
            }
        }
        if (!flag) {
            int size = buses.size() + 1;
            buses[size] = stops;
            cout << "New bus " << size << endl;
        }

    }

    return 0;
}



