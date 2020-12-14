#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

int main() {
    int N;
    vector<string> strings;

    for(cin >> N; N >0; N--) {
        string string;

        cin >> string;
        strings.push_back(string);
    }
    sort(strings.begin(), strings.end(), [](const auto &a, const auto &b) {
        return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), [](char c1, char c2) {
            return tolower(c1) < tolower(c2);
        });
    });
    for (const auto& item : strings) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}


