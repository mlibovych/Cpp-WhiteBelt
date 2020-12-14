#include <iostream>
#include <string>
#include <vector>
using namespace std;

void DoOperation(const string &operation, const int& k, vector<bool>& queue) {
    if (operation == "WORRY") {
        queue[k] = 1;
    }
    else if (operation == "QUIET") {
        queue[k] = 0;
    }
    else if (operation == "COME") {
        if (k > 0) {
            for (int i = 0; i < k; i++) {
                queue.push_back(0);
            }
        }
        else if (k < 0) {
            for (int i = k; i < 0; i++) {
                queue.pop_back();
            }
        }
    }
}

void GetWorried(const vector<bool>& queue) {
    int count;

    count = 0;
    for (int i : queue) {
        if (i) {
            count++;
        }
    }
    cout << count << endl;
}

int main() {
    int Q, k;
    string operation;
    vector<bool> queue;

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> operation;
        if (operation != "WORRY_COUNT") {
            cin >> k;
            DoOperation(operation, k, queue);
        }
        else {
            GetWorried(queue);
        }
    }
    return 0;
}
