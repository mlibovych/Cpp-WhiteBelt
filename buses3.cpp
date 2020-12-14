#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int Q;
    map<set<string>, int> buses;
    
    for (cin >> Q; Q > 0; Q--) {
        int flag;
        int n_stops;
        set<string> stops;

        for (cin >> n_stops; n_stops > 0; n_stops--) {
            string stop;

            cin >> stop;
            stops.insert(stop);
        }
        if (buses.count(stops)) {
            cout << "Already exists for " << buses[stops] << endl;
        }
        else {
            int size = buses.size() + 1;

            buses[stops] = size;
            cout << "New bus " << size << endl;
        }
    }
    return 0;
}


