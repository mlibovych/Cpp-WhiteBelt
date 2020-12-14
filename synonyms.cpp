#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
    int Q;
    map<string,set<string>> synonyms;

    for (cin >> Q; Q > 0; Q--) {
        string command;

        cin >> command;
        if (command == "ADD") {
            string word1, word2;

            cin >> word1 >> word2;
            synonyms[word1].insert(word2);
            synonyms[word2].insert(word1);
        }
        else if (command == "COUNT") {
            string word;
            set<string> w_synonyms;
            
            cin >> word;
            cout << synonyms[word].size() << endl;
        }
        else if (command == "CHECK") {
            string word1, word2;
            int flag;

            flag = 0;
            cin >> word1 >> word2;
            if (synonyms[word1].count(word2) || synonyms[word2].count(word1)) {
                flag++;
            }
            if (!flag) {
                cout << "NO";
            }
            else {
                cout << "YES";
            }
            cout << endl;
        }
    }

    return 0;
}


