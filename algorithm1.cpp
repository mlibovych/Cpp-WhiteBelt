#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    int N;
    vector<int> nums;

    for(cin >> N; N >0; N--) {
        int number;

        cin >> number;
        nums.push_back(number);
    }
    sort(nums.begin(), nums.end(), [](const auto &a, const auto &b) {
        return pow(a , 2) < pow(b, 2);
    });
    for (const auto& item : nums) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}


