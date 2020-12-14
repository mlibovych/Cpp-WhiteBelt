#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

// int main() {
//     int N, M;
//     ifstream input("input.txt");
//     string str;

//     cout << fixed;
//     if (input.is_open()) {
//         getline(input, str, ' ');
//         N = stoi(str);
//         getline(input, str);
//         M = stoi(str);
//         for (int i = 0; i < N; i++) {
//             for (int j = 0; j < M; j++) {
//                 int a;
//                 if (j < M - 1) {
//                     getline(input, str, ',');
//                     cout << setw(10) << stoi(str) << " ";
//                 }
//                 else {
//                     getline(input, str);
//                     cout << setw(10) << stoi(str);
//                     if (i < N - 1) {
//                         cout << endl;
//                     }
//                 }
//             }
//         }
//     }
//     return 0;
// }

int main() {
    ifstream input("input.txt");
    int n, m;

    input >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;

            input >> x;
            input.ignore(1);
            cout << setw(10) << x;
            if (j != m - 1) {
                cout << " ";
            }
        }
        if (i != n - 1) {
            cout << endl;
        }
    }  
  return 0;
}