#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
    int Q;
    set<string> unique;

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        string str;

        cin >> str;
        unique.insert(str);
    }
    cout << unique.size() << endl;
    return 0;
}