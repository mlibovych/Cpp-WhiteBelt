#include <iostream>
#include <string>
#include <vector>
using namespace std;

void PrintVector(const vector<int>& v) {
    for (int i : v) {
        cout << i << ' ';
    }
    cout << endl;
}

void GetAvg(int& avg, const int& N, const vector<int>& v) {
    avg = 0;
    for (int i : v) {
        avg += i;
    }
    avg /= N;
}

void GetDays(int& count, const int& avg, const vector<int>& v1, vector<int>& v2) {
    int i = 0;

    count = 0;
    for (int s : v1) {
        if (s > avg) {
            count++;
            v2.push_back(i);
        }
        i++;
    }
    cout << count << endl;
}

int main () {
    int N, tmp, avg, count;
    vector<int> temperature, new_temperature;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        temperature.push_back(tmp);
    }
    GetAvg(avg, N, temperature);
    GetDays(count, avg, temperature, new_temperature);
    PrintVector(new_temperature);
    return 0;
}
